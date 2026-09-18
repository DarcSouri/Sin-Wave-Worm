// Ultrasonic sensor pins
const int trigPin = 16;
const int echoPin = 4;

const int motorA_Pin = 2;

// Motor B control pins (on MX108 #2)
const int motorB_Pin1 = 14;
const int motorB_Pin2 = 15;

// Motor C control pins (also on MX108 #2)
const int motorC_Pin1 = 12;
const int motorC_Pin2 = 13;

// Distance threshold (cm)
const int thresholdDistance = 20;

void setup() {
  Serial.begin(115200);

  // Ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Motor pins
  pinMode(motorA_Pin, OUTPUT);
  pinMode(motorB_Pin1, OUTPUT);
  pinMode(motorB_Pin2, OUTPUT);
  pinMode(motorC_Pin1, OUTPUT);
  pinMode(motorC_Pin2, OUTPUT);

  // Ensure motors are off initially
  digitalWrite(motorA_Pin, LOW);
  digitalWrite(motorB_Pin1, LOW);
  digitalWrite(motorB_Pin2, LOW);
  digitalWrite(motorC_Pin1, LOW);
  digitalWrite(motorC_Pin2, LOW);
}

void loop() {
  long duration;
  float distance;

  // Send pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure echo
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  // Debugging output
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > thresholdDistance) {
    // Obstacle not close: move all motors forward
    digitalWrite(motorA_Pin, HIGH);       // Motor A ON

    digitalWrite(motorB_Pin1, HIGH);      // Motor B forward
    digitalWrite(motorB_Pin2, LOW);

    digitalWrite(motorC_Pin1, HIGH);      // Motor C forward
    digitalWrite(motorC_Pin2, LOW);
  } else {
    // Obstacle too close: stop all motors
    digitalWrite(motorA_Pin, LOW);

    digitalWrite(motorB_Pin1, LOW);
    digitalWrite(motorB_Pin2, LOW);

    digitalWrite(motorC_Pin1, LOW);
    digitalWrite(motorC_Pin2, LOW);

    delay(1000);

    digitalWrite(motorB_Pin1, HIGH);
    digitalWrite(motorB_Pin2, LOW);
    digitalWrite(motorC_Pin1, LOW);
    digitalWrite(motorC_Pin2, HIGH);


    }

  

  delay(200);
}

