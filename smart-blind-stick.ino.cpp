
/*
  Project: Ultrasonic Smart Blind Stick
  Board: Arduino Uno
  Sensor: HC-SR04 Ultrasonic Sensor

  Function:
  Measures the distance between the stick and
  nearby obstacles and displays the readings
  through the Arduino Serial Monitor.

  Note:
  This reconstructed implementation does not
  include a buzzer or vibration motor.
*/

// HC-SR04 pin configuration
const int TRIG_PIN = 9;
const int ECHO_PIN = 10;

// Sensor measurement settings
const unsigned long ECHO_TIMEOUT = 30000UL;
const float SPEED_OF_SOUND = 0.0343;

// Distance limits in centimetres
const float MIN_VALID_DISTANCE = 2.0;
const float MAX_VALID_DISTANCE = 400.0;

// Obstacle detection threshold
const float OBSTACLE_THRESHOLD = 100.0;

float measureDistance() {

  // Ensure trigger pin starts LOW
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  // Send a 10-microsecond ultrasonic pulse
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Measure the duration of the echo pulse
  unsigned long duration =
      pulseIn(ECHO_PIN, HIGH, ECHO_TIMEOUT);

  // Return -1 if no echo is received
  if (duration == 0) {
    return -1.0;
  }

  // Calculate distance in centimetres
  float distance =
      (duration * SPEED_OF_SOUND) / 2.0;

  // Reject readings outside the sensor's
  // nominal measurement range
  if (distance < MIN_VALID_DISTANCE ||
      distance > MAX_VALID_DISTANCE) {
    return -1.0;
  }

  return distance;
}

void setup() {

  // Configure sensor pins
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // Initialize serial communication
  Serial.begin(9600);

  Serial.println("Ultrasonic Smart Blind Stick");
  Serial.println("Obstacle Detection System");
  Serial.println("--------------------------------");
}

void loop() {

  float distance = measureDistance();

  if (distance < 0) {

    Serial.println("No valid distance reading.");

  } else {

    Serial.print("Distance: ");
    Serial.print(distance, 2);
    Serial.println(" cm");

    // Check whether an obstacle is nearby
    if (distance <= OBSTACLE_THRESHOLD) {

      Serial.println("Obstacle detected within threshold!");

    } else {

      Serial.println("No obstacle within threshold.");

    }
  }

  Serial.println("--------------------------------");

  // Short delay between measurements
  delay(200);
}