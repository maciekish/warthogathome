// This is an example of 4-wire SPI communication with a 256x64 pixel OLED as used in the CMSP.

#include <Arduino.h>
#include <U8g2lib.h>

#define DCSBIOS_IRQ_SERIAL
#include "DcsBios.h"

#define U8G2_16BIT
// U8G2_SSD1322_NHD_256X64_F_4W_SW_SPI u8g2(U8G2_R0, /* clock=*/ 13, /* data=*/ 11, /* cs=*/ 10, /* dc=*/ 9, /* reset=*/ 8); // Software SPI with full FB on Arduino Mega.
// U8G2_SSD1322_NHD_256X64_2_4W_HW_SPI u8g2(U8G2_R0, /* cs=*/ 10, /* dc=*/ 9, /* reset=*/ 8); // Hardware SPI on Arduino Nano.
U8G2_SSD1322_NHD_256X64_F_4W_HW_SPI u8g2(U8G2_R0, /* cs=*/ 53, /* dc=*/ 49, /* reset=*/ 48); // Hardware SPI on Arduino Mega.

// Offsets for slightly randomizing text position.
int x_offset = 0;
int y_offset = 0;

// The 2 lines of text to display
char* cmsp1 = "--- --- --- ---    "; // 002 000 1.00 01
char* cmsp2 = "---- ---- ---- ----"; // CHAF FLAR INTV CYCL
/*char* cmsp1 = "002 000 1.00 01    ";
char* cmsp2 = "CHAF FLAR INTV CYCL";*/

unsigned int contrast = 8;

#include "CMSP_Large_font.h"
#include "CMSP_Small_font.h"

void setup() {
  // Slightly randomize position on every boot to avoid burning out the exact same pixels. Afterall, OLEDs are "consumable".
  randomSeed(analogRead(0));
  // x_offset = random(0); // X randomization disabled, doesn't fit.
  y_offset = random(8);
  
  u8g2.begin();
  u8g2.setContrast(contrast); // Start with lowest brightness in case panel is plugged in and forgotten.
  DcsBios::setup();
}

void loop() {
  DcsBios::loop();
  u8g2.clearBuffer();
  
  if (contrast > 7) { // My OLED cannot dim a lot, so if brightness is low, just blank the display.
    // Set the font and draw the top line
    u8g2.setFont(CMSP_Large_font); // Alternative fonts: u8g2_font_profont29_tf, u8g2_font_inb19_mf
    u8g2.drawStr(0 + x_offset, 16 + y_offset, cmsp1);

    // Split the second line in two be cause the display is 2 pixels too narrow to fit the string properly.
    char left[9];
    strncpy(left, cmsp2, 10);
    char right[10];
    sprintf(right, "%s", cmsp2+10);

    // Set the font and draw the bottom line in 2 parts
    u8g2.setFont(CMSP_Small_font);
    u8g2.drawStr(0 + x_offset, 42 + y_offset, left);
    u8g2.drawStr(126 + x_offset, 42 + y_offset, right);
  }

  u8g2.sendBuffer();
}

// Update text line 1
void onCmsp1Change(char* newValue) {
    cmsp1 = newValue;
}
DcsBios::StringBuffer<19> cmsp1Buffer(0x1000, onCmsp1Change);

// Update text line 2
void onCmsp2Change(char* newValue) {
    cmsp2 = newValue;
}
DcsBios::StringBuffer<19> cmsp2Buffer(0x1014, onCmsp2Change);

// Update brightness
void onCmspBrtChange(unsigned int newValue) {
    contrast = newValue / 256.0;
    u8g2.setContrast(contrast);
}
DcsBios::IntegerBuffer cmspBrtBuffer(0x10e6, 0xffff, 0, onCmspBrtChange);
