// This is an example of 4-wire SPI communication with a 256x64 pixel OLED as used in the CMSP.

#include <Arduino.h>
#include <U8g2lib.h>

#define DCSBIOS_IRQ_SERIAL
#include "DcsBios.h"

#define U8G2_16BIT
U8G2_SSD1322_NHD_256X64_F_4W_SW_SPI u8g2(U8G2_R0, /* clock=*/ 13, /* data=*/ 11, /* cs=*/ 10, /* dc=*/ 9, /* reset=*/ 8);

// Offsets for slightly randomizing text position.
int x_offset = 0;
int y_offset = 0;

// The 2 lines of text to display
char* cmsp1 = "XXXXXXXXXXXXXXXXXXX";
char* cmsp2 = "XXXXXXXXXXXXXXXXXXX";

unsigned int contrast = 1;

void setup() {
  // Slightly randomize position on every boot to avoid burning out the exact same pixels. Afterall, OLEDs are "a consumable" :(
  randomSeed(analogRead(0));
  x_offset = random(3);
  y_offset = random(3);
  
  u8g2.begin();
  u8g2.setContrast(1); // Start with lowest brightness in case panel is plugged in and forgotten.
  DcsBios::setup();
}

void loop() {
  DcsBios::loop();

  if (contrast > 0) { // My OLED cannot dim a lot, so if brightness is 0, just blank the display.
    u8g2.firstPage();
    do {
      u8g2.setFont(u8g2_font_chargen_92_te); // Alternative fonts: u8g2_font_profont29_tf, u8g2_font_inb19_mf
      u8g2.drawStr(0 + x_offset, 24 + y_offset, cmsp1);
      u8g2.setFont(u8g2_font_chargen_92_te);
      u8g2.drawStr(0 + x_offset, 48 + y_offset, cmsp2);
    } while ( u8g2.nextPage() );
  } else {
    u8g2.clearDisplay();
  }
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
    u8g2.setContrast(newValue / 256.0);
    contrast = newValue;
}
DcsBios::IntegerBuffer cmspBrtBuffer(0x10e6, 0xffff, 0, onCmspBrtChange);
