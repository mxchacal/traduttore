#include <Arduino.h>
#include <mcp4728.h>
#include <ShiftRegister74HC595.h>
#include <MIDI.h>
#include <leds.h>

mcp4728 dac_0 = mcp4728(0); // instantiate mcp4728 object, Device ID = 0
mcp4728 dac_1 = mcp4728(1);

ShiftRegister74HC595 gate_out(2, 0, 1, 2);
Leds leds;

uint32_t color[12];

MIDI_CREATE_DEFAULT_INSTANCE();

void noteOn(byte channel, byte note, byte velocity);
void noteOff(byte channel, byte note, byte velocity);
void cc(byte channel, byte number, byte value);

void setup() {
  Serial.begin(9600);

  MIDI.begin(MIDI_CHANNEL_OMNI);
  MIDI.setHandleNoteOn(noteOn);
  MIDI.setHandleNoteOff(noteOff);
  MIDI.setHandleControlChange(cc);

  gate_out.setAllLow();
  dac_0.begin();
  dac_1.begin();

  leds.init();
}

void loop() {
  MIDI.read();
  leds.update();
}

void noteOn(byte channel, byte note, byte velocity) {
  if(channel <= 3) dac_0.analogWrite(channel, note); // cv
  if(channel >= 4) dac_1.analogWrite(channel, note);
  gate_out.set(channel, HIGH);                       // gate
  leds.set(channel, color[note]);                    // ui
}

void noteOff(byte channel, byte note, byte velocity) {
 gate_out.set(channel, LOW);
 leds.set(channel, color[note]);
}

void cc(byte channel, byte number, byte value) {
//  dac_x.write(command, channel)
}
