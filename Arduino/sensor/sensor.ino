int sensorThumb = 0;
int sensorPointy = 1;
int sensorFucky = 2;
int sensorLongy = 3;
int sensorPinky = 4;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

}

void loop() {
  int rateThumb = analogRead(sensorThumb);
  int ratePointy = analogRead( sensorPointy);
  int rateFucky = analogRead( sensorFucky);
  int rateLongy = analogRead( sensorLongy);
  int ratePinky = analogRead( sensorPinky);

  Serial.print("Thumb = ");
 Serial.println(rateThumb);

 Serial.print("Pointy = ");
 Serial.println(ratePointy);
 
 Serial.print("Fucky = ");
 Serial.println(rateFucky);
 
 Serial.print("Longy = ");
 Serial.println(rateLongy);
 
 Serial.print("Pinky = ");
 Serial.println(ratePinky);
 delay(1500);

 Serial.println( );

 if (rateThumb <=200){
  //mix funtion skal være her 
  Serial.println("mix funktion ");
 }
 if (ratePointy <=200){
  // tænd lys for pegefinger
 }
}
