//Libraries
#include <Wire.h>
#include <SparkFun_APDS9960.h>

//GestureSensorPins
#define APDS9960_INT    2 //interrupt pin

//Global Variables
SparkFun_APDS9960 apds = SparkFun_APDS9960();
int isr_flag = 0;
String voice;
int
Ring1 = 10, //Connect LED 1 To Pin #2
Ring2 = 11; //Connect LED 2 To Pin #3


void setup() {

  Serial.begin(9600);
  //GestureSensor - Input
  pinMode(APDS9960_INT, INPUT);
  //NeoPixelRing - Output
  pinMode(Ring1, OUTPUT);
  pinMode(Ring2, OUTPUT);

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
    char c = Serial.read(); //Conduct a serial read
    if (c == '#') {
      break; //Exit the loop when the # is detected after the word
    }
    voice += c; //Shorthand for voice = voice + c
  }
  if (voice.length() > 0) {
    Serial.println(voice);
    voiceCommand();
  }
}

//Routine Int - Gesture Sensor
void interruptRoutine() {
  isr_flag = 1;
}
