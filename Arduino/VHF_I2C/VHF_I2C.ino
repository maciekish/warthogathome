// Arduino Connections
// Display -> Arduino Nano
// SDA -> A4
// SCK -> A5
// VCC -> 5V
// GND -> GND

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <TM1638plus.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library. 
// On an arduino UNO:       A4(SDA), A5(SCL)
// On an arduino MEGA 2560: 20(SDA), 21(SCL)
// On an arduino LEONARDO:   2(SDA),  3(SCL), ...
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// TM1638
#define  STROBE_TM 4 // strobe = GPIO connected to strobe line of module
#define  CLOCK_TM 6  // clock = GPIO connected to clock line of module
#define  DIO_TM 7 // data = GPIO connected to data line of module
bool high_freq = false; //default false,, If using a high freq CPU > ~100 MHZ set to true. 

TM1638plus tm(STROBE_TM, CLOCK_TM , DIO_TM, high_freq);

#define DCSBIOS_IRQ_SERIAL
#include "DcsBios.h"

void setup() {
  DcsBios::setup();

  tm.displayBegin();
  tm.displayASCIIwDot(0, '2');
  tm.displayASCII(1, '3');
  tm.displayASCII(2, '4');
  tm.displayASCII(3, '1');
  
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    for(;;); // Don't proceed, loop forever
  }

  display.clearDisplay();

  display.setCursor(0,8);             // Start at top-left corner
  display.setTextSize(3);             // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
  display.println(F("--- ---"));

  display.display();
}

void onVhfAmFrequencySChange(char* newValue) {
  display.clearDisplay();

  display.setCursor(0,8);
  display.setTextSize(3);
  display.setTextColor(SSD1306_WHITE);

  if (newValue[6] == 0x20) {
    display.print(" ");
  }
  display.println(newValue);

  display.display();
}
DcsBios::StringBuffer<7> vhfAmFrequencySBuffer(0x12de, onVhfAmFrequencySChange);

void loop() {
  DcsBios::loop();
}

int htoi (char c) {  //does not check that input is valid
    if (c<='9')
        return c-'0';
    if (c<='F')
        return c-'A'+10;
    if (c<='f')
        return c-'a'+10;
    return 0;
}
