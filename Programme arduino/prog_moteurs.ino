//Parameters
const int input_voltage  = 9;//V
const int nominal_voltage  = 12;////V
const int MAX_SPEED  = 255;
const int directionA  = 12;
const int directionB  = 13;
const int brakeA  = 9;
const int brakeB  = 8;
const int speedA  = 3;
const int speedB  = 11;
const int in2  = A2;
const int in3  = A3;

#define JOY_X 14
#define JOY_Y 15

void setup() {
 //Init Serial USB
 Serial.begin(9600);
 Serial.println(F("Initialize System"));
 //Init Motor Shield
 pinMode(directionA, OUTPUT); //Initiates Motor Channel A pin
 pinMode(brakeA, OUTPUT); //Initiates Brake Channel A pin
 pinMode(directionB, OUTPUT); //Initiates Motor Channel B pin
 pinMode(brakeB, OUTPUT); //Initiates Brake Channel B pin
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
  digitalWrite(directionA, invertedX);
  digitalWrite(directionB, invertedY);
  digitalWrite(brakeA, LOW);   //Disengage the Brake for Channel A
  digitalWrite(brakeB, LOW);   //Disengage the Brake for Channel B

  analogWrite(speedA, abs(scaledX));
  analogWrite(speedB, abs(scaledY));
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
 digitalWrite(brakeA, HIGH);   //Engage the Brake for Channel A
 analogWrite(speedA, 0);
 digitalWrite(brakeB, HIGH);   //Engage the Brake for Channel B
 analogWrite(speedB, 0);
}

double getPhase(int x, int y, int mod) {
  if(y > 0)
    return PI / 2 -  atan(x / y);
  else if(y < 0)
    return PI / 2 - atan(x/ y)
}
