void onePixel() { //One pixel moving down the strip

  static uint8_t hue = 0;
  Serial.print("x");
  // First slide the led in one direction
  for (int i = 0; i < NUM_LEDS; i++) {
    // Set the i'th led to red
    leds[i] = CRGB(150, 255, 255);
    // Show the leds
    FastLED.show();
    // now that we've shown the leds, reset the i'th led to black
    leds[i] = CRGB::Black;
    // fadeall();
    // Wait a little bit before we loop around and do it again
    delay(200);
  }
  Serial.print("x");


}

void fade3pix() { //One pixel with a tail, fading in 3 pixels


  static uint8_t hue = 0;
  Serial.print("x");
  // First slide the led in one direction
  for (int i = 0; i < NUM_LEDS; i++) {
    // Set the i'th led to red
    leds[i] = CRGB(150, 255, 255);
    // Show the leds
    FastLED.show();
    // now that we've shown the leds, reset the i'th led to black
    // leds[i] = CRGB::Black;
    fadeall2();
    // Wait a little bit before we loop around and do it again
    delay(200);
  }
  Serial.print("x");


}

void fade4pix() { //One pixel with a tail, fading in 4 pixels and bouncing back to start

  static uint8_t hue = 0;
  Serial.print("x");
  // First slide the led in one direction
  for (int i = 0; i < NUM_LEDS; i++) {
    // Set the i'th led to red
    leds[i] = CRGB(255, 150, 150);
    // Show the leds
    FastLED.show();
    // now that we've shown the leds, reset the i'th led to black
    // leds[i] = CRGB::Black;
    fadeall3();
    // Wait a little bit before we loop around and do it again
    delay(200);
  }
  Serial.print("x");

  // Now go in the other direction.
  for (int i = (NUM_LEDS); i >= 0; i--) {
    // Set the i'th led to red
    leds[i] = CRGB(100, 255, 255);
    // Show the leds
    FastLED.show();
    // now that we've shown the leds, reset the i'th led to black
    // leds[i] = CRGB::Black;
    fadeall3();
    // Wait a little bit before we loop around and do it again
    delay(200);
  }

}

void changeColor() { //One pixel with a tail, fading in 3 pixels and changing color halfway through


  static uint8_t hue = 0;
  Serial.print("x");
  // First slide the led in one direction
  for (int i = 0; i <= 30; i++) {
    // Set the i'th led to red
    leds[i] = CRGB(255, 0, 0);
    // Show the leds
    FastLED.show();
    // now that we've shown the leds, reset the i'th led to black
    // leds[i] = CRGB::Black;
    fadeall2();
    delay(200);
  }
  // Wait a little bit before we loop around and do it aga

  for (int i = 30; i < NUM_LEDS; i++) {
    // Set the i'th led to red
    leds[i] = CRGB(0, 0, 255);
    // Show the leds
    FastLED.show();
    // now that we've shown the leds, reset the i'th led to black
    // leds[i] = CRGB::Black;
    fadeall2();
    // Wait a little bit before we loop around and do it again
    delay(200);
    Serial.print("x");
  }

}

void hsvChange() { //One pixel with a tail, fading in 4 pixels and bouncing 4 times and incrementing its HSV value by one for each step taken
  static uint8_t hue = 0;
  Serial.print("x");
  // First slide the led in one direction
  for (int i = 0; i < NUM_LEDS; i++) {
    // Set the i'th led to red
    leds[i] = CHSV(hue++, 255, 255);
    // Show the leds
    FastLED.show();
    // now that we've shown the leds, reset the i'th led to black
    // leds[i] = CRGB::Black;
    fadeall3();
    // Wait a little bit before we loop around and do it again
    delay(10);
  }
  Serial.print("x");

  // Now go in the other direction.
  for (int i = (NUM_LEDS) - 1; i >= 0; i--) {
    // Set the i'th led to red
    leds[i] = CHSV(hue++, 255, 255);
    // Show the leds
    FastLED.show();
    // now that we've shown the leds, reset the i'th led to black
    // leds[i] = CRGB::Black;
    fadeall3();
    // Wait a little bit before we loop around and do it again
    delay(10);
  }
  
  
}

void rainEffect() { //A blue color which has a random  dripping water effect for 3 seconds (interpretative)

  static uint8_t hue = 0;
  Serial.print("x");
  // First slide the led in one direction
  for(int i = 0; i <= 20; i++) {
    // Set the i'th led to red 
    leds[i] = CRGB(255,181,148);
    // Show the leds
    FastLED.show(); 
    // now that we've shown the leds, reset the i'th led to black
    // leds[i] = CRGB::Black;
    fadeall2();
    // Wait a little bit before we loop around and do it again
    delay(30);
  }

  for(int i =10; i < NUM_LEDS; i++) {
    // Set the i'th led to red 
    leds[i] = CRGB(255,181,148);
    // Show the leds
    FastLED.show();
    // now that we've shown the leds, reset the i'th led to black
    // leds[i] = CRGB::Black;
    fadeall2();
    // Wait a little bit before we loop around and do it again
    delay(30);
  }
  for(int i = (NUM_LEDS)-1; i >= 50; i--) {
    // Set the i'th led to red 
    leds[i] = CRGB(168,66,34);
    // Show the leds
    FastLED.show();
    // now that we've shown the leds, reset the i'th led to black
    // leds[i] = CRGB::Black;
    fadeall2();
    // Wait a little bit before we loop around and do it again
    delay(60);
  }
    for(int i =11; i < NUM_LEDS; i++) {
    // Set the i'th led to red 
    leds[i] = CRGB(168,66,34);
    // Show the leds
    FastLED.show();
    // now that we've shown the leds, reset the i'th led to black
     leds[i] = CRGB::Black;
    fadeall2();
    // Wait a little bit before we loop around and do it again
    delay(45);
  }
      for(int i =4; i < NUM_LEDS; i++) {
    // Set the i'th led to red 
    leds[i] = CRGB(66,16,0);
    // Show the leds
    FastLED.show();
    // now that we've shown the leds, reset the i'th led to black
     leds[i] = CRGB::Black;
    fadeall2();
    // Wait a little bit before we loop around and do it again
    delay(100);
      }
delay(500);

}

void thunderStrike() { //One color which lights the whole strip in various colors for .5 second in a in a lightening effect (interpretative)

  static uint8_t hue = 0;
  Serial.print("x");
  // First slide the led in one direction
  for (int i = 0; i < NUM_LEDS; i+60) {
    // Set the i'th led to red
    leds[i] = CRGB(255, 255, 255);
    // Show the leds
    FastLED.show();
    // now that we've shown the leds, reset the i'th led to black
    leds[i] = CRGB::Black;
    // fadeall();
    // Wait a little bit before we loop around and do it again
    delay(5);
    
    Serial.print("x");
  // First slide the led in one direction
  for (int i = 0; i < NUM_LEDS; i+60) {
    // Set the i'th led to red
    leds[i] = CRGB(255, 255, 255);
    // Show the leds
    FastLED.show();
    // now that we've shown the leds, reset the i'th led to black
    leds[i] = CRGB::Black;
    // fadeall();
    // Wait a little bit before we loop around and do it again
    delay(5);
  }
  Serial.print("x");

}
}


