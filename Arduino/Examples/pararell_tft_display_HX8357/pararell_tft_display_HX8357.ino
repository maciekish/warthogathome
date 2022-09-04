#include "TFT_Setup.h"
#include <TFT_HX8357.h>
#include "CDU_Font.h"

// Invoke library
TFT_HX8357 tft = TFT_HX8357();

#define text_height 21

// Offsets for slightly randomizing text position to prevent burn-in.
int x_offset = 13; // Max 27
int y_offset = 0; // Max 6

// Text lines to display
char* lines[] = {
  " WAYPT         0   D5/B1 ",
  "                         ",
  "±1      SP    INIT POSIT¡",
  "                    UNK  ",
  "EL:23      ******** DTOT¡",
  " NO CR                   ",
  "¡N34°35.367           ?1©",
  "             WND ***/*** ",
  "¡E036°00.680         L/L®",
  "[¶              ]   P1/2 "
};

void setup() {
  // Slightly randomize position on every boot to avoid burn-in.
  randomSeed(analogRead(0));
  x_offset = random(15) + 6; // Range 6-21
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
    setCDUText(10, "[               ]   P1/2 ");
    toggle = 1;
  } else {
    setCDUText(10, "[¶              ]   P1/2 ");
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
  tft.fillRect(x_offset, (y_coordinate_for_line(line) - text_height) + y_offset, 462 - x_offset, text_height, TFT_BLACK);
  tft.setCursor(x_offset, y_coordinate_for_line(line) + y_offset);
  tft.print(lines[line - 1]);
  //tft.drawString(lines[line - 1], x_offset, y_coordinate_for_line(line) + y_offset, 1);
}

int y_coordinate_for_line(int line) {
  return (32 * line) - 8;
}
