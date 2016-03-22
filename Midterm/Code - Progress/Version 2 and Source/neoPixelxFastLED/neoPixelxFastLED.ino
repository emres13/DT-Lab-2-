#include "FastLED.h"

#define i 24
#define NUM_STRIPS 2

CRGB leds[i];
CLEDController *controllers[NUM_STRIPS];
uint8_t gBrightness = 255;

void setup() {

  controllers[0] = &FastLED.addLeds<WS2812, 10>(leds, i);
  controllers[1] = &FastLED.addLeds<WS2812, 11>(leds, i);

}

void loop() {
  // draw led data for the first strand into leds
  fill_solid( &(leds[i]), 24 /*number of leds*/, CRGB( 102, 255, 102) );

  controllers[0]->showLeds(gBrightness);

  // draw led data for the second strand into leds
  fill_solid( &(leds[i]), 24 /*number of leds*/, CRGB( 102, 255, 102) );
  
  controllers[1]->showLeds(gBrightness);
}




