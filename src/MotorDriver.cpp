/*
 * MotorDriver.cpp - Motor Driver Library for Wiring/Arduino
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

#include "Arduino.h"
#include "MotorDriver.h"

// 2 Pin Motor Contoller constructor
MotorDriver::MotorDriver(int forward_pin, int reverse_pin){
  this->maxSpeed = 255; // max speed is used to limit the current to the motor by PWM valid values are 0 - 255
  this->speed = 255;    // speed is the current speed of the motor valid values are 0 to maxSpeed

  // Arduino pins for motor control
  this->forward_pin = forward_pin;
  this->reverse_pin = reverse_pin;
  this->speed_pin = -1;
  this->current_dir = 0;

  // setup the pins on the microcontroller:
  pinMode(this->forward_pin, OUTPUT);
  pinMode(this->reverse_pin, OUTPUT);
}

// 3 Pin Motor Controller constructor
MotorDriver::MotorDriver(int forward_pin, int reverse_pin, int speed_pin){
  this->maxSpeed = 255; // max speed is used to limit the current to the motor by PWM valid values are 0 - 255
  this->speed = 255;    // speed is the current speed of the motor valid values are 0 to maxSpeed

  // Arduino pins for motor control
  this->forward_pin = forward_pin;
  this->reverse_pin = reverse_pin;
  this->speed_pin = speed_pin;
  this->current_dir = 0;

  // setup the pins on the microcontroller:
  pinMode(this->forward_pin, OUTPUT);
  pinMode(this->reverse_pin, OUTPUT);
  pinMode(this->speed_pin, OUTPUT);
  analogWrite(this->speed_pin, this->speed);
}
// speed setter method:
void MotorDriver::setSpeed(int pctSpeed){
  pctSpeed = (pctSpeed > 100) ? 100 : (pctSpeed < 0) ? 0 : pctSpeed;
  this->speed = this->maxSpeed * pctSpeed * .01;
  directMotor();
}

// maxSpeed setter method:
void MotorDriver::setMaxSpeed(int maxSpeed){
  if(maxSpeed != this->maxSpeed){
    float curMaxSpeedRatio = (float)maxSpeed / this->maxSpeed;
    this->maxSpeed = maxSpeed; // Modify the Max Speed of the Motor
    this->speed = this->speed * curMaxSpeedRatio; // Modify the current Speed setting for the motor
    directMotor();    
  }
}

// Start moving the motor
void MotorDriver::directMotor(){
  if (speed_pin == -1){
    if (current_dir > 0){
      analogWrite(forward_pin, speed);
    }
    else if (current_dir < 0){
      analogWrite(reverse_pin, speed);
    }
  }
  else{
    analogWrite(speed_pin, speed);
  }
}

void MotorDriver::stop(void){
  if (speed_pin == -1){
    analogWrite(forward_pin, 0);
    analogWrite(reverse_pin, 0);
  }
  else{
    digitalWrite(forward_pin,0);
    digitalWrite(reverse_pin,0);
  }
}

void MotorDriver::forward(void){
  if (speed_pin == -1){
    analogWrite(forward_pin, speed);
    analogWrite(reverse_pin, 0);
  }
  else{
    digitalWrite(forward_pin,1);
    digitalWrite(reverse_pin,0);    
  }
}

void MotorDriver::reverse(void){
  if (speed_pin == -1){
    analogWrite(forward_pin, 0);
    analogWrite(reverse_pin, speed);
  }
  else{
    digitalWrite(forward_pin,0);
    digitalWrite(reverse_pin,1);    
  }
}

int MotorDriver::version(void){
  return 2;
}
