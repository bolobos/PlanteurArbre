// Numéros de broche
#define enableBridge1 2
#define MotorForward1 3
#define MotorReverse1 4
#define MotorForward2 5
#define MotorReverse2 6
#define interTOP 7
#define interDOWN 8
#define interRIGHT 9
#define interLEFT 10

// Variables
int Power = 80; //Motor velocity between 0 and 255

/*	AVANT   : ^ ^
	ARRIERE : v v 
	DROITE  : ^ v
	GAUCHE  : v ^
	Interpoler entre les différents états
*/

void setup(){
  pinMode(MotorForward1,OUTPUT);
  pinMode(MotorReverse1,OUTPUT);
  pinMode(enableBridge1,OUTPUT);
  pinMode(interTOP,INPUT);
  pinMode(interDOWN,INPUT);
  pinMode(interRIGHT,INPUT);
  pinMode(interLEFT,INPUT);
}

void loop(){
  digitalWrite(enableBridge1,HIGH); // Active pont en H

  top();
  down();
  right();
  left();
}

void top(){
    
  if (interTOP == true){
    analogWrite(MotorForward1,Power);
    analogWrite(MotorReverse1,0);
    analogWrite(MotorForward2,Power);
    analogWrite(MotorReverse2,0);
  }
}

void down(){
  
  if (interDOWN == true){
    analogWrite(MotorForward1,0);
    analogWrite(MotorReverse1,Power);
    analogWrite(MotorForward2,0);
    analogWrite(MotorReverse2,Power);
  }
}

void right(){

  if (interRIGHT == true){
    analogWrite(MotorForward1,0);
    analogWrite(MotorReverse1,Power);
    analogWrite(MotorForward1,Power);
    analogWrite(MotorReverse1,0);
  }
}

void left(){

  if (interLEFT == true){
    analogWrite(MotorForward1,Power);
    analogWrite(MotorReverse1,0);
    analogWrite(MotorForward1,0);
    analogWrite(MotorReverse1,Power);
  }
}




if (interRIGHT == true && interTOP == true){
    analogWrite(MotorForward1,Power);
    analogWrite(MotorReverse1,Power);
  } 

if (interRIGHT == true && interTOP == true){
  analogWrite(MotorForward1,Power);
  analogWrite(MotorReverse1,Power);
  } 

// TO DO---> rajouter quand deux boutons sont appuyés ...