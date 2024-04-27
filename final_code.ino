#include <AFMotor.h>
#include <SoftwareSerial.h>

SoftwareSerial bluetooth(9, 10);

#define trigPin A2
#define echoPin A1
#define buzzer A0

// defines variables
long duration;
int distance;
int safetyDistance;
bool isConnected = false;
bool allowForward = true; 

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);

int speedCar = 255;
int stopCar = 0;

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);  // Sets the echoPin as an Input
  pinMode(buzzer, OUTPUT);
  Stop();
}

void forward() {
  if (allowForward) {
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor1.setSpeed(speedCar);
    motor2.setSpeed(speedCar);
  }
}

void backward() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor1.setSpeed(speedCar);
  motor2.setSpeed(speedCar);
}

void left() {
  motor1.run(BACKWARD);
  motor2.run(RELEASE);
  motor1.setSpeed(speedCar);
  motor2.setSpeed(stopCar);
}

void right() {
  motor1.run(RELEASE);
  motor2.run(BACKWARD);
  motor2.setSpeed(speedCar);
  motor1.setSpeed(stopCar);
}

void Stop() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}

void loop() {

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;
  safetyDistance = distance;
  Serial.println(distance);

  if (!isConnected && bluetooth.available()) {
    Serial.println("Connected");
    isConnected = true;           
  }

  if (isConnected) {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    if (safetyDistance <= 10 && safetyDistance >= 5) {
      digitalWrite(buzzer, HIGH);
      Serial.println("Obstacle at distance:");
      Serial.println(safetyDistance);
      if (allowForward){
        Stop();
      }
      allowForward = false; 
    } else {
      digitalWrite(buzzer, LOW);
      allowForward = true; 
    }
  }

  if (bluetooth.available() > 0) {
    char command = bluetooth.read();

    switch (command) {
      case 'F': forward(); break;
      case 'B': backward(); break;
      case 'L': left(); break;
      case 'R': right(); break;
      case 'C': Stop(); break;
      // Add speed control cases if needed
      default:
        // You might want to add error handling here
        break;
    }
  }
}
