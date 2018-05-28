
#include <Adafruit_NeoPixel.h>
#define NUMPIXELS      3 // number of neopixels in strip

int indexPin = 3;
int middlePin = 6;
int ringPin = 9;
int pinkyPin = 12;

// Adafruit class for a neopixles
Adafruit_NeoPixel index = Adafruit_NeoPixel(NUMPIXELS, indexPin, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel middle = Adafruit_NeoPixel(NUMPIXELS, middlePin, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel ring = Adafruit_NeoPixel(NUMPIXELS, ringPin, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pinky = Adafruit_NeoPixel(NUMPIXELS, pinkyPin, NEO_GRB + NEO_KHZ800);

Adafruit_NeoPixel hand[] = {index, middle, ring, pinky};

// -----------------------------

int thumbSensor = 0;
int indexSensor = 1;
int middleSensor = 2;
int ringSensor = 3;
int pinkySensor = 4;

const int NUM_FINGERS = 5;

bool finger0 = 0;
bool finger1 = 0;
bool finger2 = 0;
bool finger3 = 0;
bool finger4 = 0;

int fingers[] = {finger0, finger1, finger2, finger3, finger4};

int test[4][3] = {
  {255, 0, 0},
  {127, 127, 0},
  {0, 0, 255},
  {0, 255, 0}
};

int offSet = 1000;

int sensorTresholdThumb;
int sensorTresholdIndex;
int sensorTresholdMiddle;
int sensorTresholdRing;
int sensorTresholdPinky;

int tresholdArray[] = {
  sensorTresholdThumb,
  sensorTresholdIndex,
  sensorTresholdMiddle,
  sensorTresholdRing,
  sensorTresholdPinky
};

//-----------------------------

// sættes for referencens skyld
long redColor;
long greenColor;
long blueColor;

// test

int sum;

void setup() {

  Serial.begin(9600);
  index.begin();
  middle.begin();
  ring.begin();
  pinky.begin();
// Kan indsætte offSet
  sensorTresholdThumb = analogRead(thumbSensor);
  sensorTresholdIndex = analogRead(indexSensor);
  sensorTresholdMiddle = analogRead(middleSensor);
  sensorTresholdRing = analogRead(ringSensor);
  sensorTresholdPinky = analogRead(pinkySensor);



  for (int i = 0; i < NUM_FINGERS;  i++) {
    tresholdArray[i] = analogRead(i);
  };
 // Serial.println(sensorTresholdThumb) + offSet;
  //Serial.println(sensorTresholdIndex) + offSet;
  //Serial.println(sensorTresholdMiddle) + offSet;
  //Serial.println(sensorTresholdRing) + offSet;
  //Serial.println(sensorTresholdPinky) + offSet;
}

void loop() {

  //  Serial.println(analogRead(4));

  int sum = 0;
  int redColor = 0;
  int greenColor = 0;
  int blueColor = 0;
  int sumMix = 0;

  // Read sensors and handle on/off

  //----------------------------------
  // Read the analog pins
  for (int i = 0; i < NUM_FINGERS ; i++) {
    // bestem hvad der er on eller off
    Serial.print("analogs pin nummer: ");
    Serial.println(i);
    Serial.println(analogRead(i));
    Serial.println(tresholdArray[i]);
    delay(100);
    if (analogRead(i) < tresholdArray[i]) {
      fingers[i] = 1;
      sum ++;
    }
    else {
      fingers[i] = 0;
    }
  }
  Serial.print("sum here:");
  Serial.println(sum);

  //---------------------------------

  if (fingers[0]) {

    // nu skal farverne blandes

    // loop starter på 1 pga. tommelfinger
    for (int i = 1; i < NUM_FINGERS; i++) {
      // for hver finger , som ikke er tommel
      if (fingers[i]) {
        // træk 1 fra i så vi kan finde de repspektive farveværdier fra 2d arrayet
        redColor += test[i - 1][0];
        greenColor += test[i - 1][1];
        blueColor += test[i - 1][2];
      }
    }

  }
  for (int i = 1; i < NUM_FINGERS ; i++) {
    // for hver finger der ikke er tommel:
    
      // når tommelen ikke er løftet skal de have normale farver.
      if (!fingers[0] ) {
        redColor = test[i - 1][0];
        greenColor = test[i - 1][1];
        blueColor = test[i - 1][2];
      }
      sumMix = redColor + blueColor + greenColor;

      // her normaliseres værdierne så hvis de ikke er kun en farve
      // så får de den korrekte lysintensitet
      redColor = redColor * (255.0 / sumMix);
      greenColor = greenColor * (255.0 / sumMix);
      blueColor = blueColor * (255.0 / sumMix);
      //    Serial.print("finger: ");
      //    Serial.println(i);
      //    Serial.println(redColor);
      //    Serial.println(greenColor);
      //    Serial.println(blueColor);

      for (int j = 0; j < NUMPIXELS; j ++) {

        hand[i - 1].setPixelColor(j, redColor*fingers[i], greenColor*fingers[i], blueColor*fingers[i]);
        hand[i - 1].show();
      


    }
  }
}
// indexfinger on/off
//  if (indexState > sensorTreshold ) {
//    int redColor = 255;
//    int greenColor = 0;
//    int blueColor = 0;
//    index.setPixelColor(0, redColor, greenColor, blueColor);
//    index.show();
//  } else {
//    int redColor = 0;
//    int greenColor = 0;
//    int blueColor = 0;
//    index.setPixelColor(0, redColor, greenColor, blueColor);
//    index.show();
//
//  }

//  if (middleState > sensorTreshold ) {
//    int redColor = 0;
//    int greenColor = 255;
//    int blueColor = 0;
//    middle.setPixelColor(0, redColor, greenColor, blueColor);
//    middle.show();
//  }
//  if (ringState > sensorTreshold ) {
//    int redColor = 0;
//    int greenColor = 0;
//    int blueColor = 255;
//    ring.setPixelColor(0, redColor, greenColor, blueColor);
//    ring.show();
//  }
//  if (pinkyState > sensorTreshold ) {
//    int redColor = 255;
//    int greenColor = 255;
//    int blueColor = 255;
//    pinky.setPixelColor(0, redColor, greenColor, blueColor);
//    pinky.show();
//  }

//  if (thumbState > sensorTreshold) {}



//
//  if(indexButtonState == HIGH) {
//    digitalWrite(redLED, HIGH);
//  } else {
//    digitalWrite(redLED, LOW);
//  }
//
//  if(middleButtonState == HIGH) {
//    digitalWrite(yellowLED, HIGH);
//  } else {
//    digitalWrite(yellowLED, LOW);
//  }
//
//  if(ringButtonState == HIGH) {
//    digitalWrite(greenLED, HIGH);
//  } else {
//    digitalWrite(greenLED, LOW);
//  }
//
//  if(pinkyButtonState == HIGH) {
//    setColorBlue(255);
//  } else {
//    setColorBlue(0);
//  }
//
//  if(thumbButtonState == HIGH && indexButtonState == HIGH && middleButtonState == HIGH) {
//    setColorOrange();
//  } else {
//    setColorOff();
//  }
//
//  if(thumbButtonState == HIGH && indexButtonState == HIGH && ringButtonState == HIGH) {
//    setColorBrown();
//  } else {
//    setColorOff();
//  }
//
//  if(thumbButtonState == HIGH && indexButtonState == HIGH && pinkyButtonState == HIGH) {
//    setColorViolet();
//  } else {
//    setColorOff();
//  }
//
//  if(thumbButtonState == HIGH && middleButtonState == HIGH && ringButtonState == HIGH) {
//    setColorLightgreen();
//  } else {
//    setColorOff();
//  }
//
//  if(thumbButtonState == HIGH && middleButtonState == HIGH && pinkyButtonState == HIGH) {
//    setColorDarkgreen();
//  } else {
//    setColorOff();
//  }
//
//  if(thumbButtonState == HIGH && ringButtonState == HIGH && pinkyButtonState == HIGH) {
//    setColorTurkish();
//  } else {
//    setColorOff();
//  }

//  if(thumbButtonState == HIGH && indexButtonState == HIGH && middleButtonState == HIGH && ringButtonState == HIGH && pinkyButtonState == HIGH) {
//    setRainbow();
//  } else {
//    setColorOff();
//  }
//
//  if(thumbButtonState == HIGH && pinkyButtonState == HIGH) {
//    setBlink();
//  } else {
//    setColorOff();
//    analogWrite(blueLED_RGB_Red, 0);
//    analogWrite(blueLED_RGB_Green, 0);
//    analogWrite(blueLED_RGB_Blue, 0);
//  }


//
//void setColorMix(int redValue, int greenValue, int blueValue) {
//  analogWrite(RGB_Red, redValue);
//  analogWrite(RGB_Green, greenValue);
//  analogWrite(RGB_Blue, blueValue);
//}
//
//
//void setColorBlue(int blueVal) {
//  analogWrite(blueLED_RGB_Red, 0);
//  analogWrite(blueLED_RGB_Green, 0);
//  analogWrite(blueLED_RGB_Blue, blueVal);
//}
//
//
//void setColorOrange() {
//  analogWrite(RGB_Red, 255);
//  analogWrite(RGB_Green, 165);
//  analogWrite(RGB_Blue, 0);
//}
//
//void setColorLightgreen() {
//  analogWrite(RGB_Red, 124);
//  analogWrite(RGB_Green, 252);
//  analogWrite(RGB_Blue, 0);
//}
//
//void setColorTurkish() {
//  analogWrite(RGB_Red, 64);
//  analogWrite(RGB_Green, 224);
//  analogWrite(RGB_Blue, 208);
//}
//
//void setColorBrown() {
//  analogWrite(RGB_Red, 244);
//  analogWrite(RGB_Green, 164);
//  analogWrite(RGB_Blue, 96);
//}
//
//void setColorViolet() {
//  analogWrite(RGB_Red, 235);
//  analogWrite(RGB_Green, 130);
//  analogWrite(RGB_Blue, 235);
//}
//
//void setColorDarkgreen() {
//  analogWrite(RGB_Red, 60);
//  analogWrite(RGB_Green, 179);
//  analogWrite(RGB_Blue, 113);
//}
//
//
//void setRainbow() {
//  analogWrite(blueLED_RGB_Red, 0);
//  analogWrite(blueLED_RGB_Green, 0);
//  analogWrite(blueLED_RGB_Blue, 0);
//  analogWrite(RGB_Red, 255);
//  analogWrite(RGB_Red, 255);
//  analogWrite(RGB_Red, 255);
//  delay(100);
//  analogWrite(RGB_Red, 0);
//  analogWrite(RGB_Red, 0);
//  analogWrite(RGB_Red, 0);
//  digitalWrite(redLED, HIGH);
//  delay(100);
//  digitalWrite(redLED, LOW);
//  digitalWrite(yellowLED, HIGH);
//  delay(100);
//  digitalWrite(yellowLED, LOW);
//  digitalWrite(greenLED, HIGH);
//  delay(100);
//  digitalWrite(greenLED, LOW);
//  analogWrite(blueLED_RGB_Red, 0);
//  analogWrite(blueLED_RGB_Green, 0);
//  analogWrite(blueLED_RGB_Blue, 255);
//  delay(100);
//}
//
//
//void setBlink() {
//  analogWrite(blueLED_RGB_Red, 0);
//  analogWrite(blueLED_RGB_Green, 0);
//  analogWrite(blueLED_RGB_Blue, 255);
//  delay(80);
//  analogWrite(blueLED_RGB_Red, 0);
//  analogWrite(blueLED_RGB_Green, 0);
//  analogWrite(blueLED_RGB_Blue, 0);
//  analogWrite(RGB_Red, 255);
//  analogWrite(RGB_Green, 0);
//  analogWrite(RGB_Blue, 0);
//  delay(80);
//  analogWrite(blueLED_RGB_Red, 255);
//  analogWrite(blueLED_RGB_Green, 0);
//  analogWrite(blueLED_RGB_Blue, 0);
//  analogWrite(RGB_Red, 0);
//  analogWrite(RGB_Green, 0);
//  analogWrite(RGB_Blue, 0);
//  delay(80);
//  analogWrite(blueLED_RGB_Red, 0);
//  analogWrite(blueLED_RGB_Green, 0);
//  analogWrite(blueLED_RGB_Blue, 0);
//  analogWrite(RGB_Red, 0);
//  analogWrite(RGB_Green, 255);
//  analogWrite(RGB_Blue, 0);
//  delay(80);
//  analogWrite(blueLED_RGB_Red, 0);
//  analogWrite(blueLED_RGB_Green, 255);
//  analogWrite(blueLED_RGB_Blue, 0);
//  analogWrite(RGB_Red, 0);
//  analogWrite(RGB_Green, 0);
//  analogWrite(RGB_Blue, 0);
//  delay(80);
//  analogWrite(blueLED_RGB_Red, 0);
//  analogWrite(blueLED_RGB_Green, 0);
//  analogWrite(blueLED_RGB_Blue, 0);
//  analogWrite(RGB_Red, 0);
//  analogWrite(RGB_Green, 0);
//  analogWrite(RGB_Blue, 255);
//  delay(80);
//}
//
//void setColorOff() {
//  analogWrite(RGB_Red, 0);
//  analogWrite(RGB_Green, 0);
//  analogWrite(RGB_Blue, 0);
//}
