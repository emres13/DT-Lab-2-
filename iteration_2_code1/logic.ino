int logic() {
    switch (stateVar) {
        
       
            
        case (1): // night time lights on
            lightVar = 1;
            if (darkVar == 1) {
                lightVar = !lightVar;
                stateVar = 1;
                Serial.println("State 1");
                touched = 2;
            } else if (darkState == 0) {
                stateVar = 0;
                Serial.println("State 0");
            }
    }
}

