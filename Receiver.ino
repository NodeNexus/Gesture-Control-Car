#include <SoftwareSerial.h>

SoftwareSerial rfSerial(2, 3); // TX=3, RX=2 (connected to RF receiver)

#define IN1 4
#define IN2 5
#define IN3 6
#define IN4 7

void setup() {
  rfSerial.begin(9600);
  Serial.begin(9600);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  stopMotors();
}

void loop() {
  if (rfSerial.available()) {
    String cmd = rfSerial.readStringUntil('\n');
    cmd.trim();
    Serial.println("Received: " + cmd);

    if (cmd == "F") forward();
    else if (cmd == "B") backward();
    else if (cmd == "L") left();
    else if (cmd == "R") right();
    else stopMotors();
  }
}

void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void left() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void right() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}