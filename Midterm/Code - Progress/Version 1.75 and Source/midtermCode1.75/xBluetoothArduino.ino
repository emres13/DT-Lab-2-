int voiceCommand() {

  if (voice.length() > 0) {
    Serial.println(voice);

    if (voice == "*love") {
      love(); 
    }
    else if (voice == "*energy") {
      energy(); 
    }
    else if (voice == "*creativity") {
      creativity();
    }
    else if (voice == "*lost") {
      lost();
    }
/*  else if (voice == "*TV off") {
      ;
    }
    else if (voice == "*fan off") {
      ;
    }

    //-----------------------------------------------------------------------//

*/
    voice = "";}}



