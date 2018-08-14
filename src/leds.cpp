#include <Arduino.h>
#include <leds.h>

Leds::Leds() {
  pixels.begin();
  pixels.show();
}

void Leds::init() {
  //Do some fancy things
}

void Leds::update() {
  pixels.show();
}

void Leds::set(uint32_t color, int pixel, int brightness) {
  pixels.setPixelColor(pixel, color);
  pixels.setBrightness(brightness);
}
