//Parameters
#define input_voltage 9//V
#define nominal_voltage 12////V
#define MAX_SPEED 255
#define DIRECTION_A 12
#define DIRECTION_B 13
#define BRAKE_A 9
#define BRAKE_B 8
#define SPEED_A 3
#define SPEED_B 11

#define JOY_X 14
#define JOY_Y 15

void setup() {
 //Init Serial USB
 Serial.begin(9600);
 Serial.println(F("Initialize System"));
 //Init Motor Shield
 pinMode(DIRECTION_A, OUTPUT); //Initiates Motor Channel A pin
 pinMode(BRAKE_A, OUTPUT); //Initiates Brake Channel A pin
 pinMode(DIRECTION_B, OUTPUT); //Initiates Motor Channel B pin
 pinMode(BRAKE_B, OUTPUT); //Initiates Brake Channel B pin
}

void loop() {
  int valX = analogRead(JOY_X);
  int valY = analogRead(JOY_Y);
  int* v = getValue(valX, valY);
  int scaledX = v[0], scaledY = v[1];
  bool invertedX = scaledX < 0;
  bool invertedY = scaledY < 0;
  //Serial.println(valY);
  Serial.print(valX);
  Serial.print(" ");
  Serial.println(valY);
  digitalWrite(DIRECTION_A, invertedX);
  digitalWrite(DIRECTION_B, invertedY);
  digitalWrite(BRAKE_A, LOW);   //Disengage the Brake for Channel A
  digitalWrite(BRAKE_B, LOW);   //Disengage the Brake for Channel B

  analogWrite(SPEED_A, abs(scaledX));
  analogWrite(SPEED_B, abs(scaledY));
  delete v;
}

int* getValue(int valX, int valY) {
  int scaledX = constrain(map(valX, 273, 750, -MAX_SPEED, MAX_SPEED), -MAX_SPEED, MAX_SPEED);
  int scaledY = constrain(map(valY, 273, 750, -MAX_SPEED, MAX_SPEED), -MAX_SPEED, MAX_SPEED);
  int* result = new int[2];
  int x, y;
  x = scaledX;
  y = scaledY;

  int mod = sqrt(x * x + y * y);
  double phase = getPhase(x, y, mod);
  phase += PI / 4.0;
  /*Serial.print(x);
  Serial.print(" ");
  Serial.println(y);*/
  x = cos(phase) * mod;
  y = sin(phase) * mod;
  /*Serial.print(x);
  Serial.print(" ");
  Serial.println(y);*/

  if(valY < 0) {
    result[0] = x;
    result[1] = y;
  } else {
    result[0] = y;
    result[1] = x;
  }
  
  return result;
}

void dcStop() { /* function dcStop */
 //// stop motors A and B
 digitalWrite(BRAKE_A, HIGH);   //Engage the Brake for Channel A
 analogWrite(SPEED_A, 0);
 digitalWrite(BRAKE_B, HIGH);   //Engage the Brake for Channel B
 analogWrite(SPEED_B, 0);
}

double getPhase(int x, int y, int mod) {
  if(y > 0)
    return PI / 2 -  atan(x / y);
  else if(y < 0)
    return PI / 2 - atan(x/ y)
}
