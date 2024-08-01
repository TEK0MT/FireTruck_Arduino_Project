/*
* AUTHORS : OLA MOHAMED , MARIAM ADHMA , MOHAMED TAREK
* LAST UPDTAED : 1 AUGUST 2024
* 
*/
#include <Servo.h>

#define FLAMERIGHT 2
#define FLAMECENTER 3 
#define FLAMELEFT 4
#define MQ2 A0
#define ULTRASONIC_TRIG A1
#define ULTRASONIC_ECHO A2
#define M1 8
#define M2 7
#define M3 6
#define M4 5
#define Pump 13
#define SERVO_PIN 9

Servo myservo;

void move_forward() {
  digitalWrite(M1, HIGH);
  digitalWrite(M3, HIGH);
  digitalWrite(M2, LOW);
  digitalWrite(M4, LOW);
}

void move_Right() {
  digitalWrite(M1, LOW);
  digitalWrite(M3, HIGH);
  digitalWrite(M2, HIGH);
  digitalWrite(M4, LOW);
}

void move_Left() {
  digitalWrite(M3, LOW);
  digitalWrite(M4, HIGH);
  digitalWrite(M1, HIGH);
  digitalWrite(M2, LOW);
}

void move_Stop() {
  digitalWrite(M2, LOW);
  digitalWrite(M4, LOW);
  digitalWrite(M1, LOW);
  digitalWrite(M3, LOW);
}

void fire_off() {
  digitalWrite(Pump, HIGH);
}

void fire_off_stop() {
  digitalWrite(Pump, LOW);
}

long measure_distance() {
  digitalWrite(ULTRASONIC_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(ULTRASONIC_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(ULTRASONIC_TRIG, LOW);
  long duration = pulseIn(ULTRASONIC_ECHO, HIGH);
  long distance = duration * 0.034 / 2;
  return distance;
}

void setup() {
  pinMode(FLAMERIGHT, INPUT);
  pinMode(FLAMECENTER, INPUT);
  pinMode(FLAMELEFT, INPUT);
  pinMode(MQ2, INPUT);
  pinMode(ULTRASONIC_TRIG, OUTPUT);
  pinMode(ULTRASONIC_ECHO, INPUT);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(M3, OUTPUT);
  pinMode(M4, OUTPUT);
  pinMode(Pump, OUTPUT);
  
  myservo.attach(SERVO_PIN);

  Serial.begin(9600);
}

void loop() {
  int righ = digitalRead(FLAMERIGHT);
  int left = digitalRead(FLAMELEFT);
  int center = digitalRead(FLAMECENTER);
  int gasSensorValue = analogRead(MQ2);
  long distance = measure_distance();
  
  if (righ == LOW && left == LOW && center == LOW) {
    fire_off_stop();
    
    if (distance < 15 && gasSensorValue < 300) {
      move_Stop();
      delay(250);

      // Scan surroundings
      myservo.write(45);
      long distanceLeft = measure_distance();
      
      myservo.write(135);
      long distanceRight = measure_distance();
      
      myservo.write(90);

      // Choose direction based on the largest available space
      if (distanceLeft > distanceRight) {
        move_Left();
        delay(map(distanceLeft, 15, 200, 300, 2000)); // Adjust turn duration based on distance
      } else if (distanceRight > distanceLeft) {
        move_Right();
        delay(map(distanceRight, 15, 200, 300, 2000)); // Adjust turn duration based on distance
      } else {
        move_Stop();
      }
    } else {
      move_forward();
    }
  } else if (righ == HIGH && left == HIGH && center == HIGH) {
    if (distance < 15 && gasSensorValue >= 300) {
      move_Stop();
      fire_off();
    } else {
      move_forward();
      fire_off_stop();
    }
  } else if (righ == HIGH && left == LOW) {
    move_Right();
    fire_off_stop();
  } else if (left == HIGH && righ == LOW) {
    move_Left();
    fire_off_stop();
  } else if (center == HIGH) {
    move_forward();
    fire_off_stop();
  } else {
    move_Stop();
    fire_off_stop();
  }
}

