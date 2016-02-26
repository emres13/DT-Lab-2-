
int darkSense() {
    int sensorValue = analogRead(A0);
    Serial.println(sensorValue);
    
    if (darkVar < darkThreshold) {
        darkState = 1;
    } else {
        darkState = 0;
    }
}

