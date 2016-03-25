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
  int left = readSensor(leftLDR, leftLed);
  int right = readSensor(rightLDR, rightLed);
  
  if((left >= 20) && (right >= 20))
  {
    forward();
  }
  
  else if (left >= 20 && right < 20)
  {
    backward();
    delay(750);
    turnLeft();
    delay(millis()%2000+100);
  }
  
  else if (left < 20 && right >= 20)
  {
    backward();
    delay(750);
    turnRight();
    delay(millis()%2000+100);
  }
  
  else 
  {
    backward();
    delay(millis()%1000);
    if(millis()%2)
    {
      turnLeft();
      delay(millis()%5000);
    }
    else
    {
      turnRight();
      delay(3000);
    }
  }
}

int readSensor(int ldr, int led)
{
  digitalWrite(led, HIGH);
  delay(10);
  int reading1 = analogRead(ldr);
  digitalWrite(led, LOW);
  delay(10);
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
