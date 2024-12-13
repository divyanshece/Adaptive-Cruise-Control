#include <LiquidCrystal.h>
#include <LCD_I2C.h>

LCD_I2C lcd(0x27, 16, 2);
const int trigPin = 10;
const int echoPin = 11;
long duration;
int distanceCm, distanceInch;

// Motor Pins 
int ena = 3;
int in1 = 5;
int in2 = 4;

int in3 = 6;
int in4 = 7;
int enb = 9;

// Motor speed variables
int enaSpeed = 255; // Initial speed for motor A
int enbSpeed = 200; // Initial speed for motor B

void setup() {
  delay(2000);
  pinMode(ena, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enb, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // LCD with Sensor
  lcd.begin();
  lcd.backlight();

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // LCD with Sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distanceCm = duration * 0.034 / 2;
  distanceInch = duration * 0.0133 / 2;

  lcd.setCursor(1, 0);
  lcd.print("Distance: ");
  lcd.print(distanceCm);
  lcd.print(" cm");
  delay(1);

  // Motor control
  if (distanceCm <= 10) {
    // Stop motors
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    analogWrite(ena, 0);
    analogWrite(enb, 0);
  } else if (distanceCm > 10 && distanceCm <= 20) {
    // Gradually slow down motors
    int speed = map(distanceCm, 10, 20, 0, max(enaSpeed, enbSpeed));
    analogWrite(ena, map(speed, 0, max(enaSpeed, enbSpeed), 0, enaSpeed));
    analogWrite(enb, map(speed, 0, max(enaSpeed, enbSpeed), 0, enbSpeed));
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  } else {
    // Motor A and B Clockwise Max Speed
    analogWrite(ena, enaSpeed);
    analogWrite(enb, enbSpeed);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }
}
