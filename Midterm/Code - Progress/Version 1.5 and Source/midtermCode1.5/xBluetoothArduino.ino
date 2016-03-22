void love(){
  
  for(int i=0;i<NUMPIXELS;i++){
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(150,0,0)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(delayval); // Delay for a period of time (in milliseconds).
  }
}

void hate(){

digitalWrite(6, HIGH);

}



int voiceCommand(){
  
 if (voice.length() > 0) {
    Serial.println(voice);
//-----------------------------------------------------------------------//   
  //----------Control Multiple Pins/ LEDs----------// 
            if(voice == "*love") {love();}  //Turn Off All Pins (Call Function)
  else if(voice == "*hate") {hate();} //Turn On  All Pins (Call Function)
 
  //----------Turn On One-By-One----------//
  else if(voice == "*TV on") {;}
  else if(voice == "*fan on") {;}
  
  //----------Turn Off One-By-One----------//
  else if(voice == "*TV off") {;}
  else if(voice == "*fan off") {;}
 
//-----------------------------------------------------------------------// 


voice="";}}//Reset the variable after initiating



