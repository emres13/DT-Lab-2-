#include "FastLED.h"

// How many leds in your strip?
#define NUM_LEDS 60

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806, define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 6
#define CLOCK_PIN 13


// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() {
  Serial.begin(57600);
  Serial.println("resetting");
  LEDS.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS);
  LEDS.setBrightness(255);
}
//3pixelTail
void fadeall2() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i].nscale8(80);
  }
}
//4pixelTail
void fadeall3() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i].nscale8(100);
  }
}
void fadeall4() {
  for (int i = 0; i < NUM_LEDS; i + 10) {
    leds[i].nscale8(120);
  }
}

void loop() {

  onePixel();
  fade3pix();
  fade4pix();
  changeColor();
  hsvChange();
  rainEffect();
  thunderStrike();


}



