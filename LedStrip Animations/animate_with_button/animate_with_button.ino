#include "FastLED.h"

// How many leds in your strip?
#define NUM_LEDS 60

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806, define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 6
#define CLOCK_PIN 13

#define BUTTON_PIN   2

bool oldState = HIGH;
int showType = 0;
// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() {
  Serial.begin(57600);
  Serial.println("resetting");
  LEDS.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS);
  LEDS.setBrightness(240);
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

  bool newState = digitalRead(BUTTON_PIN);

  // Check if state changed from high to low (button press).
  if (newState == LOW && oldState == HIGH) {
    // Short delay to debounce button.
    delay(20);
    // Check if button is still low after debounce.
    newState = digitalRead(BUTTON_PIN);
    if (newState == LOW) {
      showType++;
      if (showType > 5)
        showType = 0;
      startShow(showType);
    }
  }

  // Set the last button state to the old state.
  oldState = newState;
}
void startShow(int i) {
  switch (i) {
    case 0: onePixel();
      break;
    case 1: fade3pix();
      break;
    case 2: fade4pix();
      break;
    case 3: changeColor();
      break;
    case 4: hsvChange();
      break;
    case 5: rainEffect();
      break;
      case 6: thunderStrike();
      break;

  }

}


