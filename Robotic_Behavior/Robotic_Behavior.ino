// Araf Ahmed Team Software Lead - This program provides instructions to the arduino car robot, outlining its behavior
// The intended environment for which this car robot is programmed is an arbitrary 'racetrack' outlined by a thin, dark colored line
// which the robot will detect using two IR sensors identifying direction of deviations to perform autonomous course-correction

// Initializing digital pins wired to motors
int in1 = 4; // variable names for the L298N
int in2 = 5; // variable names for the L298N
int in3 = 9; // variable names for the L298N
int in4 = 10; // variable names for the L298N

// Initializing IR sensors
int irgreen = 2; // variable name for left IR sensor - identified by color of wiring
int irblue = 7; // variable name for right IR sensor - identified by color of wiring

void setup() {

  // Initializing IR sensors as inputs
  pinMode (irgreen, INPUT) ;
  pinMode (irblue, INPUT) ;
  
  // Initializing all L298N digital pins as outputs
  pinMode (in1, OUTPUT);
  pinMode (in2, OUTPUT);
  pinMode (in3, OUTPUT);
  pinMode (in4, OUTPUT);
  
}


void loop() {

  int greenstatus = digitalRead(irgreen); // read the status of left IR sensor
  int bluestatus = digitalRead(irblue); // read the status of right IR sensor

  if (bluestatus == 1) {
    // if right sensor detects track line, left deviation is detected
    // perform right turn supplying power such that left motors move forward and right motors move backward
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    delay(1);
  } else {
    // continue forward if no such deviation detected
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  }


  if (greenstatus == 1) {
    // right deviation detected
    // perform left turn - configure right motors to forward movement and left motors to backward movement
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    delay(1);
  } else {
    // continue forward if no such deviation detected
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  }
  
}
