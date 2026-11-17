
# Working Principle

## 1. Ultrasonic Sensing

The HC-SR04 ultrasonic sensor measures the distance to objects using ultrasonic sound waves.

It contains a transmitter and a receiver.

## 2. Pulse Transmission

The Arduino sends a short HIGH pulse to the TRIG pin of the HC-SR04 sensor.

The sensor transmits an ultrasonic signal at approximately 40 kHz.

## 3. Echo Reception

When the transmitted signal encounters an object, part of the signal is reflected towards the sensor.

The receiver detects the reflected signal and generates an output pulse on the ECHO pin.

## 4. Time Measurement

The Arduino uses the pulseIn() function to measure how long the ECHO pin remains HIGH.

This duration represents the total travel time of the ultrasonic signal.

## 5. Distance Calculation

The distance is calculated using:

Distance = (Time × Speed of Sound) / 2

The approximate speed of sound used in the program is 0.0343 cm per microsecond.

The division by two accounts for the outgoing and returning journeys of the sound wave.

## 6. Obstacle Detection

The calculated distance is compared against a predefined threshold of 100 cm.

- If the distance is 100 cm or less, the system identifies an obstacle within the threshold.
- If the distance is greater than 100 cm, the system reports no obstacle within the threshold.
- If a valid echo is not received, the system reports an invalid distance reading.

## 7. Output

The measured distance and obstacle detection status are displayed through the Arduino Serial Monitor at 9600 baud.
