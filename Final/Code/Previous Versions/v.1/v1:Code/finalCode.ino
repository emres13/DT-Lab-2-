#include <SPI.h>
#include <SdFat.h>
#include <SdFatUtil.h> 
#include <SFEMP3Shield.h>
#include <FastLED.h>
#include <CapacitiveSensor.h>

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



void setup() {
  


  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalSMD5050 );
  pinMode(A0, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  Serial.begin(9600);

  sd.begin(SD_SEL, SPI_HALF_SPEED);
  MP3player.begin();

  MP3player.playTrack(1);
  MP3player.setVolume(0,0); 
}

void fadeall() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i].nscale8(1000);
  }
}

void loop() {
  //led's
  LedAnimations();
  //motor
  motorVibration();

}
