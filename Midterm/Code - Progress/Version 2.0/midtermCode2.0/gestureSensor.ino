int handleGesture() {
  if ( apds.isGestureAvailable() ) {
    switch ( apds.readGesture() ) {
      case DIR_UP:
        //Lights ON
        Serial.println("UP");
        wakeUp();
        break;

      case DIR_DOWN:
        //Lights OFF
        Serial.println("DOWN");
        sleep();
        break;

      case DIR_LEFT:
        Serial.println("LEFT");
        // not in use//
        break;

      case DIR_RIGHT:
        Serial.println("RIGHT");
        // not in use //
        break;

      case DIR_NEAR:
        //Special Case
        Serial.println("NEAR");
        rainbowCycle(20);
        break;

      case DIR_FAR:
        //Special Case
        Serial.println("FAR");
        theaterChaseRainbow(50);

        break;
      default:
        Serial.println("NONE");
    }
  }
}
