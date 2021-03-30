//Moteurs (PWM)
#define MOTOR1 3
#define MOTOR2 5
#define MOTOR3 6
#define MOTOR4 9
//Valve d'air comprim� pour la graine
#define VALVE = 1
//Capteur laser (Analogique ?)
#define LASER = 0x01 //Hexad�cimal = analogique
#define ANEMOMETRE 
#define LEDS
#define GIROUETTE

void setup() {
	pinMode(MOTOR1, OUTPUT);
	pinMode(MOTOR2, OUTPUT);
	pinMode(MOTOR3, OUTPUT);
	pinMode(MOTOR4, OUTPUT);

	pinMode(VALVE, OUTPUT);
	pinMode(LASER, INPUT);
	pinMode(ANEMOMETRE, INPUT);
	pinMode(GIROUETTE, INPUT)
	pinMode(LEDS, OUTPUT)
}

void loop() {
	
}
