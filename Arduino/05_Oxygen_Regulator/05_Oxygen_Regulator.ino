#define DCSBIOS_RS485_SLAVE 5 // The following #define tells DCS-BIOS that this is a RS-485 slave device. It also sets the address of this slave device. The slave address should be between 1 and 126 and must be unique among all devices on the same bus.
#define TXENABLE_PIN 2 // The Arduino pin that is connected to the /RE and DE pins on the RS-485 transceiver.
//#define DCSBIOS_IRQ_SERIAL // For direct USB Testing. Only #define euther TXENABLE_PIN or DCSBIOS_IRQ_SERIAL, never both.

#include "DcsBios.h"

// Switches
/*DcsBios::Switch2Pos eppApuGenPwr("EPP_APU_GEN_PWR", 6);
DcsBios::Switch3Pos eppInverter("EPP_INVERTER", 8, 7);
DcsBios::Switch2Pos eppEmerFlood("EPP_EMER_FLOOD", 9);
DcsBios::Switch2Pos eppAcGenPwrL("EPP_AC_GEN_PWR_L", 10);
DcsBios::Switch2Pos eppAcGenPwrR("EPP_AC_GEN_PWR_R", 11);
DcsBios::Switch2Pos eppBatteryPwr("EPP_BATTERY_PWR", 12);*/

// Oxygen Flow Indicator
void onOxyFlowChange(unsigned int newValue) {
    digitalWrite(3, newValue);
}
DcsBios::IntegerBuffer oxyFlowBuffer(0x112a, 0x0800, 11, onOxyFlowChange);

// Backlight
void onInternalConsoleLightsChange(unsigned int newValue) {
    analogWrite(5, newValue / (256 * 4)); // Use 1/4 of max power, it gets very bright anyway.
}
DcsBios::IntegerBuffer internalConsoleLightsBuffer(0x1306, 0xffff, 0, onInternalConsoleLightsChange);

// AUX Light
void onInternalFltInstLightsChange(unsigned int newValue) {
    analogWrite(6, newValue / (256 * 4)); // Use 1/4 of max power, it gets very bright anyway.
}
DcsBios::IntegerBuffer internalFltInstLightsBuffer(0x130a, 0xffff, 0, onInternalFltInstLightsChange);

void setup() {
  pinMode(3, OUTPUT); // Oxygen Flow Indicator
  
  DcsBios::setup();
}

void loop() {
  DcsBios::loop();
}
