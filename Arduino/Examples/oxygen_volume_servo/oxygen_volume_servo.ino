#define DCSBIOS_IRQ_SERIAL

#include "DcsBios.h"
#include <Servo.h>

Servo oxyVolume;

void onOxyVolumeChange(unsigned int newValue) {
  int val = map(newValue, 0, 32684, 180, 0);
  oxyVolume.write(val);
}
DcsBios::IntegerBuffer oxyVolumeBuffer(0x1132, 0xffff, 0, onOxyVolumeChange);

void setup() {
  oxyVolume.attach(9);
  DcsBios::setup();
}

void loop() {
  DcsBios::loop();
}
