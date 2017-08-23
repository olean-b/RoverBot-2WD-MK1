#ifndef Robot_h
#define Robot_h

#include "Arduino.h"

// Class to attach a drivetrain. This is defined as two dc motors, attached to a L9110S driver board.
class Drive {
  public:
    // The constructor for a drive instance. Requires the pin numbers of the left motor port and right motor port. Note that sideA is used as the direction control, and sideB is used as the speed control
    Drive(int leftA, int leftB, int rightA, int rightB);
    // Method to set up hardware for the drive system. Call this in setup()
    void begin();

    // Moves the robot forwards at given speed. Speed must be a positive integer between 0 and 255. Controls both wheels
    void forward(int speed);
    // Moves the robot backwards at given speed. Speed must be a positive integer between 0 and 255. Controls both wheels
    void backward(int speed);
    // Does a point turn to the left (anti-clockwise) at the given speed. Speed must be a positive integer between 0 and 255
    void turnLeft(int speed);
    // Does a point turn to the right (clockwise) at the given speed. Speed must be a positive integer between 0 and 255
    void turnRight(int speed);
    // Sort of self documenting. It stops the motors
    void stop();
    // Function to control the drive train as seperate motors. Still needs to be in one function in order to ramp the speed up and down
    void motors(int speedLeftVec, int speedRightVec);

  private:
    // Varaibles to store the current speed of the left and right wheels. This is so that sudden changes in current draw can be avoided. Even with a capacitor over the motor power supply, I think I should build some software protection in as well. Also, variables for storing the motor pins
    int _leftSpeed, _rightSpeed, _leftA, _leftB, _rightA, _rightB;

    bool _leftForwards, _rightForwards;

};

#endif
