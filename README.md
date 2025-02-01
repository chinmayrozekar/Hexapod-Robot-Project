
# Hexapod Robot Project

This project showcases a six-legged **hexapod robot** capable of various gaits and obstacle avoidance using an **Arduino Uno** and an **SSC-32 servo controller**. The robot is equipped with 13 servo motors to control its limbs and a **PING))) ultrasonic sensor** for obstacle detection.

---

## **Project Overview**
The purpose of this project is to explore hexapod locomotion and implement multiple gait patterns:
- **Tripod Gait**: Fast but less stable, with three legs moving at a time.
- **Wave Gait**: Slow but highly stable, with one leg moving at a time.
- **Ripple Gait**: Moderate speed and stability, with a synchronized wave on both sides of the robot.

The robot uses a PING))) ultrasonic sensor to detect obstacles and react by adjusting its gait.

---

## **Features**
- **Multiple Gaits**: Implemented tripod, wave, ripple, and turn gaits.
- **Obstacle Detection**: Utilizes a PING))) ultrasonic sensor to measure distance and avoid obstacles.
- **Servo Control**: Managed through the SSC-32 servo controller, allowing precise movement of 13 servos.
- **Arduino Integration**: Coded in Arduino with a simplified interface for development.

---

## **Hardware Requirements**
- Arduino Uno
- SSC-32 Servo Controller
- 13 Servo Motors
- PING))) Ultrasonic Sensor
- 7.2V Battery for power

---

## **Project Files**
1. **detection.ino**: Implements basic obstacle detection and gait control.
2. **obstacle avoidance and detection.ino**: Advanced obstacle avoidance with dynamic gait transitions.
3. **ping.ino**: Reads and prints distance measurements from the PING))) sensor.
4. **ripple.ino**: Demonstrates the ripple gait pattern.
5. **tripod.ino**: Demonstrates the tripod gait pattern.
6. **turn.ino**: Implements a turning gait with multiple servo frame transitions.
7. **wave.ino**: Demonstrates the wave gait pattern.

---

## **How to Run**
1. Connect the hardware as per the schematic in the project documentation.
2. Upload the `.ino` files to the Arduino Uno using the Arduino IDE.
3. Monitor the serial output to observe sensor readings and system behavior.
4. Adjust gait parameters in the code to customize the movement patterns.

---

## **Gait Comparison**
| Gait        | Stability        | Speed       | Description                        |
|-------------|------------------|-------------|-------------------------------------|
| Tripod      | Low              | High        | Moves three legs at a time.         |
| Wave        | High             | Low         | Moves one leg at a time.            |
| Ripple      | Moderate         | Moderate    | Synchronized wave on both sides.    |

---

## **Sample Code Snippet**
Here's a sample snippet demonstrating how the hexapod sets its servo frames:

```cpp
#include "SSC32.h"
SSC32 mySSC32;

int channels[] = {0, 1, 2, 3, 4, 5, 16, 17, 18, 19, 20, 21};
int homeFrame[] = {1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500};

void setup() {
    mySSC32.begin(9600);
    mySSC32.enableServos(channels);
    mySSC32.setFrame(homeFrame);
}
```

---

## **Acknowledgments**
This project was conducted as part of the **EE685/885 Principles of Robotics Lab** at the Rochester Institute of Technology. Special thanks to **Chinmay Deepak Rozekar** and **Pranav Dattatray Kelkar** for their contributions.

---

## **References**
- [Arduino Reference](https://www.arduino.cc/en/Reference/HomePage)
- [Parallax PING))) Sensor Guide](https://www.parallax.com/sites/default/files/downloads/28015-PING-Sensor-Product-Guide-v2.0.pdf)
- [Servo Motors Overview](http://www.electronicshub.org/servo-motors/)

---

