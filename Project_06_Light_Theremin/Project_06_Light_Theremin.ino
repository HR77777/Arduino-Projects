int sensorVal;
int sensorLow = 1023;
int sensorHigh = 0;
const int ledPin = 13; //On-board LED connected to Pin 13

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH); //Turn on LED
  //millis() gives time in ms since the Arduino was last powered on. Loop for 5 seconds. 
  while (millis() < 5000) { 
    sensorVal = analogRead(A0); //Read the value of the phototransistor sensor 
    //Calibrate the sensor's maximum and minimum values 
    if (sensorVal > sensorHigh) {
      sensorHigh = sensorVal;
    }
    if (sensorVal < sensorLow) {
      sensorLow = sensorVal; 
    }
  }
  digitalWrite(ledPin, LOW); //Turn off LED
}

void loop() {
  sensorVal = analogRead(A0); //Read value from the phototransistor sensor 
  int pitch = map(sensorVal, sensorLow, sensorHigh, 50, 4000); //Map the sensor value to a frequency 
  tone(8, pitch, 20); //Piezo connected to pin 8, play note for 20 ms 
  delay(10); 
}
