#include "Arduino.h"
#include "Robot.h"

/* DRIVE SYSTEM */

// Drive constructor
Drive::Drive(int leftA, int leftB, int rightA, int rightB){
  _leftA = leftA;
  _leftB = leftB;
  _rightA = rightA;
  _rightB = rightB;
  _leftForwards = false;
  _rightForwards = false;
}

// Set up hardware for drive system, call this in setup()
void Drive::begin(){
  pinMode(_leftA, OUTPUT);
  pinMode(_leftB, OUTPUT);
  pinMode(_rightA, OUTPUT);
  pinMode(_rightB, OUTPUT);
}

// The below functions drive the robot in the suggested direction. They are passed speed, an integer between 0 and 255.
void Drive::forward(int speed){
  motors(speed, speed);
}

void Drive::backward(int speed){
  motors((-1 * speed), (-1 * speed));
}

// The functions below peform a point turn, at the given speed (Integer between 0 and 255). Arc turns can be initiated by calling left() and right() individually.
void Drive::turnLeft(int speed){
  motors((-1 * speed), speed);
}

void Drive::turnRight(int speed){
  motors(speed, (-1 * speed));
}

// this one stops the motors. Come as a surprise to anyone?
void Drive::stop(){
  // Write both terminals on both motors to high
  digitalWrite(_leftA, HIGH);
  digitalWrite(_leftB, HIGH);

  digitalWrite(_rightA, HIGH);
  digitalWrite(_rightB, HIGH);

  // Store that neither motor is moving
  _leftSpeed = 0;
  _rightSpeed = 0;
}

// Function to control the motors seperately. However, motors need to be controlled by one function to facilitate rampinig the speeds up and down. A negative speed turns the motor backwards
void Drive::motors(int speedLeftVec, int speedRightVec){
  // Get the absolute speed values
  int speedLeft = abs(speedLeftVec);
  int speedRight = abs(speedRightVec);

  // If there is a sudden change in direction, turn off the motor
  if((speedLeftVec > 0) != _leftForwards){
    digitalWrite(_leftA, LOW);
    digitalWrite(_leftB, LOW);
    _leftSpeed = 0;
  }

  if((speedRightVec > 0) != _rightForwards){
    digitalWrite(_rightA, LOW);
    digitalWrite(_rightB, LOW);
    _rightSpeed = 0;
  }

  // Get a boolean as to whether each motor is forwards or backwards. true is forwards, false is backwards
  _leftForwards = (speedLeftVec > 0);
  _rightForwards = (speedRightVec > 0);

  // When left is forwards, _leftA is HIGH, while when it going backwards, _leftA is LOW
  digitalWrite(_leftA, (_leftForwards ? HIGH : LOW));
  digitalWrite(_rightA, (_rightForwards ? HIGH : LOW));

  // Ramp the speeds to the desired rates, so as not to cause sudden changes and fry shit
  while (_leftSpeed != speedLeft || _rightSpeed != speedRight){
    // Adjust the speed of the motor, if it is not already at the desired speed
    if(_leftSpeed != speedLeft){
      _leftSpeed += (_leftSpeed > speedLeft ? -1 : 1);
      analogWrite(_leftB, (_leftForwards ? 255 - _leftSpeed : _leftSpeed));
    }
    if(_rightSpeed != speedRight){
      _rightSpeed += (_rightSpeed > speedRight? -1 : 1);
      analogWrite(_rightB, (_rightForwards ? 255 - _rightSpeed : _rightSpeed));
    }
    delay(1);
  }
  analogWrite(_leftB, (_leftForwards ? 255 - _leftSpeed : _leftSpeed));
  analogWrite(_rightB, (_rightForwards ? 255 - _rightSpeed : _rightSpeed));
}
