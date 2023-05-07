
// just changed speed and turning time

// left motor or wheel
#define IN1 9 //in1 at pin D6
#define IN2 6 //in2 at pin D9

// right motor or wheel
#define IN3 10 //in3 at pin D11
#define IN4 11 //in4 at pin D10

// IR1 will be at the front left of the robot
// IR2 will be at the front right
#define IR1 8 // define what pin the IR sensor 1 is connected to on the Arduino Nano
#define IR2 7 // IR sensor 2

void setup() {
  // setup code

  pinMode(IN1, OUTPUT); // here we tell the Arduino IN1 is an OUTPUT pin
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(IR1, INPUT);  // define this pin as an INPUT
  pinMode(IR2, INPUT);  // define this pin as an INPUT

  pinMode(2, OUTPUT); // ultrasonic sensor output
  pinMode(4, INPUT); // ultrasonic sensor input
  Serial.begin(9600);

  delay(5000);
}

void loop() {
  // loop/main code

  int speed = 225; // standard speed of robot
  int detectIf = 0; // 1 if detecting white, 0 if detecting black
  int detectionLeft;  // integer to store IR1 input
  int detectionRight;  // integer to store IR2 input

  // int speed;
  // long dist = ultrasonicDetection(detectIf);
  // if (dist <= 6) {
  //   speed = 200;
  //   Serial.println("Speed 200");
  // }
  // else {
  //   speed = 100;
  //   Serial.println("Speed 100");
  // }
  
  //moves wheel 1 forward
  analogWrite(IN1, speed);
  analogWrite(IN2, 0);

  //moves wheel 2 forward
  analogWrite(IN3, speed);
  analogWrite(IN4, 0);
  
  detectionLeft = digitalRead(IR1);  // save the value gotten from the IR1 sensor in our variable that holds integers
  //Serial.println(detectionLeft + " detected on the left");  // print out the value saved in our variable on the Serial monitor 

  detectionRight = digitalRead(IR2);  // save the value gotten from the IR1 sensor in our variable that holds integers
  //Serial.println(detectionRight + " detected on the right");  // print out the value saved in our variable on the Serial monitor 

  if (detectionLeft == detectIf) {
    Serial.println("Detected line on the left");
    leftLineDetection();
  }
  else if (detectionRight == detectIf) {
    Serial.println("Detected line on the right");
    rightLineDetection();
  }

  delay(0.5); // wait for 0.001 seconds
  
}

void leftLineDetection() {
    //stops wheel 1
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  //stops wheel 2
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  delay(200); // stop for 0.2 seconds

    //moves wheel 1 backward
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  //moves wheel 2 backward
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  delay(350); // move back for 0.45 seconds

    //moves wheel 1 forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  //moves wheel 2 backward
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  delay(500); // turn right for .5 seconds

  // moves wheel 1 forward again
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  // moves wheel 2 forward again
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void rightLineDetection() {
  //stops wheel 1
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  //stops wheel 2
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  delay(200); // stop for 0.2 seconds

    //moves wheel 1 backward
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  //moves wheel 2 backward
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  delay(350); // move back for 0.75 seconds

  //moves wheel 1 backward
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  //moves wheel 2 forward
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  delay(500); // turn right for .5 seconds

  // moves wheel 1 forward again
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  // moves wheel 2 forward again
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// not working right now :(
long ultrasonicDetection(int detectIf) {
  /*
  digitalWrite(2, LOW);
  delayMicroseconds(4);
  */
  int detectionLeft;  // integer to store IR1 input
  int detectionRight;  // integer to store IR2 input
  digitalWrite(2, HIGH);

  delayMicroseconds(2);
  detectionLeft = digitalRead(IR1);
  detectionRight = digitalRead(IR2);
  if (detectionLeft == detectIf || detectionRight == detectIf) {
    digitalWrite(2, LOW);
    return 100;
  }

  delayMicroseconds(2);
  detectionLeft = digitalRead(IR1);
  detectionRight = digitalRead(IR2);
  if (detectionLeft == detectIf || detectionRight == detectIf) {
    digitalWrite(2, LOW);
    return 100;
  }

  delayMicroseconds(2);
  detectionLeft = digitalRead(IR1);
  detectionRight = digitalRead(IR2);
  if (detectionLeft == detectIf || detectionRight == detectIf) {
    digitalWrite(2, LOW);
    return 100;
  }

  delayMicroseconds(2);
  detectionLeft = digitalRead(IR1);
  detectionRight = digitalRead(IR2);
  if (detectionLeft == detectIf || detectionRight == detectIf) {
    digitalWrite(2, LOW);
    return 100;
  }

  delayMicroseconds(2);
  detectionLeft = digitalRead(IR1);
  detectionRight = digitalRead(IR2);
  if (detectionLeft == detectIf || detectionRight == detectIf) {
    digitalWrite(2, LOW);
    return 100;
  }

  digitalWrite(2, LOW);

  long t = pulseIn(4, HIGH); // input pulse and save it into a variable

  return t / 74 / 2; // time converted to inches
}