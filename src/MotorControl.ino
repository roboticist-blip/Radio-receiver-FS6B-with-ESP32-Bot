// Fs6b receiver channels
const int channel1Pin = 13;  // Channel 1 (Left/Right)
const int channel3Pin = 12;  // Channel 3 (Forward/Backward)

// L298N motor driver pins
const int motorAIn1 = 14;  // IN1
const int motorAIn2 = 27;  // IN2
const int motorBIn1 = 26;  // IN3
const int motorBIn2 = 25;  // IN4

// Speed pin always HIGH (enable pins assumed tied HIGH or not used)

unsigned long duration1;
unsigned long duration3;

void setup() {
  Serial.begin(115200);

  pinMode(motorAIn1, OUTPUT);
  pinMode(motorAIn2, OUTPUT);
  pinMode(motorBIn1, OUTPUT);
  pinMode(motorBIn2, OUTPUT);
}

void loop() {
  duration1 = pulseIn(channel1Pin, HIGH, 25000);
  duration3 = pulseIn(channel3Pin, HIGH, 25000);
   
   Serial.print("Ch1:"); Serial.print(duration1);
   Serial.print("    Ch3:"); Serial.println(duration3);
  if(duration1 == 0) duration1 = 1500;
  if(duration3 == 0) duration3 = 1500;

  controlMotors(duration1, duration3);

  delay(20);
}

void controlMotors(int ch1, int ch3) {
  /*
  Channel 1 controls Left/Right:
    - Left if below 1450
    - Right if above 1550
  Channel 3 controls Forward/Backward:
    - Forward if above 1550
    - Backward if below 1450
  Neutral zones (1450-1550) mean stop on respective axis.
  */

  bool left = (ch1 < 1450);
  bool right = (ch1 > 1550);
  bool forward = (ch3 > 1550);
  bool backward = (ch3 < 1450);

  if(forward && !left && !right) { 
    // Forward
    motorForward();
  }
  else if(backward && !left && !right) {
    // Backward
    motorBackward();
  }
  else if(left && !forward && !backward) {
    // Turn Left (rotate motors in opposite directions)
    motorLeft();
  }
  else if(right && !forward && !backward) {
    // Turn Right (rotate motors in opposite directions)
    motorRight();
  }
  else if(forward && left) {
    motorForwardLeft();
  }
  else if(forward && right) {
    motorForwardRight();
  }
  else if(backward && left) {
    motorBackwardLeft();
  }
  else if(backward && right) {
    motorBackwardRight();
  }
  else {
    motorStop();
  }
}

void motorForward() {
  digitalWrite(motorAIn1, HIGH);
  digitalWrite(motorAIn2, LOW);
  digitalWrite(motorBIn1, HIGH);
  digitalWrite(motorBIn2, LOW);
}

void motorBackward() {
  digitalWrite(motorAIn1, LOW);
  digitalWrite(motorAIn2, HIGH);
  digitalWrite(motorBIn1, LOW);
  digitalWrite(motorBIn2, HIGH);
}

void motorLeft() {
  digitalWrite(motorAIn1, LOW);
  digitalWrite(motorAIn2, HIGH);
  digitalWrite(motorBIn1, HIGH);
  digitalWrite(motorBIn2, LOW);
}

void motorRight() {
  digitalWrite(motorAIn1, HIGH);
  digitalWrite(motorAIn2, LOW);
  digitalWrite(motorBIn1, LOW);
  digitalWrite(motorBIn2, HIGH);
}

void motorForwardLeft() {
  digitalWrite(motorAIn1, HIGH);
  digitalWrite(motorAIn2, LOW);
  digitalWrite(motorBIn1, LOW);
  digitalWrite(motorBIn2, LOW);
}

void motorForwardRight() {
  digitalWrite(motorAIn1, LOW);
  digitalWrite(motorAIn2, LOW);
  digitalWrite(motorBIn1, HIGH);
  digitalWrite(motorBIn2, LOW);
}

void motorBackwardLeft() {
  digitalWrite(motorAIn1, LOW);
  digitalWrite(motorAIn2, HIGH);
  digitalWrite(motorBIn1, LOW);
  digitalWrite(motorBIn2, LOW);
}

void motorBackwardRight() {
  digitalWrite(motorAIn1, LOW);
  digitalWrite(motorAIn2, LOW);
  digitalWrite(motorBIn1, LOW);
  digitalWrite(motorBIn2, HIGH);
}

void motorStop() {
  digitalWrite(motorAIn1, LOW);
  digitalWrite(motorAIn2, LOW);
  digitalWrite(motorBIn1, LOW);
  digitalWrite(motorBIn2, LOW);
}
