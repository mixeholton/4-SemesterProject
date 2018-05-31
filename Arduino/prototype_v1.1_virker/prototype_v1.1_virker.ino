
#include <Adafruit_NeoPixel.h>
#define NUMPIXELS      3 // number of neopixels in strip

int indexPin = 3;

// Adafruit class for a neopixles
Adafruit_NeoPixel index = Adafruit_NeoPixel(NUMPIXELS, indexPin, NEO_GRB + NEO_KHZ800);

index.begin();

index.setPixelColor(2, 255, 255, 255);
// this is neopixle syntax
index.show();


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

int fingerBaseColor[4][3] = {
  {255, 0, 0},
  {127, 127, 0},
  {0, 0, 255},
  {0, 255, 0}
};


int sensorThresholdThumb;
int sensorThresholdIndex;
int sensorThresholdMiddle;
int sensorThresholdRing;
int sensorThresholdPinky;

int thresholdArray[] = {
  sensorThresholdThumb,
  sensorThresholdIndex,
  sensorThresholdMiddle,
  sensorThresholdRing,
  sensorThresholdPinky
};

int threshold = 1015;
//-----------------------------

// longs are used to make sure there is no overflow
long redColor;
long greenColor;
long blueColor;

void setup() {
  Serial.begin(9600);
  index.begin();
  middle.begin();
  ring.begin();
  pinky.begin();

  for (int i = 0; i < NUM_FINGERS;  i++) {
    // following comment can change the threshold dynamically to fit the environment
    // thresholdArray[i] = analogRead(i);
    thresholdArray[i] = threshold;
    if (i == 0) {
      // the thumb needs a lower threshold
      thresholdArray[i] -= 15;
    }
  }

}

void loop() {

  int redColor = 0;
  int greenColor = 0;
  int blueColor = 0;
  int sumMix = 0;

  // Read sensors and handle on/off

  //----------------------------------
  // Read the analog pins
  for (int i = 0; i < NUM_FINGERS ; i++) {
    // handle fingers to be considered on or off
    if (analogRead(i) < thresholdArray[i]) {
      fingers[i] = 1;
    }
    else {
      fingers[i] = 0;
    }
  }

  // if the thumb is strechted
  if (!fingers[0]) {
    // loop starts at 1 because of the thumb
    for (int i = 1; i < NUM_FINGERS; i++) {
      if (fingers[i]) {
        // subtracting i with 1 to make sure the it corresponds to the colors from the 2d array
        redColor += fingerBaseColor[i - 1][0];
        greenColor += fingerBaseColor[i - 1][1];
        blueColor += fingerBaseColor[i - 1][2];
      }
    }
  }

  redColor = 1000 * (255.0 / 3000)
  for (int i = 1; i < NUM_FINGERS ; i++) {
    // check if the thumb is in the palm
    if (fingers[0] ) {
      redColor = fingerBaseColor[i - 1][0];
      greenColor = fingerBaseColor[i - 1][1];
      blueColor = fingerBaseColor[i - 1][2];
    }
    sumMix = redColor + blueColor + greenColor;

    // the colors get normalized if there is more than 1 active finger
    // sumMix increases af more colors are selected
    redColor = redColor * (255.0 / sumMix);
    greenColor = greenColor * (255.0 / sumMix);
    blueColor = blueColor * (255.0 / sumMix);

    for (int j = 0; j < NUMPIXELS; j ++) {
      // for each pixle on each finger, give that a color
      hand[i - 1].setPixelColor(j, redColor * fingers[i], greenColor * fingers[i], blueColor * fingers[i]);
      // this is neopixle syntax
      hand[i - 1].show();

    }
  }
}
