#define DCSBIOS_RS485_SLAVE 9 // The following #define tells DCS-BIOS that this is a RS-485 slave device. It also sets the address of this slave device. The slave address should be between 1 and 126 and must be unique among all devices on the same bus.
#define TXENABLE_PIN 2 // The Arduino pin that is connected to the /RE and DE pins on the RS-485 transceiver.
//#define DCSBIOS_IRQ_SERIAL // For direct USB Testing. Only #define euther TXENABLE_PIN or DCSBIOS_IRQ_SERIAL, never both.

#include "DcsBios.h"

// Switches
DcsBios::Switch3Pos lcpPosition("LCP_POSITION", 4, 3);
DcsBios::Switch2Pos lcpAnticollision("LCP_ANTICOLLISION", 7);
DcsBios::Switch2Pos lcpNoseIllum("LCP_NOSE_ILLUM", 8);
DcsBios::Switch2Pos lcpSignalLights("LCP_SIGNAL_LIGHTS", 9);
DcsBios::Switch2Pos lcpAccelComp("LCP_ACCEL_COMP", 10);

DcsBios::Potentiometer lcpFormation("LCP_FORMATION", A0);
DcsBios::Potentiometer lcpEngInst("LCP_ENG_INST", A1);
DcsBios::Potentiometer lcpAuxInst("LCP_AUX_INST", A2);
DcsBios::Potentiometer lcpFlightInst("LCP_FLIGHT_INST", A3);
DcsBios::Potentiometer lcpFlood("LCP_FLOOD", A4);
DcsBios::Potentiometer lcpConsole("LCP_CONSOLE", A5);


// Backlight
void onInternalConsoleLightsChange(unsigned int newValue) {
    analogWrite(5, newValue / (256 * 6)); // Use 1/6 of max power, it gets very bright anyway.
}
DcsBios::IntegerBuffer internalConsoleLightsBuffer(0x1306, 0xffff, 0, onInternalConsoleLightsChange);

void setup() {
  DcsBios::setup();
}

void loop() {
  DcsBios::loop();
}
