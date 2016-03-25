uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return pixels.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if (WheelPos < 170) {
    WheelPos -= 85;
    return pixels.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return pixels.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
void wakeUp() {
  colorWipe(pixels.Color(255, 0, 0), 50); // Red
  colorWipe(pixels.Color(0, 255, 0), 50); // Green
  colorWipe(pixels.Color(0, 0, 255), 50); // Blue
  colorWipe(pixels.Color(0, 0, 128), 50); // Blue
  colorWipe(pixels.Color(0, 128, 0), 50); // Green
  colorWipe(pixels.Color(255, 165, 0), 50); // Orange
}
void sleep() {

  for ( int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(black)); // name the color
    pixels.show(); // update pixel
  }
}


void colorWipe(uint32_t c, uint8_t wait) {
  for (uint16_t i = 0; i < pixels.numPixels(); i++) {
    pixels.setPixelColor(i, c);
    pixels.show();
    delay(100);
  }
}

void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for (j = 0; j < 256 * 5; j++) { // 5 cycles of all colors on wheel
    for (i = 0; i < pixels.numPixels(); i++) {
      pixels.setPixelColor(i, Wheel(((i * 256 / pixels.numPixels()) + j) & 255));
    }
    pixels.show();
    delay(wait);
  }

}

void theaterChaseRainbow(uint8_t wait) {
  for (int j = 0; j < 256; j++) {   // cycle all 256 colors in the wheel
    for (int q = 0; q < 3; q++) {
      for (int i = 0; i < pixels.numPixels(); i = i + 3) {
        pixels.setPixelColor(i + q, Wheel( (i + j) % 255)); //turn every third pixel on
      }
      pixels.show();

      delay(wait);

      for (int i = 0; i < pixels.numPixels(); i = i + 3) {
        pixels.setPixelColor(i + q, 0);      //turn every third pixel off
      }
    }
  }
}
