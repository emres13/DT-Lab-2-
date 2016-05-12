#include <SPI.h>
#include <SdFat.h>
#include <SdFatUtil.h>
#include <SFEMP3Shield.h>
#include <FastLED.h>
#include <SimpleTimer.h>

#define LED_PIN     A0

// Information about the LED strip itself
#define NUM_LEDS    60
#define CHIPSET     WS2812
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

SdFat sd;
SFEMP3Shield MP3player;

int enA = 10;
int in1 = A2;
int in2 = A3;




// There must be one global SimpleTimer object.
// More SimpleTimer objects can be created and run,
// although there is little point in doing so.
SimpleTimer timer;


void fadeall() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i].nscale8(1000);
  }
}

// function to be called repeatedly
void wakeUpHelmet() {
  Serial.print("Mission Contol: Helmet Awake");
  Serial.print("\n");
  //brightness1
  FastLED.setBrightness(20);
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::White;
  }
  FastLED.show();
  FastLED.delay(1000);
  //brightness2
  FastLED.setBrightness(40);
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::White;
  }
  FastLED.show();
  FastLED.delay(1000);
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
  Serial.print("Helmet Lights Up");
  Serial.print("\n");
  FastLED.setBrightness(60);
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::White;
  }
  FastLED.show();
}
//lower brightness for take off
void takeOff() {
  Serial.print("Mission Contol: Take off successfull");
  Serial.print("\n");
  FastLED.setBrightness(10);
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::White;
  }
  FastLED.show();
}


//flash white light
void leavingTheAtmosphere() {
  Serial.print("Mission Contol: Atmosphere Passed");
  Serial.print("\n");
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
  Serial.print("Mission Contol: Arrived Space");
  Serial.print("\n");
  static uint8_t hue = 0;
  FastLED.setBrightness(50);
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Yellow;
    FastLED.show();
    fadeall();

  }
  for (int i = (NUM_LEDS) - 1; i >= 0; i--) {
    leds[i] = CRGB::Yellow;
    FastLED.show();
    fadeall();
  }

}


void languageConfussion() {
  FastLED.clear();
  normalLighting();
  Serial.print("Mission Contol: Data lost");
  Serial.print("\n");

  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Black;
    FastLED.show();
    // clear this led for the next time around the loop
    FastLED.delay(800);
  }
}




//last one flash turn on
void theEnd() {
  Serial.print("Mission Contol: One more hope");
  Serial.print("\n");
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

void takeOffVibration() {
  Serial.print("Status: Take-Off Engine- Active ");
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  for (int i = 0; i < 256; i++)
  {
    analogWrite(enA, i);
    delay(40);
  }
  // decelerate from maximum speed to zero
  for (int i = 256; i >= 0; --i)
  {
    analogWrite(enA, i);
    delay(37);
  }
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}


void engineKick() {
  Serial.print("Status: Engine- Heating Up ");

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  {
    digitalWrite(enA, 200);
    delay(1000);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);

  }

}
// print current arduino "uptime" on the serial port
void DigitalClockDisplay() {
  int h, m, s;
  s = millis() / 1000;
  m = s / 60;
  h = s / 3600;
  s = s - m * 60;
  m = m - h * 60;
  Serial.print(h);
  printDigits(m);
  printDigits(s);
  Serial.println();
}

void printDigits(int digits) {
  Serial.print(":");
  if (digits < 10)
    Serial.print('0');
  Serial.print(digits);
}



void setup() {
  Serial.begin(9600);



  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalSMD5050 );
  pinMode(A0, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  Serial.begin(9600);

  sd.begin(SD_SEL, SPI_HALF_SPEED);
  MP3player.begin();

  MP3player.playTrack(1);
  MP3player.setVolume(0, 0);

  // timed actions setup

  timer.setInterval(1000, DigitalClockDisplay);

  timer.setTimeout(5000, wakeUpHelmet);
  timer.setTimeout(10000, engineKick);
  timer.setTimeout(18000, engineKick);

  timer.setTimeout(74000, takeOff);
  timer.setTimeout(76000, takeOffVibration);

  timer.setTimeout(96000, leavingTheAtmosphere);

  timer.setTimeout(110000, whenArrivedSpace);
  timer.setTimeout(130000, whenArrivedSpace);

  timer.setTimeout(135000, languageConfussion);

  timer.setTimeout(187000, theEnd);

}


void loop() {
  // this is where the "polling" occurs
  timer.run();
}
