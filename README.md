# 🍬 Smart Candy Dispensing Machine (Arduino Mega)

Welcome to the Smart Candy Machine project! This is an automated system designed to dispense different types of candies based on user input, using an Arduino Mega 2560 controller and simulated in Proteus.

## 📸 Simulation Preview
<img width="1314" height="908" alt="Screenshot 2026-03-21 151949" src="https://github.com/user-attachments/assets/edcb506a-4d88-40ba-afbb-51797c07ff68" />

## 🚀 How it Works
1. Detection: The Ultrasonic Sensor detects when a hand or a cup is placed near the machine (Distance < 10cm).
2. User Interaction: The Virtual Terminal prompts the user to choose between 3 types of candy (Press 1, 2, or 3).
3. Sorting: A Stepper Motor (controlled by ULN2003) rotates the selection plate to the correct position.
4. Vibration: A DC Motor (controlled by L298) vibrates briefly to ensure the candy falls.
5. Dispensing: A Servo Motor opens the final gate for 2 seconds then closes.
6. Queue Management: The system waits for the user to move their hand away before being ready for the next order.

## 🛠️ Components Used

### 🧠 Control Unit
- Microcontroller: Arduino Mega 2560 (The brain of the system).

### 📡 Sensing
- Ultrasonic Sensor (HC-SR04): Detects hand presence to trigger the process.

### 🕹️ Actuators & Drivers
- Stepper Motor (28BYJ-48): Rotates the selection mechanism with high precision.
- ULN2003 Driver: Drives the stepper motor sequences.
- DC Motor: Provides mechanical vibration to prevent candy from getting stuck.
- L298N Driver: Controls the DC motor's power and direction.
- Servo Motor (SG90): Operates the discharge gate (Open 90° / Close 0°).

### 🔔 Feedback & Interface
- Buzzer & LED: Visual and audible alerts during the dispensing process.
- Virtual Terminal: For user interaction and system status updates.

---

## 📂 Project Structure
- sketch_mar20a.ino: The main Arduino source code.
- New Project.pdsprj: The Proteus simulation file.
- sketch_mar20a.ino.hex: The compiled HEX file for instant simulation.

## 📝 Setup Instructions
1. Open the Proteus file (`.pdsprj`).
2. Double-click the Arduino Mega and load the .hex file.
3. Start the simulation.
4. Adjust the Potentiometer (RV1) to decrease the distance below 10cm.
5. Use the Virtual Terminal to enter your choice.
