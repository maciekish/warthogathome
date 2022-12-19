#define DCSBIOS_RS485_SLAVE 5 // The following #define tells DCS-BIOS that this is a RS-485 slave device. It also sets the address of this slave device. The slave address should be between 1 and 126 and must be unique among all devices on the same bus.
#define TXENABLE_PIN 2 // The Arduino pin that is connected to the /RE and DE pins on the RS-485 transceiver.
//#define DCSBIOS_IRQ_SERIAL // For direct USB Testing. Only #define euther TXENABLE_PIN or DCSBIOS_IRQ_SERIAL, never both.

#include "DcsBios.h"
#include <Servo.h>

// Switches
DcsBios::Switch2Pos oxyDiluter("OXY_DILUTER", 10);
DcsBios::Switch3Pos oxyEmergency("OXY_EMERGENCY", 8, 7);
DcsBios::Switch2Pos oxySupply("OXY_SUPPLY", 11);

// Oxygen Pressure Servo
Servo oxyPressure;

void onOxySupplyChange(unsigned int newValue) {
  int val = map(newValue, 0, 32684, 180, 0);
  oxyPressure.write(val);
}
DcsBios::IntegerBuffer oxySupplyBuffer(0x112a, 0x0400, 10, onOxySupplyChange);

// Oxygen Flow Indicator
unsigned int internalFltInstLights = 255;

void onOxyFlowChange(unsigned int newValue) {
    // analogWrite(3, newValue * (internalFltInstLights / 256)); // Controlled by FLT INST
    analogWrite(3, newValue * 128); // Controlled by FLT INST
}
DcsBios::IntegerBuffer oxyFlowBuffer(0x112a, 0x0800, 11, onOxyFlowChange);

// Backlight
void onInternalConsoleLightsChange(unsigned int newValue) {
    analogWrite(5, newValue / (256 * 6)); // Use 1/6 of max power, it gets very bright anyway.
}
DcsBios::IntegerBuffer internalConsoleLightsBuffer(0x1306, 0xffff, 0, onInternalConsoleLightsChange);

// AUX Light
void onInternalFltInstLightsChange(unsigned int newValue) {
    internalFltInstLights = newValue;
    analogWrite(6, newValue / (256 * 4)); // Use 1/4 of max power, it gets very bright anyway.
}
DcsBios::IntegerBuffer internalFltInstLightsBuffer(0x130a, 0xffff, 0, onInternalFltInstLightsChange);

void setup() {
  pinMode(3, OUTPUT); // Oxygen Flow Indicator
  oxyPressure.attach(9); // Oxygen Pressure Servo
  
  DcsBios::setup();
}

void loop() {
  DcsBios::loop();
}
