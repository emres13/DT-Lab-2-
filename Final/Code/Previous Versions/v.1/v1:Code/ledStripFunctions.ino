int LedAnimations(){
  Serial.print("\n");
  Serial.print("Journey of Emre Sardogan");
  Serial.print("\n");

  wakeUpHelmet();
  Serial.print("\n");
  Serial.print("Mission Contol: Helmet Awake");
  Serial.print("\n");
  FastLED.delay(10000);
  
  normalLighting();
  Serial.print("\n");
  Serial.print("Mission Contol: Astronot Ready");
  Serial.print("\n");
  FastLED.delay(10000);
  
  takeOff();
  Serial.print("\n");
  Serial.print("Mission Contol: Take off successfull");
  Serial.print("\n");
  FastLED.delay(1000);

  leavingTheAtmosphere();
  Serial.print("\n");
  Serial.print("Mission Contol: Atmosphere Passed");
  Serial.print("\n");
  FastLED.delay(1000);

  whenArrivedSpace();
  Serial.print("\n");
  Serial.print("Mission Contol: Arrived Space");
  Serial.print("\n");
  FastLED.delay(100);

  languageConfussion();
  Serial.print("\n");
  Serial.print("Mission Contol: Data lost");
  Serial.print("\n");
  FastLED.delay(1000);

  theEnd();
  Serial.print("\n");
  Serial.print("Mission Contol: One more hope");
  Serial.print("\n");
  FastLED.delay(1000);
}


//Helmet WakeUp animation
void wakeUpHelmet() {

  //brightness1
  FastLED.setBrightness(20);
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::White;
  }
  FastLED.show();
  FastLED.delay(500);
  //brightness2
  FastLED.setBrightness(40);
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::White;
  }
  FastLED.show();
  FastLED.delay(500);
  //brightness3
  FastLED.setBrightness(60);
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::White;
  }
  FastLED.show();
  FastLED.delay(500);

}

//normal amount of light inside the helmet
void normalLighting() {
  FastLED.setBrightness(20);
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::White;
  }
  FastLED.show();
}
//lower brightness for take off
void takeOff() {

  FastLED.setBrightness(10);
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::White;
  }
  FastLED.show();
}


//flash white light
void leavingTheAtmosphere() {

  //call bright white light
  FastLED.setBrightness(100);
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::White;
  }
  FastLED.show();
  FastLED.delay(200);
  //call black to clear
  FastLED.setBrightness(200);
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Black;
  }
  FastLED.show();
  FastLED.delay(200);
}

//yellow lights flying around
void whenArrivedSpace() {
  static uint8_t hue = 0;
  FastLED.setBrightness(50);
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Yellow;
    FastLED.show();
    fadeall();

  }
  for(int i = (NUM_LEDS)-1; i >= 0; i--) {
    leds[i] = CRGB::Yellow;
    FastLED.show();
    fadeall();
}
}

//call normal lighting first
//losing power
void languageConfussion() {

  normalLighting();
  for (int dot = 0; dot < NUM_LEDS; dot++) {
    leds[dot] = CRGB::Black;
    FastLED.show();
    // clear this led for the next time around the loop
    FastLED.delay(500);
  }

}

//last one flash turn on
void theEnd() {

  FastLED.setBrightness(150);
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::White;
  }
  FastLED.show();
  FastLED.delay(100);
  FastLED.setBrightness(150);
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Black;
  }
  FastLED.show();
  FastLED.delay(100);

}



