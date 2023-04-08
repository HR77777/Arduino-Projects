const int sensorPin = A0;
const float baseTemp = 22.0; 

void setup() {
  Serial.begin(9600); // opens a serial port
  //Set the red LEDs to be off by default. 
  for (int pinNum = 2; pinNum < 5; pinNum++) {
    pinMode(pinNum, OUTPUT);
    digitalWrite(pinNum, LOW);
  }
}

void loop() {
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);
  float voltage = (sensorVal/1024.0)*5.0;
  Serial.print(", Volts: ");
  Serial.print(voltage);
  float temp = (voltage - .5) * 100;
  Serial.print(", degrees C: ");
  Serial.println(temp);
  if (temp < baseTemp+2) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if (temp < baseTemp+4) {
      digitalWrite(2, HIGH);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
  } else if (temp < baseTemp+6) {
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
  } else {
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
  }
  delay(1);
}
