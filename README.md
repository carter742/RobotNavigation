# About
This codes purpose is to simplify the work required to write nagivation code for a two wheel drive robot.

# Useful Information
- The `pin.h` file contains all the pin definitions.
- There are currently two different command end conditions. They are `TIME` and `LINE`

# Tutorial
Here is an outline of how the codes basic functionality.

## Basic Command Structure
```
void forward(const uint8_t speed, const ExitCondition exitCondition);
```
Here is the basic format of a command. Almost all the commands (expect for one) start by defining the `motor speed`. This value goes from 0-265.

The last part is the `exit condition`. This part tells the program what condition needs to be met before moving onto the next command. Every function
has been designed so the last parameter is the `exit condition`. 

There are currently two `exit conditions`:
1)  TIME: mesuread in milliseconds
3)  LINES: the number of lines crossed


## Here is an example of a `time based` command:
```
forward(255, {TIME, 1000});
```
Here we move forward at the maximum speed and we wait 1000 milliseconds before we stop. 


## Here is an example of a `line based` command:
```
forward(100, {LINES, 3});
```
Here we move forward at a speed of 100 and we wait until 3 lines are detected before we stop. 

## Turning Commands
There are three different turning commands. 

### Turning
A regular turn is when `only one wheel` is powered. This can be done by calling one of the functions below. 
```
void turnRight(const uint8_t speed, const ExitCondition exitCondition);
void turnLeft(const uint8_t speed, const ExitCondition exitCondition);
```
Functionality:
- Turn Right: powers left motor
- Turn Left: powers right motor

Parameters:
- Speed: controls the motor speed (255 is max speed)
- Exit Condition: When the program stops performing the command.

### Precise Turning
For more control over turning these function overloads can be used:
'''
void turnRight(const uint8_t speedL, const int16_t speedR, const ExitCondition exitCondition);
void turnLeft(const uint8_t speedR, const int16_t speedL, const ExitCondition exitCondition);
'''
Functionality:
-  The first paramemter controls the speed.
-  The second controls the tightness of the turn by varying the speed of the other motor. If the value is negative the motor will go in reverse for extra tight turns. (supports -255 to 255)

Parameters:
- First parameter: Controls the speed for the turn.
- Second parameter: Controls how tight the turn is.
- Exit Condition: When the program stops performing the command.

# Example Code

Disclaimer: Values are arbitrary and purely for demonstration.
```
void setup() {
  lockPins();

  forward(255, {LINES, 3});
  turnLeft(255, {TIME, 500});
  backward(255, {TIME, 1000});
  turnRight(255, -255, {TIME, 500});
  forward(255, {TIME, 2000});
  
  detectColor(true);
  turnLeft(255, 200, {TIME, 500});
  detectColor(false);
  
  Serial.begin(9600);

  //delay is detected so that all pins can fully reset 
  //when reset button is pressed.
  delay(100);

  initPins();
}

void loop() {
  updateLineSensor();

  if (isDetectingColor()) {
    Serial.println("DETECTING COLOR");
  }
  
  executeCmds();
}
```

# Experimental Features
- lockPins(): this has not been tested but it could stop the arduino from starting the motors on code upload.
- detectColor(): Currently only toggles a flag to check for ponds. Does not actaully do anything else yet.

# To-Do:
1) Colour Sensor Code
2) Arm Motor Code
3) Turning in reverse
4) Refine Line Sensor Code
