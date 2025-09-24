#include <Wire.h>
#include <MPU6050.h>
#include <SoftwareSerial.h>

MPU6050 mpu;
SoftwareSerial rfSerial(2, 3); // TX=3, RX=2 (connected to RF transmitter)

int16_t ax, ay, az;
int16_t gx, gy, gz;

void setup() {
  Wire.begin();
  Serial.begin(9600);
  rfSerial.begin(9600);

  Serial.println("Initializing MPU6050...");
  mpu.initialize();
  if (!mpu.testConnection()) {
    Serial.println("MPU6050 connection failed!");
    while (1);
  }
  Serial.println("MPU6050 ready");
}

void loop() {
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  String cmd = "STOP";
  if (ay > 15000) cmd = "F";    // Forward
  else if (ay < -15000) cmd = "B"; // Backward
  else if (ax > 15000) cmd = "L";  // Left
  else if (ax < -15000) cmd = "R"; // Right

  rfSerial.println(cmd);
  Serial.println("Sent: " + cmd);

  delay(200);
}