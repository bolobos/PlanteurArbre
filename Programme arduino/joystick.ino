// Joystick arduino




int dataIn[4] {0,0,0,0};
int in_byte = 0;
int array_index;

void setup() {
  Serial.begin (9600);
}

void loop() {
  if (Serial.available() > 0) {
    in_byte ==Serial.read();
    if (in_byte == (255)) {
      array_index = 0;
    }
    dataIn[array_index] = in_byte;
    array_index = array_index +1;
  }

  Serial.print (dataIn[0]);
  Serial.print(", button:");
  Serial.print(dataIn[1]);
  Serial.print(", x:");
  Serial.print(dataIn[2]);
  Serial.print(", y");
  Serial.print(dataIn[3]);
  Serial.print(", ");
  Serial.println (in_byte);

}
