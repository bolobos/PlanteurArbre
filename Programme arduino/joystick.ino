// Joystick arduino




//Constants
#define NUM_JOY 2
#define MIN_VAL 0
#define MAX_VAL 1023

//Parameters
const int joyPin [2] = {A0, A1};
const int joyBtn  = 2;
const int joyOffset  = 0;

//Variables
int joyVal [NUM_JOY] = {0, 0};

void setup() {
  //Init Serial USB
  Serial.begin(9600);
  Serial.println(F("Initialize System"));
  //Init Joystick
  for (int i = 0; i < NUM_JOY; i++) pinMode(joyPin[i], INPUT);
}

void loop() {
  readJoystick();
  delay(500);
}

void readJoystick( ) { /* function readJoystick */
  ////Test routine for Joystick
  for (int i = 0; i < NUM_JOY; i++) {
    joyVal[i] = analogRead(joyPin[i]);
    Serial.print(F("joy")); Serial.print(i); Serial.print(F(" : ")); Serial.println(joyVal[i]);
  }
  for (int i = 0; i < NUM_JOY; i++) {
    Serial.print(F("Conv")), Serial.print(i); Serial.print(F(" : ")); Serial.println(joyRawToPhys(joyVal[i]));
  }
  if (!digitalRead(joyBtn)) {
    Serial.println(F("Joy Button pressed"));
  }
}

int joyRawToPhys(int raw) { /* function joyRawToPhys */
  ////Joystick conversion rule
  float phys = map(raw, MIN_VAL, MAX_VAL, -100 + joyOffset, 100 + joyOffset) - joyOffset; //

  return phys;
}
