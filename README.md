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

### Regular Turn:
A regular turn is when `only one wheel` is powered. 
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

### Soft Turns:
A soft turn is when `both wheels are going forward` but one drives slower than the other. This causes the robot to turn while stil moving forward.
```
void turnRightSoft(const uint8_t speed, const uint8_t tightness, const ExitCondition exitCondition);
void turnLeftSoft(const uint8_t speed, const uint8_t tightness, const ExitCondition exitCondition);
```
Functionality:
- Turn Right Soft: Powers the left motor forward and the right motor at a lower speed.
- Turn Left Soft: Powers the right motor forward and the left motor at a lower speed.

Parameters:
- Speed: controls the speed of the motor (255 is max speed going forward)
- Tightness: controls how tight the turn is (255 means straight forward and 0 means turn on the spot)

Note: It is not recommand to set a soft turns tightness to 255 or 0. This is for the sake of clarity. Instead use the forward and regular turn commands respectively. 

### Hard Turn:
A hard turn is when `one wheel goes forward and the other goes backwards`. 
```
void turnRightHard(const uint8_t speed, const uint8_t tightness, const ExitCondition exitCondition);
void turnLeftHard(const uint8_t speed, const uint8_t tightness, const ExitCondition exitCondition);
```
Functionality:
- Turn Right Hard: Powers the left motor forward and the right motor backwards
- Turn Left Hard: Powers the right motor forward and the left motor backwards

Parameters:
- Speed: controls the speed of the motor (255 is max speed going forward)
- Tightenss: controls the speed of the other motor (255 is max speed in reverse)
- Exit Condition: When the program stops performing the command.

# Command Cheat Sheet

Note: all commands can be seen in the `commandManager.h` file.
```
//Used to tell the robot when it should start looking for fish.
void checkForPonds(const bool check);

//Linear motion commands
void forward(const uint8_t speed, const ExitCondition exitCondition);
void backward(const uint8_t speed, const ExitCondition exitCondition);

//regular turning commands
void turnRight(const uint8_t speed, const ExitCondition exitCondition);
void turnLeft(const uint8_t speed, const ExitCondition exitCondition);

//hard turning commands
void turnRightHard(const uint8_t speed, const uint8_t tightness, const ExitCondition exitCondition);
void turnLeftHard(const uint8_t speed, const uint8_t tightness, const ExitCondition exitCondition);

//soft turning commands
void turnRightSoft(const uint8_t speed, const uint8_t tightness, const ExitCondition exitCondition);
void turnLeftSoft(const uint8_t speed, const uint8_t tightness, const ExitCondition exitCondition);
```

# Example Code

Disclaimer: Values are arbitrary and purely for demonstration.
```
void setup() {
  lockPins();

  forward(255, {LINES, 3});
  turnLeft(255, {TIME, 500});
  backward(255, {TIME, 1000});
  turnRightHard(255, 255, {TIME, 500});
  forward(255, {TIME, 2000});
  
  checkForPonds(true);
  turnLeftSoft(255, 255, {TIME, 500});
  checkForPonds(false);
  
  Serial.begin(9600);

  //delay is detected so that all pins can fully reset 
  //when reset button is pressed.
  delay(100);

  initPins();
}

void loop() {
  updateLineSensor();
  executeCmds();
}
```
