// Include Libs
#include <Servo.h>
#include <NewPing.h>

// L298N Pins
const int motor1Forward = 7;
const int motor1Reverse = 6;
const int motor2Forward = 4;
const int motor2Reverse = 5;

// Servo Pin
const int servoPin = 10;

//  Servo Positions
const int leftPos = 130;
const int centerPos = 90;
const int rightPos = 40;

// Sensor Pins (Analog)
#define trigPin A1
#define echoPin A2

#define maxDist 200
boolean movingForward = false;
int distance = 100;

NewPing sonar(trigPin, echoPin, maxDist);
Servo servoMotor;

void setup()
{
  pinMode(motor2Forward, OUTPUT);
  pinMode(motor1Forward, OUTPUT);
  pinMode(motor1Reverse, OUTPUT);
  pinMode(motor2Reverse, OUTPUT);

  servoMotor.attach(servoPin);
  
  delay(2000);
  servoMotor.write(centerPos);
  delay(3000);
  servoMotor.write(leftPos);
  delay(3000);
  servoMotor.write(centerPos);
  delay(3000);
  servoMotor.write(rightPos);
  delay(3000);
  servoMotor.write(centerPos);

  delay(2000);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
}

void loop()
{
  int distanceRight = 0;
  int distanceLeft = 0;
  delay(50);

  if (distance <= 20)
  {
    stopMoving();
    delay(300);
    moveReverse();
    delay(400);
    stopMoving();
    delay(300);
    distanceRight = lookRight();
    delay(300);
    distanceLeft = lookLeft();
    delay(300);

    if (distance >= distanceLeft)
    {
      turnRight();
      stopMoving();
    }
    else
    {
      turnLeft();
      stopMoving();
    }
  }
  else
  {
    moveForward();
  }
  distance = readPing();
}

int readPing()
{
  delay(70);
  int cm = sonar.ping_cm();
  if (cm == 0)
  {
    cm = 250;
  }
  return cm;
}

int lookLeft()
{
  servoMotor.write(leftPos);
  delay(500);
  int distance = readPing();
  delay(100);
  servoMotor.write(centerPos);
  return distance;
}

int lookRight()
{
  servoMotor.write(rightPos);
  delay(500);
  int distance = readPing();
  delay(100);
  servoMotor.write(centerPos);
  return distance;
}

void stopMoving()
{
  digitalWrite(motor2Forward, LOW);
  digitalWrite(motor1Forward, LOW);
  digitalWrite(motor2Reverse, LOW);
  digitalWrite(motor1Reverse, LOW);
}

void moveForward()
{
  if (!movingForward)
  {
    movingForward = true;

    digitalWrite(motor1Forward, HIGH);
    digitalWrite(motor2Forward, HIGH);

    digitalWrite(motor1Reverse, LOW);
    digitalWrite(motor2Reverse, LOW);
  }
}

void moveReverse()
{
  movingForward = false;

  digitalWrite(motor1Reverse, HIGH);
  digitalWrite(motor2Reverse, HIGH);

  digitalWrite(motor1Forward, LOW);
  digitalWrite(motor2Forward, LOW);
}

void turnLeft()
{
  digitalWrite(motor1Reverse, HIGH);
  digitalWrite(motor2Forward, HIGH);

  digitalWrite(motor1Forward, LOW);
  digitalWrite(motor2Reverse, LOW);

  delay(500);

  digitalWrite(motor1Forward, HIGH);
  digitalWrite(motor2Forward, HIGH);

  digitalWrite(motor1Reverse, LOW);
  digitalWrite(motor2Reverse, LOW);
}

void turnRight()
{
  digitalWrite(motor1Forward, HIGH);
  digitalWrite(motor2Reverse, HIGH);

  digitalWrite(motor1Reverse, LOW);
  digitalWrite(motor2Forward, LOW);

  delay(500);

  digitalWrite(motor1Forward, HIGH);
  digitalWrite(motor2Forward, HIGH);

  digitalWrite(motor1Reverse, LOW);
  digitalWrite(motor2Reverse, LOW);
}