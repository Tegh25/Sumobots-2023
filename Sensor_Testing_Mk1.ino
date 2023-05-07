/*
// IR1 will be at the front left of the robot
// IR2 will be at the front right
#define IR1 8 // define what pin the IR sensor 1 is connected to on the Arduino Nano
#define IR2 7 // IR sensor 2

void setup() {
  // put your setup code here, to run once:
  pinMode(IR1, INPUT);  // define this pin as an INPUT
  pinMode(IR2, INPUT);  // define this pin as an INPUT
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val1; int val2;  //create a variable or container that holds integers
  
  val1 = digitalRead(IR1);  //save the value gotten from the sensor in our variable that holds integers
  val2 = digitalRead(IR2);  //save the value gotten from the sensor in our variable that holds integers

  if (val1)
    Serial.println("left sensor");
  if (val2) 
    Serial.println("right sensor");

  delay(2000);
}
*/