# Arduino Bluetooth Car with Ultrasonic Sensor

## Overview
This project involves building a Bluetooth-controlled car using an Arduino Uno board, an ultrasonic sensor, a motor driver shield, and a few other components. The car can be controlled wirelessly via a Bluetooth connection using a smartphone or any other Bluetooth-enabled device. Additionally, it is equipped with an ultrasonic sensor to detect obstacles in its path and stop accordingly to avoid collisions.

## Components Required
- Arduino Uno board
- Motor driver shield (e.g., L298N or L293D)
- Ultrasonic sensor (HC-SR04)
- Bluetooth module (HC-05 or HC-06)
- DC motors (2)
- Wheels (2)
- Chassis
- Jumper wires
- Buzzer
- Power source (battery pack or power bank)

## Wiring
- **Motor Driver Shield**: Connect the DC motors to the motor driver shield according to its pinout.
- **Ultrasonic Sensor**: Connect the trigPin and echoPin of the ultrasonic sensor to the Arduino Uno board.
- **Bluetooth Module**: Connect the TX pin of the Bluetooth module to pin 9 of the Arduino Uno and the RX pin to pin 10.

## Installation and Setup
1. **Arduino IDE**: Install the Arduino IDE on your computer if you haven't already.
2. **Library Installation**: Install the required libraries for the motor driver shield and the Bluetooth module. (AFMotor.h and SoftwareSerial.h)
3. **Upload Code**: Copy the provided Arduino code into the Arduino IDE and upload it to your Arduino board.
4. **Powering Up**: Power up your Arduino board using a suitable power source.

## Operation
1. **Bluetooth Connection**: Pair your smartphone or any Bluetooth-enabled device with the HC-05 or HC-06 module on the Arduino.
2. **Control Commands**: Use predefined commands (F - Forward, B - Backward, L - Left, R - Right, C - Stop) to control the movement of the car.
3. **Obstacle Detection**: The ultrasonic sensor detects obstacles in the path of the car. When an obstacle is detected within a certain range, the car stops automatically and activates a buzzer to alert the user.
4. **Safety**: Ensure that the car operates in a safe environment, away from any potential hazards or obstructions.

## Demo


https://github.com/Ace-9136/Bluetooth-Controlled-WheelChair/assets/97794390/e4713689-2bb3-4480-a372-3ca3cb18d700


## Troubleshooting
- **Bluetooth Connectivity Issues**: Check the Bluetooth module connections and ensure that the pairing process is completed correctly.
- **Motor Control Problems**: Verify the wiring of the motors to the motor driver shield and ensure that the motor control commands are properly executed.
- **Ultrasonic Sensor Calibration**: Adjust the distance thresholds in the code according to the specific requirements of your environment.

## Future Improvements
- Implement speed control functionality for finer movement adjustments.
- Add obstacle avoidance algorithms for more advanced navigation capabilities.
- Enhance the user interface for easier control and feedback.

## Credits
This project is inspired by various Arduino-based robotics projects and tutorials available online. Special thanks to the contributors of the AFMotor and SoftwareSerial libraries for their valuable contributions.

## Disclaimer
This project involves working with electrical components and motorized systems, which can potentially cause harm if not handled properly. Ensure that all safety precautions are taken, and adult supervision is advised, especially when working with high-voltage components or machinery. The creators of this project hold no responsibility for any damage or injury caused by the replication or misuse of the information provided.
