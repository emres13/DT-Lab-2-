
    int oneAfterAnotherLoop()
{
  int index;
  int delayTime = 1000;
  for (index = 0; index <= 12; index++)
  {
    digitalWrite(ledPins[index], HIGH);
    delay(delayTime);
  }

  for (index = 12; index >= 0; index--)
  {
    digitalWrite(ledPins[index], LOW);
    delay(delayTime);
  }

  
}

