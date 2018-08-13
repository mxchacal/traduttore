#include <Arduino.h>
#include <leds.h>

Leds::Leds() {
  pixels.begin();
  pixels.show();
}

void Leds::init() {}

void Leds::update() {}

void Leds::set(uint32_t color, int pixel) {
  pixels.setPixelColor(pixel, color);
}
