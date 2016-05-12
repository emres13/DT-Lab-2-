int motorVibration() {

  Serial.print("\n");
  Serial.print("Status: Start-Up Engine- Active");
  Serial.print("\n");
  engineKick();
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  
  delay(1000);
  
  Serial.print("\n");
  Serial.print("Status: Take-Off Engine- Active ");
  Serial.print("\n");
  takeOffVibration();

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  
  delay(1000);

  Serial.print("\n");
  Serial.print("Status: Critical");
  Serial.print("\n");
  languageX();
  

  delay(1000);

 
}

void takeOffVibration() {

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  for (int i = 0; i < 256; i++)
  {
    analogWrite(enA, i);
    delay(20);
  }
  // decelerate from maximum speed to zero
  for (int i = 256; i >= 0; --i)
  {
    analogWrite(enA, i);
    delay(20);
  }

}

void engineKick() {

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  {
    digitalWrite(enA, 200);
    delay(2000);

  }

}

void languageX() {

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  {
    digitalWrite(enA, 200);
    delay(500);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);

  }
}

