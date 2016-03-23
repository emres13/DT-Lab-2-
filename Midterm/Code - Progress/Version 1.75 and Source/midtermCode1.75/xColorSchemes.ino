void love() {

  for (int i = 0; i < NUMPIXELS; i++) {
    //Color of the LED's before LED#8
    pixels.setPixelColor(i, pixels.Color(blue)); // name the color
    pixels.show(); // update pixel
  }
  for (int i = 8; i < NUMPIXELS; i++) {
    //Color of the LED's between (8-18)
    pixels.setPixelColor(i, pixels.Color(magenta)); // name the color
    pixels.show(); // update pixel
  }
  for (int i = 16; i < NUMPIXELS; i++) {
    //Color of the LED's before LED#18
    pixels.setPixelColor(i, pixels.Color(green));// name the color
    pixels.show(); // update pixel
  }
}

void energy() {
  for (int i = 0; i < NUMPIXELS; i++) {
    //Color of the LED's before LED#18
    pixels.setPixelColor(i, pixels.Color(red)); // name the color
    pixels.show();// update pixel
  }
  for (int i = 18; i < NUMPIXELS; i++) {
  //Color of the LED's after LED#18
    pixels.setPixelColor(i, pixels.Color(yellow)); // name the color
    pixels.show(); // update pixel
  }
}
void creativity() {
  for (int i = 0; i < NUMPIXELS; i++) {
    //Color of the LED's before LED#12
    pixels.setPixelColor(i, pixels.Color(orange)); // name the color
    pixels.show(); // update pixel
  }
  for (int i = 12; i < NUMPIXELS; i++) {
  //Color of the LED's after LED#12
    pixels.setPixelColor(i, pixels.Color(white));// name the color
    pixels.show(); // update pixel
  }
}
void lost() {
  for (int i = 0; i < NUMPIXELS; i++) {
    //Color of the LED's before #12
    pixels.setPixelColor(i, pixels.Color(navy)); // name the color
    pixels.show(); // update pixel
  }
  for (int i = 12; i < NUMPIXELS; i++) {
    //Color of the LED's after #12
    pixels.setPixelColor(i, pixels.Color(cyan)); // name the color
    pixels.show(); // update pixel
  }
}
