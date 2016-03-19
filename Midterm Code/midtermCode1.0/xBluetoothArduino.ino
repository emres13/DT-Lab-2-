void allon(){
     digitalWrite(Ring1, HIGH);
     digitalWrite(Ring1, HIGH);

}
void alloff(){
     digitalWrite(Ring1, LOW);
     digitalWrite(Ring2, LOW);
   
}

int voiceCommand(){
  
 if (voice.length() > 0) {
    Serial.println(voice);
//-----------------------------------------------------------------------//   
  //----------Control Multiple Pins/ LEDs----------// 
            if(voice == "*all on") {allon();}  //Turn Off All Pins (Call Function)
  else if(voice == "*all off") {alloff();} //Turn On  All Pins (Call Function)
 
  //----------Turn On One-By-One----------//
  else if(voice == "*TV on") {digitalWrite(Ring1, HIGH);}
  else if(voice == "*fan on") {digitalWrite(Ring2, HIGH);}
  
  //----------Turn Off One-By-One----------//
  else if(voice == "*TV off") {digitalWrite(Ring1, LOW);}
  else if(voice == "*fan off") {digitalWrite(Ring2, LOW);}
 
//-----------------------------------------------------------------------// 
voice="";}} //Reset the variable after initiating
