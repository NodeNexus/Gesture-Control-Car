# 🤖 Gesture-Controlled Car (Arduino)

## 📌 Overview
This project uses **Arduino + MPU6050 (accelerometer + gyro)** as a gesture controller.  
The controller sends movement commands via **RF modules** to another Arduino that drives the car motors using an **L298N motor driver**.

- Tilt forward → Car moves forward  
- Tilt backward → Car moves backward  
- Tilt left → Car turns left  
- Tilt right → Car turns right  

---

## 🛠️ Hardware Required
- 2 × Arduino Uno/Nano
- 1 × MPU6050 accelerometer
- 1 × RF Transmitter + Receiver pair (433MHz)
- 1 × L298N Motor Driver
- 4 × DC Motors + Chassis
- Jumper wires, breadboard, battery pack

---

## 🔌 Wiring

### Transmitter (Arduino + MPU6050 + RF Transmitter)
- MPU6050 → Arduino:  
  - VCC → 5V  
  - GND → GND  
  - SDA → A4  
  - SCL → A5  
- RF Transmitter:  
  - Data → D3  
  - VCC → 5V  
  - GND → GND  

### Receiver (Arduino + RF Receiver + L298N)
- RF Receiver:  
  - Data → D2  
  - VCC → 5V  
  - GND → GND  
- L298N:  
  - IN1 → D4  
  - IN2 → D5  
  - IN3 → D6  
  - IN4 → D7  
  - Motor outputs → DC motors  

---

## ▶️ Usage
1. Upload `Transmitter.ino` to the controller Arduino.  
2. Upload `Receiver.ino` to the car Arduino.  
3. Power up both Arduinos.  
4. Tilt the transmitter to drive the car! 🚗  

---
---

## ✨ Future Improvements
- Add speed control with tilt angle.  
- Upgrade to Wi-Fi (ESP8266/ESP32) for longer range.  
- Add obstacle avoidance sensor.
