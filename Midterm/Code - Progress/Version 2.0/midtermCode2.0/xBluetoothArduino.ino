int voiceCommand() { //functions are in xColorSchemes tab.

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
    else if (voice == "*wake up") {
      wakeUp();
    }
    else if (voice == "*sleep") {
      sleep();
    }
    else if (voice == "*standby") {
      standby();
  }

    //-----------------------------------------------------------------------//


    voice = "";
  }
}


