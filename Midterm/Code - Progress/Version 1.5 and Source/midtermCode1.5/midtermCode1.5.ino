/*
  Code by: Emre Sardogan
  March 18, 2016 @ Parsons School of Design
  '''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  Credits to: Angelo Casimiro (4/27/14)(Android-Bluetooth)
            : Shawn Hymel @ SparkFun Electronics(GestureSensor)
            : AdaFruit NeoPixel Library-Example Sketches(NeoPixels)
  
            Code Version 1.5
            Gesture Sensor (Working(commands-not-assigned-yet)
            NeoPixel #1 (Connected and Working)
            Bluetooth (Connected + Working)
            Voice Color Commands(Working(commands-not-assigned-yet)
*/



//Libraries
#include <Wire.h>
#include <SparkFun_APDS9960.h>
#include <Adafruit_NeoPixel.h>

#define PIN 10
#define NUMPIXELS 24

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(24, PIN, NEO_GRB + NEO_KHZ800);


//GestureSensorPins
#define APDS9960_INT    2 //interrupt pin


//Global Variables
SparkFun_APDS9960 apds = SparkFun_APDS9960();
int isr_flag = 0;
String voice;
int delayval = 500;

//CRGB leds[NUM_LEDS];
//CLEDController *controllers[NUM_STRIPS];
//uint8_t gBrightness = 255;




void setup() {

  //NeoPixelRing - Output

  pixels.begin();
  pixels.show();

  //FastLED
  // controllers[0] = &FastLED.addLeds<WS2812, 10>(leds, NUM_LEDS);
  // controllers[1] = &FastLED.addLeds<WS2812, 11>(leds, NUM_LEDS);

  Serial.begin(9600);
  //GestureSensor - Input
  pinMode(APDS9960_INT, INPUT);

  //debug PIN
  pinMode(6, OUTPUT);


  //GestureSensor-Setup
  Serial.println();
  Serial.println(F("--------------------------------"));
  Serial.println(F("GestureTest"));
  Serial.println(F("--------------------------------"));

  // Initialize interrupt service routine
  attachInterrupt(0, interruptRoutine, FALLING);

  // Initialize APDS-9960 (configure I2C and initial values)
  if ( apds.init() ) {
    Serial.println(F("initialization complete"));
  } else {
    Serial.println(F("Something went wrong during APDS-9960 init!"));
  }

  // Start running the APDS-9960 gesture sensor engine
  if ( apds.enableGestureSensor(true) ) {
    Serial.println(F("Gesture sensor is now running"));
  } else {
    Serial.println(F("Something went wrong during gesture sensor init!"));
  }



}

void loop() {
  voiceCommand();



  //Loop 1 - GestureSensor
  if ( isr_flag == 1 ) {
    detachInterrupt(0);
    handleGesture();
    isr_flag = 0;
    attachInterrupt(0, interruptRoutine, FALLING);
  }
  //Loop 2 - Bluetooth-Android
  while (Serial.available()) { //Check if there is an available byte to read
    delay(10); //Delay added to make thing stable
    char x = Serial.read(); //Conduct a serial read
    if (x == '#') {
      break; //Exit the loop when the # is detected after the word
    }
    voice += x; //Shorthand for voice = voice + c
  }
  if (voice.length() > 0) {
    Serial.println(voice);
  }
}

//Routine Int - Gesture Sensor
void interruptRoutine() {
  isr_flag = 1;
}
