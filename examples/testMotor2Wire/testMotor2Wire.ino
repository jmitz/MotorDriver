#include <MotorDriver.h>

MotorDriver testMotor(6, 5);

void setup() {
	Serial.begin(9600);
	while(!Serial); //wait for serial port to connect (needed for Leonardo)
	Serial.println("Starting Motor Sample");
}

void loop() {
	// Limit speed (voltage) of motor
	testMotor.setMaxSpeed(200);

	// Set speed of motor
	testMotor.setSpeed(150);

	Serial.println("Forward 2 seconds");

	// Start forward motion of motor
	testMotor.forward();

	delay(2000);

	Serial.println("Stop Motor 1 second");

	// Stop Motor
	testMotor.stop();

	delay(1000);

	Serial.println("Reverse 1 second");

	// Reverse Motor
	testMotor.reverse();

	delay(1000);

	testMotor.stop();

	delay(500)
}
