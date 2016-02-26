#include <Wire.h>

#include <RTClib.h>

#define DS3231_I2C_ADDRESS 0x68

int darkState;
int darkThreshold = 400;
int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

// Set up LED display
int ledState; // Determines which frame of the animation.
int animeSpeed = 8000; // Speed at which the LEDs change frames.
int maxBrightness = 3100; // Maximum brightness for LEDs. Used for fading on and off the light.


int pinCount = 12; // how many pwm pins



// Variables for logic

int touched; // Just touched?
int stateVar; // State of the light
boolean lightVar; // Lights on?
boolean darkVar;

void setup() {
  for (int thisPin = 0; thisPin < pinCount; thisPin++) { // set the 6 led pins to output
    pinMode(ledPins[thisPin], OUTPUT);
  }
  

  Serial.begin(9600);
  Serial.println();
 
}

void loop() {
darkSense();

 logic();
 
  oneAfterAnotherLoop(); // call the function "fade"
  
 
}

