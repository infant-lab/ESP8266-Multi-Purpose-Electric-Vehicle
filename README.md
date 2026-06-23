-- ESP8266-Based IoT Multi-Purpose Electric Vehicle:

An IoT-enabled multipurpose electric vehicle developed as my final year major project. The vehicle is remotely controlled using the Blynk IoT platform and is capable of movement, steering, servo actuation, DC motor operation and water pump control over Wi-Fi.

------------------

-- Project Overview:

This project demonstrates the design and implementation of a Wi-Fi controlled multipurpose electric vehicle using the ESP8266 NodeMCU. The system integrates multiple motors and is operated through the Blynk mobile application, enabling real-time wireless control.
The vehicle was developed to showcase embedded systems, IoT communication, motor control and remote automation.

------------------

-- Features:

- 🚗 Forward and Reverse movement
- ⬅️ Left and Right steering
- ⚡ Variable speed control using PWM
- 🤖 Servo motor control
- ⚙️ 12V DC geared motor control
- 💧 5V Submersible water pump control
- 📱 Blynk mobile app interface
- 📶 Wi-Fi based remote operation

------------------

-- Hardware Used:

| Component | Quantity |
|-----------|----------|
| ESP8266 NodeMCU | 1 |
| L298N Motor Driver | 2 |
| Servo Motor | 1 |
| DC Geared Motor | 1 |
| 5V Submersible Water Pump | 1 |
| DC Motors | 4 |
| Chassis | 1 |
| Lithium-Ion Battery pack | 1 |

------------------

-- Software Used:

- Arduino IDE
- Blynk IoT Platform
- VS Code
- Arduino core for ESP8266

------------------

-- Pin Connections:

| Function | ESP8266 Pin |
|----------|-------------|
| PWM Speed | D2 |
| Forward Motor | D3 |
| Reverse Motor | D4 |
| Right Motor | D5 |
| Left Motor | D6 |
| Servo Motor | D7 |
| DC Motor | D1 |
| Water Pump | D0 |

------------------

-- Blynk Virtual Pins:

| Virtual Pin | Function |
|-------------|----------|
| V1 | Speed Control |
| V2 | Forward |
| V3 | Reverse |
| V4 | Right |
| V5 | Left |
| V7 | Servo Control |
| V8 | DC Motor |
| V9 | Water Pump |

------------------

-- Working Principle:

The ESP8266 NodeMCU serves as the central controller of the system, connecting to a Wi-Fi network and communicating with the Blynk cloud platform. Commands from the Blynk mobile application are transmitted through Blynk Virtual Pins and processed by the ESP8266, which translates these inputs into GPIO signals to control the various hardware components in real time.

The vehicle provides wireless control over locomotion, speed, steering, a 12V DC geared motor, a servo mechanism and a 5V submersible water pump. PWM (Pulse Width Modulation) is used to regulate the speed of the locomotion motors, while digital GPIO outputs control the direction of movement and the operation of auxiliary devices. The servo motor is controlled directly by the ESP8266 using the Servo library, allowing accurate positioning independent of the motor drivers.

During the initial design phase, the system was developed using a single L298N motor driver to control all motors and peripherals. However, testing revealed that this configuration was not sufficient to reliably operate multiple actuators simultaneously, resulting in unstable performance and reduced system reliability.

To overcome this limitation, the hardware architecture was redesigned by incorporating a second L298N motor driver. The first motor driver was dedicated exclusively to the four DC motors responsible for the vehicle's locomotion, enabling smooth forward, reverse, left, and right movement. The second motor driver was assigned to the auxiliary 12V geared DC motor and the 5V submersible water pump, allowing these components to operate independently of the locomotion system. The servo motor remained directly connected to the ESP8266 and was not driven through the motor driver.

This redesign distributed the electrical load more effectively, simplified the control architecture, improved troubleshooting, maintenance and significantly enhanced the overall stability and responsiveness of the vehicle. The final system achieved reliable real time wireless control of all components through the Blynk mobile application, demonstrating the practical integration of embedded systems, IoT communication and motor control in a multipurpose robotic platform.


------------------

-- Repository Structure:

```
ESP8266-Multi-Purpose-Electric-Vehicle
│
├── Code/
│   └── ESP8266_MultiPurposeEV.ino
│
├── Images/
│
├── Documents/
│
├── Wiring/
│
├── README.md
└── LICENSE
```

------------------

-- Future Improvements

- Autonomous obstacle detection and avoidance.
- GPS-based navigation and route tracking.
- Live camera streaming for remote monitoring.
- Battery voltage and health monitoring.
- Voice-controlled operation.
- Mobile notifications for system status.

------------------

-- Author

Infant Jerosin J

Bachelor of Engineering (Electrical & Electronics Engineering)

Embedded Systems • IoT • PCB Design • Embedded C • Electronics
