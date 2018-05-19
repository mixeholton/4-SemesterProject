//Knapperne på fingrene
int thumbButton = 2; 
int indexButton = 14; 
int middleButton = 15; 
int ringButton = 16; 
int pinkyButton = 17; 

//Alle LED dioderne
//RGB på tommelfingeren
int RGB_Red = 3; 
int RGB_Green = 4; 
int RGB_Blue = 5;  

//LED på de andre fingre
int redLED = 6; 
int yellowLED = 7; 
int greenLED = 8;
//RGB kommer til at repræsentere blå 
int blueLED_RGB_Red = 9; 
int blueLED_RGB_Green = 10; 
int blueLED_RGB_Blue = 11;  

int thumbButtonState = 0;
int indexButtonState = 0;
int middleButtonState = 0;
int ringButtonState = 0;
int pinkyButtonState = 0; 

void setup() {
  Serial.begin(9600); 

  //finer-knapper sættes til input
  pinMode(thumbButton, INPUT); 
  pinMode(indexButton, INPUT);
  pinMode(middleButton, INPUT);
  pinMode(ringButton, INPUT);
  pinMode(pinkyButton, INPUT);

  //LED sættes som output
  pinMode(RGB_Red, OUTPUT);
  pinMode(RGB_Green, OUTPUT);
  pinMode(RGB_Blue, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED_RGB_Red, OUTPUT);
  pinMode(blueLED_RGB_Green, OUTPUT);
  pinMode(blueLED_RGB_Blue, OUTPUT);
}

void loop() {
  //aflæs knappernes input 
  //Serial.println(middleButtonState);
  //delay(1000); 
  thumbButtonState = digitalRead(thumbButton); 
  indexButtonState = digitalRead(indexButton);
  middleButtonState = digitalRead(middleButton);
  ringButtonState = digitalRead(ringButton);
  pinkyButtonState = digitalRead(pinkyButton); 
  //Serial.println(ringButtonState); 

  if(indexButtonState == HIGH) {
    digitalWrite(redLED, HIGH);   
  } else {
    digitalWrite(redLED, LOW);   
  }
  
  if(middleButtonState == HIGH) {
    digitalWrite(yellowLED, HIGH);   
  } else {
    digitalWrite(yellowLED, LOW);   
  }
  
  if(ringButtonState == HIGH) {
    digitalWrite(greenLED, HIGH);   
  } else {
    digitalWrite(greenLED, LOW);   
  }
  
  if(pinkyButtonState == HIGH) {
    setColorBlue(255); 
  } else {
    setColorBlue(0);    
  }
  
  if(thumbButtonState == HIGH && indexButtonState == HIGH && middleButtonState == HIGH) { 
    setColorOrange();  
  } else {
    setColorOff();   
  }

  if(thumbButtonState == HIGH && indexButtonState == HIGH && ringButtonState == HIGH) { 
    setColorBrown();  
  } else {
    setColorOff();   
  }

  if(thumbButtonState == HIGH && indexButtonState == HIGH && pinkyButtonState == HIGH) { 
    setColorViolet();  
  } else {
    setColorOff();   
  }

  if(thumbButtonState == HIGH && middleButtonState == HIGH && ringButtonState == HIGH) { 
    setColorLightgreen();  
  } else {
    setColorOff();   
  }

  if(thumbButtonState == HIGH && middleButtonState == HIGH && pinkyButtonState == HIGH) { 
    setColorDarkgreen();  
  } else {
    setColorOff();   
  }

  if(thumbButtonState == HIGH && ringButtonState == HIGH && pinkyButtonState == HIGH) { 
    setColorTurkish();  
  } else {
    setColorOff();   
  }

  if(thumbButtonState == HIGH && indexButtonState == HIGH && middleButtonState == HIGH && ringButtonState == HIGH && pinkyButtonState == HIGH) {
    setRainbow();     
  } else {
    setColorOff();   
  }

  if(thumbButtonState == HIGH && pinkyButtonState == HIGH) {
    setBlink();   
  } else {
    setColorOff(); 
    analogWrite(blueLED_RGB_Red, 0);
    analogWrite(blueLED_RGB_Green, 0);
    analogWrite(blueLED_RGB_Blue, 0);   
  }
}


void setColorMix(int redValue, int greenValue, int blueValue) {
  analogWrite(RGB_Red, redValue);
  analogWrite(RGB_Green, greenValue);
  analogWrite(RGB_Blue, blueValue);   
}


void setColorBlue(int blueVal) {
  analogWrite(blueLED_RGB_Red, 0);
  analogWrite(blueLED_RGB_Green, 0);
  analogWrite(blueLED_RGB_Blue, blueVal);
}


void setColorOrange() {
  analogWrite(RGB_Red, 255);
  analogWrite(RGB_Green, 165);
  analogWrite(RGB_Blue, 0);
}
  
void setColorLightgreen() {  
  analogWrite(RGB_Red, 124);
  analogWrite(RGB_Green, 252);
  analogWrite(RGB_Blue, 0);
}

void setColorTurkish() {  
  analogWrite(RGB_Red, 64);
  analogWrite(RGB_Green, 224);
  analogWrite(RGB_Blue, 208);
}

void setColorBrown() {  
  analogWrite(RGB_Red, 244);
  analogWrite(RGB_Green, 164);
  analogWrite(RGB_Blue, 96);
}

void setColorViolet() {  
  analogWrite(RGB_Red, 235);
  analogWrite(RGB_Green, 130);
  analogWrite(RGB_Blue, 235);
}

void setColorDarkgreen() {
  analogWrite(RGB_Red, 60);
  analogWrite(RGB_Green, 179);
  analogWrite(RGB_Blue, 113);
}


void setRainbow() {
  analogWrite(blueLED_RGB_Red, 0); 
  analogWrite(blueLED_RGB_Green, 0); 
  analogWrite(blueLED_RGB_Blue, 0);
  analogWrite(RGB_Red, 255);
  analogWrite(RGB_Red, 255);
  analogWrite(RGB_Red, 255);
  delay(100); 
  analogWrite(RGB_Red, 0);
  analogWrite(RGB_Red, 0);
  analogWrite(RGB_Red, 0);
  digitalWrite(redLED, HIGH);
  delay(100); 
  digitalWrite(redLED, LOW); 
  digitalWrite(yellowLED, HIGH); 
  delay(100); 
  digitalWrite(yellowLED, LOW); 
  digitalWrite(greenLED, HIGH); 
  delay(100); 
  digitalWrite(greenLED, LOW); 
  analogWrite(blueLED_RGB_Red, 0); 
  analogWrite(blueLED_RGB_Green, 0); 
  analogWrite(blueLED_RGB_Blue, 255); 
  delay(100);    
}


void setBlink() {
  analogWrite(blueLED_RGB_Red, 0); 
  analogWrite(blueLED_RGB_Green, 0); 
  analogWrite(blueLED_RGB_Blue, 255);
  delay(80);
  analogWrite(blueLED_RGB_Red, 0);
  analogWrite(blueLED_RGB_Green, 0);
  analogWrite(blueLED_RGB_Blue, 0);
  analogWrite(RGB_Red, 255);
  analogWrite(RGB_Green, 0);
  analogWrite(RGB_Blue, 0); 
  delay(80);
  analogWrite(blueLED_RGB_Red, 255); 
  analogWrite(blueLED_RGB_Green, 0); 
  analogWrite(blueLED_RGB_Blue, 0);
  analogWrite(RGB_Red, 0);
  analogWrite(RGB_Green, 0);
  analogWrite(RGB_Blue, 0);
  delay(80);
  analogWrite(blueLED_RGB_Red, 0);
  analogWrite(blueLED_RGB_Green, 0);
  analogWrite(blueLED_RGB_Blue, 0);
  analogWrite(RGB_Red, 0);
  analogWrite(RGB_Green, 255);
  analogWrite(RGB_Blue, 0);
  delay(80);
  analogWrite(blueLED_RGB_Red, 0); 
  analogWrite(blueLED_RGB_Green, 255); 
  analogWrite(blueLED_RGB_Blue, 0);
  analogWrite(RGB_Red, 0);
  analogWrite(RGB_Green, 0);
  analogWrite(RGB_Blue, 0);
  delay(80);
  analogWrite(blueLED_RGB_Red, 0);
  analogWrite(blueLED_RGB_Green, 0);
  analogWrite(blueLED_RGB_Blue, 0);
  analogWrite(RGB_Red, 0);
  analogWrite(RGB_Green, 0);
  analogWrite(RGB_Blue, 255);
  delay(80);   
}

void setColorOff() {
  analogWrite(RGB_Red, 0); 
  analogWrite(RGB_Green, 0); 
  analogWrite(RGB_Blue, 0);   
}
