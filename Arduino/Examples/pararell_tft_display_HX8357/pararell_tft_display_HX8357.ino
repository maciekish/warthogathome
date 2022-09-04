#include "TFT_Setup.h"
#include <TFT_HX8357.h>
#include "CDU_Font.h"

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
  "[               ] P1/2  "
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

  drawCDULine(1);
  drawCDULine(2);
  drawCDULine(3);
  drawCDULine(4);
  drawCDULine(5);
  drawCDULine(6);
  drawCDULine(7);
  drawCDULine(8);
  drawCDULine(9);
  drawCDULine(10);
}

int toggle = 0;

void loop() {
  if (toggle == 0) {
    setCDUText(10, "[               ] P1/2  ");
    toggle = 1;
  } else {
    setCDUText(10, "[""\xB6""              ] P1/2  ");
    toggle = 0;
  }
  
  delay(900);
}

// Set and draw CDU Text
void setCDUText(int line, char* text) {
  lines[line - 1] = text;
  drawCDULine(line);
}

// Draw existing CDU Text
void drawCDULine(int line) {
  // Draw by char to reduce flickering
  for (int i = 0; i < strlen(lines[line-1]); i++) {
    int x_pos = (x_offset + (i * text_width)) + i * 2;

    // Clear char
    tft.fillRect(x_pos, (y_coordinate_for_line(line) - text_height) + y_offset, text_width, text_height, TFT_BLACK);

    // Draw char
    tft.drawChar(x_pos, y_coordinate_for_line(line) + y_offset, lines[line - 1][i], TFT_GREEN, TFT_BLACK, 3);
  }
}

int y_coordinate_for_line(int line) {
  return (32 * line) - 8;
}
