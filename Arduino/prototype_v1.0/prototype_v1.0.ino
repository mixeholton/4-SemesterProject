int pinkyRedPin = 11;
int pinkyGreenPin = 10;
int pinkyBluePin = 9;
int fuckyRedPin = 6;
int fuckyBluePin = 5;
int fuckyGreenPin = 3;
int delayTime = 500;
int aPin = 5;


int redColorRGB = 255;
int blueColorRGB = 255;
int greenColorRGB = 255;

int RandomRed;
int RandomGreen;
int RandomBlue;


// this is not used anywhere yet just experimentation 
class Finger {
  private: 
    String name;
    int index;
    int rgb;
};




void setup() {
  Serial.begin(9600);
  pinMode(pinkyRedPin, OUTPUT);
  pinMode(pinkyGreenPin, OUTPUT);
  pinMode(pinkyBluePin, OUTPUT);

  pinMode(fuckyRedPin, OUTPUT);
  pinMode(fuckyGreenPin, OUTPUT);
  pinMode(fuckyBluePin, OUTPUT);
}


void loop() {
  //}
  int mix = analogRead(aPin);
  Serial.println(analogRead(aPin));
  RandomRed = random(0, 255);
  RandomGreen = random(0, 255);
  RandomBlue = random(0, 255);

  if (mix != 0) {
    setPinkyColor(128, 128, 0);
    setFuckyColor(128, 128, 0);
  }
  else {
    setPinkyColor(0, blueColorRGB, 0);
    setFuckyColor(redColorRGB , 0, 0);
  }
  delay(delayTime);

  //  for (int i = 0; i < 30000; i++) {
  //    setColor(i, 50, i+25);
  //    delay(delayTime);
  //    Serial.println(i);
  //    if (i == 255) {
  //      i = 0;
  //    }
  //  }
  //  setColor(255, 0, 0); // Red Color
  //  delay(delayTime);
  //  setColor(0, 255, 0); // Green Color
  //  delay(delayTime);
  //  setColor(0, 0, 255); // Blue Color
  //  delay(delayTime);
  //  setColor(255, 255, 255); // White Color
  //  delay(delayTime);
  //  setColor(170, 0, 255); // Purple Color
  //  delay(delayTime);
}
void setPinkyColor(int pinkyRedValue, int pinkyGreenValue, int pinkyBlueValue) {
  analogWrite(pinkyRedPin, pinkyRedValue);
  analogWrite(pinkyGreenPin, pinkyGreenValue);
  analogWrite(pinkyBluePin, pinkyBlueValue);
}

void setFuckyColor(int fuckyRedValue, int fuckyGreenValue, int fuckyBlueValue) {
  analogWrite(fuckyRedPin, fuckyRedValue);
  analogWrite(fuckyGreenPin, fuckyGreenValue);
  analogWrite(fuckyBluePin, fuckyBlueValue);
}



