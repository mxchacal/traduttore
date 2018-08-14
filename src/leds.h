#ifndef LEDS_H
#define LEDS_H
#include <Adafruit_NeoPixel.h>

class Leds {
public:
  Leds();
  void init();
  void update();
  void set(uint32_t color, int pixel, int brightness);

private:
  Adafruit_NeoPixel pixels = Adafruit_NeoPixel(8, 6, NEO_GRB + NEO_KHZ800);
};

#endif
