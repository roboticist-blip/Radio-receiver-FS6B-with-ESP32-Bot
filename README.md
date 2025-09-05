# ESP32 Motor Control with Fs6b Receiver and L298N Motor Driver

## Project Overview

This project demonstrates how to control two DC motors connected to an L298N motor driver using an ESP32 board and an Fs6b receiver (RC controller). Channels 1 and 3 of the Fs6b receiver are used to provide direction control:
- Channel 1 controls turning left/right
- Channel 3 controls moving forward/backward

The L298N motor driver input pins are connected to ESP32 GPIO pins 14, 27, 26, and 25 respectively.

This setup allows full control of a motorized robot or vehicle to move forward, backward, turn left, and turn right.

## Hardware Connections

- Fs6b Receiver channel 1 -> ESP32 GPIO 34
- Fs6b Receiver channel 3 -> ESP32 GPIO 35
- L298N Motor IN1 -> ESP32 GPIO 14
- L298N Motor IN2 -> ESP32 GPIO 27
- L298N Motor IN3 -> ESP32 GPIO 26
- L298N Motor IN4 -> ESP32 GPIO 25
- L298N Speed pins assumed always HIGH (connected to 5V or enabled)

## Features

- Reads PWM signals from Fs6b receiver channels 1 and 3
- Interprets PWM values for directional control
- Controls two motors via L298N motor driver to move in four directions: forward, backward, left, right
- Combines channel inputs for diagonal movements (forward-left, forward-right, etc.)

## Usage

1. Connect the hardware as described in the Hardware Connections section.
2. Upload the provided Arduino code to the ESP32 via Arduino IDE.
3. Power up the system and use the Fs6b transmitter to control the motors.

## Code

The key code files include:

- `MotorControl.ino`: Main Arduino sketch reading receiver PWM and controlling motor driver pins.

## Contributing

Contributions are welcome! Feel free to fork the repo, open issues for bugs or features, and submit pull requests.

## License

This project is licensed under the MIT License.

---

Thank you for checking out this project! If you find it useful, please star the repository.
