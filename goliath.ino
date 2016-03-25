#include <Servo.h>

#define leftLDR A0
#define rightLDR A1
#define leftLed 2
#define rightLed 3

Servo leftServo;
Servo rightServo;

void setup() {
  leftServo.attach(11);
  rightServo.attach(10);

  pinMode(leftLDR, INPUT);
  pinMode(rightLDR, INPUT);
  pinMode(leftLed, OUTPUT);
  pinMode(rightLed, OUTPUT);

  digitalWrite(leftLed, LOW);
  digitalWrite(rightLed, LOW);
}

void loop() {
  delay(50);
  if((readSensor(leftLDR, leftLed) >= 20) && (readSensor(rightLDR, rightLed) >= 20))
  {
    forward();
  }
  
  else if ((readSensor(leftLDR, leftLed) >= 20) && (readSensor(rightLDR, rightLed) < 20))
  {
    turnLeft();
    delay(500);
  }
  
  else if ((readSensor(leftLDR, leftLed) < 20) && (readSensor(rightLDR, rightLed) >= 20))
  {
    turnRight();
    delay(500);
  }
  
  else 
  {
    backward();
    delay(1000);
    if(millis()%2)
    {
      turnLeft();
      delay(2500);
    }
    else
    {
      turnRight();
      delay(2500);
    }
  }
}

int readSensor(int ldr, int led)
{
  digitalWrite(led, HIGH);
  delay(20);
  int reading1 = analogRead(ldr);
  digitalWrite(led, LOW);
  delay(20);
  int reading2 = analogRead(ldr);
  
  return (reading1-reading2);
}

void forward()
{
  leftServo.write(0);
  rightServo.write(180);
}

void turnLeft()
{
  leftServo.write(180);
  rightServo.write(180);
}

void turnRight()
{
  leftServo.write(0);
  rightServo.write(0);
}

void backward()
{
  leftServo.write(180);
  rightServo.write(0);
}
