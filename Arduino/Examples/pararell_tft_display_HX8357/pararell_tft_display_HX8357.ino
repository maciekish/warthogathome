#include "TFT_Setup.h"
#include <TFT_HX8357.h>
#include "CDU_Font.h"

#define DCSBIOS_IRQ_SERIAL
#include "DcsBios.h"

#define DEMO_ENABLED false

// Invoke library
TFT_HX8357 tft = TFT_HX8357();

#define text_height 21
#define text_width 18

// Offsets for slightly randomizing text position to prevent burn-in.
int x_offset = 0; // Max 4
int y_offset = 0; // Max 6

// Text lines to display
char* lines[] = {
  " WAYPT   F1  1    D5/B1 ",
  "              FROM:0    ",
  "\xB1""0           INIT POSIT""\xA1",
  "                    UNK ",
  "\xA1""EL:14992 ******** DTOT""\xA1",
  "                        ",
  "\xA1""N42""\xB0""17.661          ?6""\xA9",
  "            WND 272/003  ",
  "\xA1""E042""\xB0""12.054        L/L""\xAE",
  "[""\xB6""              ] P1/2  "
};

void setup() {
  // Slightly randomize position on every boot to avoid burn-in.
  randomSeed(analogRead(0));
  x_offset = random(4);
  y_offset = random(6);
  
  tft.begin();
  tft.setRotation(1);

  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_GREEN, TFT_BLACK);
  tft.setFreeFont(&CDU);
  tft.setTextSize(3);
  tft.setTextWrap(false);

  if (DEMO_ENABLED) {
    drawCDULine(0);
    drawCDULine(1);
    drawCDULine(2);
    drawCDULine(3);
    drawCDULine(4);
    drawCDULine(5);
    drawCDULine(6);
    drawCDULine(7);
    drawCDULine(8);
    drawCDULine(9);
  } else {
    setCDUText(4, "       * NO DATA *       ");
  }

  DcsBios::setup();
}

// int demo_toggle = 0;

void loop() {
  DcsBios::loop();
  
  /*if (demo_toggle == 0) {
    setCDUText(9, "[               ] P1/2  ");
    demo_toggle = 1;
  } else {
    setCDUText(9, "[""\xB6""              ] P1/2  ");
    demo_toggle = 0;
  }
  
  delay(900);*/
}

// Set and draw CDU Text
void setCDUText(int line, char* text) {
  lines[line] = text;
  drawCDULine(line);
}

// Draw CDU Text
void drawCDULine(int line) {
  // Draw by char to reduce flickering
  for (int i = 0; i < strlen(lines[line]); i++) {
    int x_pos = (x_offset + (i * text_width)) + i * 2;

    // Clear char
    tft.fillRect(x_pos, (y_coordinate_for_line(line) - text_height) + y_offset, text_width, text_height, TFT_BLACK);

    // Draw char
    tft.drawChar(x_pos, y_coordinate_for_line(line) + y_offset, lines[line][i], TFT_GREEN, TFT_BLACK, 3);
  }
}

int y_coordinate_for_line(int line) {
  return (32 * line) + 24;
}

void onCDULine0Change (char* newValue) {
  setCDUText(0, newValue);
}
DcsBios::StringBuffer<24> cduLine0Buffer(0x11c0, onCDULine0Change);

void onCDULine1Change (char* newValue) {
  setCDUText(1, newValue);
}
DcsBios::StringBuffer<24> cduLine1Buffer(0x11d8, onCDULine1Change);

void onCDULine2Change (char* newValue) {
  setCDUText(2, newValue);
}
DcsBios::StringBuffer<24> cduLine2Buffer(0x11f0, onCDULine2Change);

void onCDULine3Change (char* newValue) {
  setCDUText(3, newValue);
}
DcsBios::StringBuffer<24> cduLine3Buffer(0x1208, onCDULine3Change);

void onCDULine4Change (char* newValue) {
  setCDUText(4, newValue);
}
DcsBios::StringBuffer<24> cduLine4Buffer(0x1220, onCDULine4Change);

void onCDULine5Change (char* newValue) {
  setCDUText(5, newValue);
}
DcsBios::StringBuffer<24> cduLine5Buffer(0x1238, onCDULine5Change);

void onCDULine6Change (char* newValue) {
  setCDUText(6, newValue);
}
DcsBios::StringBuffer<24> cduLine6Buffer(0x1250, onCDULine6Change);

void onCDULine7Change (char* newValue) {
  setCDUText(7, newValue);
}
DcsBios::StringBuffer<24> cduLine7Buffer(0x1268, onCDULine7Change);

void onCDULine8Change (char* newValue) {
  setCDUText(8, newValue);
}
DcsBios::StringBuffer<24> cduLine8Buffer(0x1280, onCDULine8Change);

void onCDULine9Change (char* newValue) {
  setCDUText(9, newValue);
}
DcsBios::StringBuffer<24> cduLine9Buffer(0x1298, onCDULine9Change);
