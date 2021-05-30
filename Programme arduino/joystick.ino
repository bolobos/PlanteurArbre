// Joystick arduino

#include <SoftwareSerial.h>

#define rxPin 11 // Broche 11 en tant que RX, à raccorder sur TX du HC-05
#define txPin 10 // Broche 10 en tant que TX, à raccorder sur RX du HC-05

SoftwareSerial SerialB(rxPin, txPin);

int dataIn[3] {0,0,0};
int in_byte = 0;
int array_index;

void setup() {

  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  SerialB.begin (38400);
  Serial.begin(38400);
}

void loop() {
  
  int i = 0;
  char someChar[32] = {0};
  // when characters arrive over the serial port...
  if(Serial.available()) {
    do{
      someChar[i++] = Serial.read();
    delay(3);
    }while (Serial.available() > 0);
    mySerial.println(someChar);
    Serial.println(someChar);
    }
  while(mySerial.available())
 Serial.print((char)mySerial.read());

  Serial.print(dataIn[1]);
  Serial.print(", x:");
  Serial.print(dataIn[2]);
  Serial.print(", y");
  Serial.print(dataIn[3]);
  Serial.print(", ");
  Serial.println (in_byte);

}
