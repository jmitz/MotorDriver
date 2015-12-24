/*
 * MotorDriver.h - Motor Driver Library for Wiring/Arduino
 *
 * Original library        (0.2)   by Jeff Mitzelfelt
 *
 * Drives an analog DC motor using either a two or three
 * pin motor controller.
 *
 * 3 Pin Motor Controller
 * Forward pin - digital
 * Reverse pin - digital
 * Speed pin   - digital with PWM
 *
 * 2 Pin Motor Controller
 * Forward pin - digital with PWM
 * Reverse pin - digital with PWM 
 */

// ensure this library description is only included once
#ifndef MotorDriver_h
#define MotorDriver_h

#include "Arduino.h"

// library interface description
class MotorDriver {
  public:
  	// constructors:
    // 2 Pin Motor Controller
  	MotorDriver(int forward_pin, int reverse_pin);

    // 3 Pin Motor Controller
    MotorDriver(int forward_pin, int reverse_pin, int speed_pin);
  	// speed setter method:
  	void setSpeed(int speed);

  	// maxSpeed setter method:
  	void setMaxSpeed(int maxSpeed);

    void directMotor();

  	void stop();

  	void forward();

  	void reverse();

  	int version();

  private:
    int maxSpeed;    // Maximum speed value 0 to 255 used to set the maximum voltage for the motor
    int speed;       // Set motor speed value from 0 to maxSpeed
    int forward_pin; // Pin used to determine forward motor direction
    int reverse_pin; // Pin used to determine reverse motor direction
    int speed_pin;   // Pin used to determine speed
    int current_dir; // Direction of motor movement
};

#endif