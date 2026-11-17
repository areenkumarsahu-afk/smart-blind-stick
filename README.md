
# Ultrasonic Smart Blind Stick

An Arduino-based obstacle detection prototype designed to assist visually impaired individuals by measuring the distance to nearby objects using ultrasonic sensing.

## Project Overview

The Ultrasonic Smart Blind Stick is an embedded systems project that uses an HC-SR04 ultrasonic sensor and an Arduino Uno to detect obstacles in front of the device.

The ultrasonic sensor transmits sound waves and receives their reflected signals. The Arduino measures the time taken for the reflected waves to return and calculates the distance to the detected object.

The measured distance is displayed through the Arduino Serial Monitor. A predefined threshold is used to determine whether an obstacle is within the specified detection range.

## Objectives

- Develop an affordable ultrasonic obstacle detection prototype.
- Interface an HC-SR04 sensor with an Arduino Uno.
- Measure distances using ultrasonic signals.
- Implement distance-based obstacle detection.
- Understand basic embedded systems programming and sensor interfacing.

## Features

- Ultrasonic distance measurement.
- Real-time distance readings through Serial Monitor.
- Configurable obstacle detection threshold.
- Invalid sensor reading handling.
- Arduino-based embedded implementation.

## Hardware Components

| Component | Quantity |
|---|---:|
| Arduino Uno | 1 |
| HC-SR04 Ultrasonic Sensor | 1 |
| Battery / Power Supply | 1 |
| Connecting Wires | As required |
| Walking Stick Structure | 1 |

## Software Requirements

- Arduino IDE
- Arduino Uno board support
- USB cable for programming
- Serial Monitor

## Working Principle

1. The HC-SR04 sensor transmits an ultrasonic pulse.
2. The pulse reflects from a nearby object.
3. The sensor receives the reflected signal.
4. The Arduino measures the echo duration.
5. The distance is calculated using the speed of sound.
6. The measured distance is compared with a predefined threshold.
7. The result is displayed through the Serial Monitor.

## Circuit Connections

| HC-SR04 Pin | Arduino Uno |
|---|---|
| VCC | 5V |
| GND | GND |
| TRIG | Digital Pin 9 |
| ECHO | Digital Pin 10 |

See [Wiring Connections](docs/wiring-connections.md).

## Repository Structure

- `src/` - Arduino source code.
- `docs/` - Project documentation.
- `hardware/` - Hardware information and pin configuration.
- `images/` - Project photographs and diagrams.
- `tests/` - Testing documentation.

## Installation and Setup

1. Install the Arduino IDE.
2. Connect the Arduino Uno to your computer.
3. Open `smart_blind_stick.ino`.
4. Select Arduino Uno under Tools > Board.
5. Select the appropriate communication port.
6. Upload the program.
7. Open the Serial Monitor.
8. Set the baud rate to 9600.

## Usage

After uploading the program, the ultrasonic sensor begins measuring distances continuously.

The Serial Monitor displays the measured distance in centimetres and indicates whether an obstacle is within the configured threshold.

The current implementation uses a 100 cm obstacle detection threshold.

## Demonstration

Project photographs can be found in the `images/` directory.

## Testing

Testing documentation is available in:

- [Testing and Results](docs/testing-and-results.md)
- [Test Records](tests/test-results.md)

Experimental measurements should be added after testing the actual hardware.

## Limitations

- The current implementation does not include audio alerts.
- The current implementation does not include vibration feedback.
- The sensor detects objects within its effective sensing direction.
- Ultrasonic measurements can be affected by object shape and surface characteristics.
- The prototype does not provide complete environmental awareness.

## Future Improvements

- Add vibration-based obstacle alerts.
- Integrate additional ultrasonic sensors.
- Implement downward-facing obstacle detection.
- Improve power management.
- Develop a compact and durable enclosure.
- Introduce emergency location-sharing capabilities.

## Safety Disclaimer

This project is an educational prototype and is not a certified mobility aid. It should not replace a conventional white cane, mobility training, or other established assistive devices.

## License

This project is distributed under the MIT License.
