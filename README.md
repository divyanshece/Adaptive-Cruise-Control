# 🚗⚡ Adaptive Cruise Control System

## 🔍 Overview
This project implements an **🚗 Adaptive Cruise Control (ACC) system** using an **📡 ultrasonic sensor, 📺 LCD display, and ⚙️ DC motors** controlled by an 🖥️ Arduino-compatible microcontroller. The system detects the 📏 distance of an object in front of the 🚗 and adjusts the ⚡ motor speed accordingly to maintain a safe 📏 distance.

## 🛠️ Components Used
- **🖥️ Arduino Board** (e.g., Arduino Uno)
- **📡 Ultrasonic Sensor** (HC-SR04) for 📏 distance measurement
- **📺 16x2 I2C LCD Display** for visual output
- **⚙️ Motor Driver Module** (L298N or equivalent) to control ⚙️ DC motors
- **⚙️ DC Motors** (for 🚗 movement)
- **🔋 Power Supply** (🔋 Battery or 🔌 USB power)

## 🔌 Pin Configuration
### 📡 Ultrasonic Sensor (HC-SR04)
| 📌 Pin  | 🖥️ Arduino Pin |
|------|------------|
| 📡 Trig | 10         |
| 📡 Echo | 11         |

### ⚙️ Motor Driver (L298N or Equivalent)
| 🔧 Function            | 🖥️ Arduino Pin |
|---------------------|------------|
| ⚙️ Motor A Enable (ENA) | 3          |
| ⚙️ Motor A Control 1 (IN1) | 5      |
| ⚙️ Motor A Control 2 (IN2) | 4      |
| ⚙️ Motor B Enable (ENB) | 9          |
| ⚙️ Motor B Control 1 (IN3) | 6      |
| ⚙️ Motor B Control 2 (IN4) | 7      |

### 📺 LCD Display (I2C)
| 🛠️ Function | 🔢 I2C Address |
|----------|------------|
| 📺 LCD      | 0x27       |

## 💻 Code Explanation
### 1. **⚙️ Initializing Components**
- The 📺 LCD, 📡 ultrasonic sensor, and ⚙️ motor pins are initialized in `setup()`.
- The `lcd.begin()` function starts the 📺 LCD display.
- `pinMode()` is used to define 🏗️ input/output pins.

### 2. **📏 Distance Measurement**
- The 📡 ultrasonic sensor sends a signal using `digitalWrite(trigPin, HIGH)`.
- The signal reflects back and is read via `pulseIn(echoPin, HIGH)`.
- 📏 Distance is calculated in 📏 cm using the formula:
  ```cpp
  distanceCm = duration * 0.034 / 2;
  ```

### 3. **⚡ Motor Control Based on 📏 Distance**
| 📏 Distance (cm) | 🎯 Action |
|--------------|--------|
| ≤ 10 cm     | ⛔ Stop both ⚙️ motors |
| 10 - 20 cm  | 🐢 Reduce speed gradually |
| > 20 cm     | 🚀 Full speed forward |

- `analogWrite(ena, speed)` and `analogWrite(enb, speed)` control ⚡ motor speed.
- `digitalWrite(in1, HIGH); digitalWrite(in2, LOW);` moves the ⚙️ motors forward.

### 4. **📺 LCD Display**
- The 📏 distance is displayed in real-time on the 📺 LCD using:
  ```cpp
  lcd.setCursor(1, 0);
  lcd.print("📏 Distance: ");
  lcd.print(distanceCm);
  lcd.print(" cm");
  ```

## ▶️ How to Run the Code
1. 🔌 Connect all 🛠️ components as per the 🔌 pin configuration.
2. ⬆️ Upload the code to your 🖥️ Arduino board using the 🖥️ Arduino IDE.
3. 🔋 Power the system and observe the 📏 distance displayed on the 📺 LCD.
4. 📦 Place an object in front of the 📡 sensor to see how the ⚙️ motor speed changes.

## 🚀 Future Improvements
- Implement **🧠 PID control** for smoother ⚡ speed adjustments.
- Add **🛑 braking mechanism** for better safety.
- Use **📡 Bluetooth/WiFi** for 📲 remote control.

## 📜 License
This project is **🆓 open-source** and can be modified or distributed freely.

---

