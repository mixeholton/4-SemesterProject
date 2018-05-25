#include <Adafruit_NeoPixel.h>

int NUMPIXELS = 3;
int indexPin = 3;
int middlePin = 6;
int ringPin = 9;
int pinkyPin = 12;
int IndexT = 980;
int MiddleT = 950;
int RingT = 940;
int PinkyT = 940;
int finger2, finger3, finger4, finger5;
int start2, start3, start4, start5; 

Adafruit_NeoPixel index = Adafruit_NeoPixel(NUMPIXELS, indexPin, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel middle = Adafruit_NeoPixel(NUMPIXELS, middlePin, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel ring = Adafruit_NeoPixel(NUMPIXELS, ringPin, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pinky = Adafruit_NeoPixel(NUMPIXELS, pinkyPin, NEO_GRB + NEO_KHZ800);


void setup() {
  Serial.begin(9600);
  index.begin();
  middle.begin();
  ring.begin();
  pinky.begin();
  for (int i = 0; i < NUMPIXELS; i++) {
    index.setPixelColor(i, 0, 0, 0);
    middle.setPixelColor(i, 0, 0, 0);
    ring.setPixelColor(i, 0, 0, 0);
    pinky.setPixelColor(i, 0, 0, 0);
  }
  start2 = analogRead(1); 
  start3 = analogRead(2);
  start4 = analogRead(3);
  start5 = analogRead(4);
}

void loop() {

  turnoffMiddle(); 
  turnoffRing(); 
  turnoffPinky(); 
  Serial.println(start2); 
  delay(1000); 

  finger2 = analogRead(1);
  Serial.print("indexfinger: ");
  Serial.println(finger2);

//  finger3 = analogRead(2);
//  Serial.print("middlefinger: ");
//  Serial.println(finger3);


  finger4 = analogRead(3);
  //Serial.print("ringfinger: ");
  //Serial.println(finger4);


  finger5 = analogRead(4);
  //Serial.print("pinkyfinger: ");
  //Serial.println(finger5);

  if (finger2 > start2+10) {
    turnoffIndex();
  } else {
    lightIndexFinger();
  }

//  if (finger3 > start3) {
//    turnoffMiddle();
//  } else {
//    lightMiddleFinger();
//  }
//
//  if (finger4 < RingT) {
//    turnoffRing();
//  } else {
//    lightRingFinger();
//  }
//
//  if (finger5 < PinkyT) {
//    turnoffPinky();
//  } else {
//    lightPinkyFinger();
//  }


}



void turnoffIndex() {
  for (int i = 0; i < NUMPIXELS; i++) {
    index.setPixelColor(i, 0, 0, 0);
  }
  index.show();
}
void turnoffMiddle() {
  for (int i = 0; i < NUMPIXELS; i++) {
    middle.setPixelColor(i, 0, 0, 0);
  }
  middle.show();
}
void turnoffRing() {
  for (int i = 0; i < NUMPIXELS; i++) {
    ring.setPixelColor(i, 0, 0, 0);
  }
  ring.show();
}

void turnoffPinky() {
  for (int i = 0; i < NUMPIXELS; i++) {
    pinky.setPixelColor(i, 0, 0, 0);
  }
  pinky.show();
}



void lightIndexFinger() {
  for (int i = 0; i < NUMPIXELS; i++) {
    index.setPixelColor(i, 255, 0, 0);
  }
  index.show();
}

void lightMiddleFinger() {
  for (int i = 0; i < NUMPIXELS; i++) {
    middle.setPixelColor(i, 127, 127, 0);
  }
  middle.show();
}

void lightRingFinger() {
  for (int i = 0; i < NUMPIXELS; i++) {
    ring.setPixelColor(i, 0, 0, 255);
  }
  ring.show();
}

void lightPinkyFinger() {
  for (int i = 0; i < NUMPIXELS; i++) {
    pinky.setPixelColor(i, 255, 255, 255);
  }
  pinky.show();
}
