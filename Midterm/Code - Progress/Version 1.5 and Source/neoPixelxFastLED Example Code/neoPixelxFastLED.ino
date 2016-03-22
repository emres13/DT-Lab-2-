#include "FastLED.h"

#define NUM_LEDS 24
#define NUM_STRIPS 2

CRGB leds[NUM_LEDS];
CLEDController *controllers[NUM_STRIPS];
uint8_t gBrightness = 255;

void setup() {

  controllers[0] = &FastLED.addLeds<WS2812, 10>(leds, NUM_LEDS);
  controllers[1] = &FastLED.addLeds<WS2812, 11>(leds, NUM_LEDS);

}

void loop() {
  
  fill_solid(leds, NUM_LEDS, CRGB::LemonChiffon);
  controllers[0]->showLeds(gBrightness);

  // draw led data for the second strand into leds
  fill_solid(leds, NUM_LEDS, CRGB::DeepSkyBlue);
  controllers[1]->showLeds(gBrightness);

}

