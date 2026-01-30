# 🔥 SafeZone Fire & Person Detection System

SafeZone is an **Arduino‑based safety monitoring system** designed to detect **fire hazards and human presence** in an area using multiple sensors. It provides **visual alerts via LEDs**, **real‑time status on an LCD**, and **serial alerts** for integration with a Python-based buzzer or monitoring application.

This project is suitable for **students, beginners in embedded systems**, and **IoT safety prototypes**.

---

## 📌 Features

* 🔥 **Fire Detection** using:

  * Flame sensor
  * Temperature sensor (DHT11)
* 👤 **Person Detection** using Ultrasonic Sensor (HC-SR04)
* 📟 **16×2 LCD Display** for system status and temperature
* 💡 **LED Alerts** for different safety states
* 🔔 **Serial Alerts** for external Python buzzer control
* ⚡ **Non‑blocking LED blinking** using `millis()`

---

## 🧰 Components Required

| Component                 | Quantity  |
| ------------------------- | --------- |
| Arduino Uno               | 1         |
| 16×2 LCD (parallel)       | 1         |
| DHT11 Temperature Sensor  | 1         |
| Flame Sensor Module       | 1         |
| HC‑SR04 Ultrasonic Sensor | 1         |
| Red LED                   | 1         |
| Yellow LED                | 1         |
| Green LED                 | 1         |
| White LED                 | 1         |
| Resistors (220Ω)          | 4         |
| Breadboard & Jumper Wires | As needed |

---

## 🔌 Pin Connections

### Sensors

* **Flame Sensor** → Pin `2`
* **DHT11 Data** → Pin `3`
* **Ultrasonic TRIG** → Pin `4`
* **Ultrasonic ECHO** → Pin `5`

### LEDs

* **Red LED** → Pin `6`
* **Green LED** → Pin `7`
* **Yellow LED** → Pin `A0`
* **White LED** → Pin `A1`

### LCD (16×2)

```text
RS  → 8
EN  → 9
D4  → 10
D5  → 11
D6  → 12
D7  → 13
```

---

## ⚙️ System Logic (How It Works)

The system continuously reads:

* Flame sensor status
* Temperature from DHT11
* Distance from Ultrasonic sensor

Based on predefined **thresholds**, the system decides the safety state.

### Thresholds Used

```cpp
int fireTempThreshold = 40;   // °C
int dangerDistance = 50;      // cm
```

---

## 🚦 System States & Indicators

| Condition           | LCD Display                  | LED Behavior                             |
| ------------------- | ---------------------------- | ---------------------------------------- |
| 🔥 Fire + 👤 Person | FIRE ALERT / PERSON DETECTED | 🔴🟡 Red & Yellow blink FAST alternately |
| 🔥 Fire + No Person | FIRE ALERT / NO PERSON       | 🟡 Yellow blinks slowly                  |
| No Fire + 👤 Person | AREA SAFE                    upda| ⚪ White ON                               |
| No Fire + No Person | AREA SAFE / Temp: XX°C       | 🟢 Green ON                              |

---

## 📟 LCD Display Behavior

* Displays **system status messages**
* Shows **current temperature** when area is safe
* Uses typing animation during alerts

Example (Safe State):

```text
AREA SAFE
Temp: 28°C
```

---

## 🖥️ Serial Output

The system sends alerts via Serial for Python integration:

* `ALERT1` → Fire detected, no person
* `ALERT2` → Fire detected, person nearby

These can be used to trigger:

* Buzzers
* Desktop alerts
* Logging systems

---

## 🚀 How to Use

1. Connect all components correctly
2. Install required Arduino libraries:

   * `LiquidCrystal`
   * `DHT sensor library`
3. Upload the code to Arduino
4. Open **Serial Monitor (9600 baud)**
5. Observe LCD messages and LED indicators

---

## 🛠️ Customization

You can easily modify:

* Temperature threshold
* Detection distance
* Blink speed
* LCD messages
* Add Wi‑Fi / GSM / IoT modules

---

## 🎯 Educational Value

This project teaches:

* Sensor integration
* Threshold-based decision making
* Non‑blocking Arduino programming
* LCD interfacing
* Real‑world safety system design

---

## 📜 License

This project is open for **educational and personal use**. Feel free to modify and improve it.

---

## 👨‍💻 Author

**SafeZone Project**
Designed for learning embedded systems, IoT, and safety applications.

---

 *Stay Safe. Build Smart.*
