#include <Servo.h>

// =====================================
// TRAFFIC LIGHT PINS
// =====================================
#define RED_LED 8
#define YELLOW_LED 12
#define GREEN_LED 9

// =====================================
// OTHER COMPONENTS
// =====================================
#define BUTTON 11
#define BUZZER 10

#define TRIG 6
#define ECHO 7

// =====================================
// SERVO
// =====================================
#define SERVO_PIN 5

Servo tactileServo;

// =====================================
// VARIABLES
// =====================================
bool crossingActive = false;

// =====================================
// ULTRASONIC FUNCTION
// =====================================
long getDistance() {

  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG, LOW);

  long duration = pulseIn(ECHO, HIGH, 30000);

  if (duration == 0)
    return 999;

  long distance = duration * 0.034 / 2;

  return distance;
}

// =====================================
// TACTILE MOVEMENT
// =====================================
void tactileMove() {

  tactileServo.write(60);
  delay(500);

  tactileServo.write(120);
  delay(500);
}

// =====================================
// SETUP
// =====================================
void setup() {

  // =====================================
  // PIN MODES
  // =====================================
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  // INPUT_PULLUP prevents false triggering
  pinMode(BUTTON, INPUT_PULLUP);

  pinMode(BUZZER, OUTPUT);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  // =====================================
  // SERVO
  // =====================================
  tactileServo.attach(SERVO_PIN);

  // =====================================
  // SERIAL MONITOR
  // =====================================
  Serial.begin(9600);

  Serial.println("=================================");
  Serial.println(" SMART PEDESTRIAN ASSISTANCE ");
  Serial.println(" SYSTEM INITIALIZED ");
  Serial.println("=================================");

  // =====================================
  // INITIAL STATE
  // =====================================
  digitalWrite(GREEN_LED, HIGH);

  digitalWrite(YELLOW_LED, LOW);

  digitalWrite(RED_LED, LOW);

  Serial.println("Traffic State: GREEN");
  Serial.println("Tactile Feedback: ACTIVE");
  Serial.println("System Ready");
}

// =====================================
// MAIN LOOP
// =====================================
void loop() {

  // =====================================
  // NORMAL TRAFFIC STATE
  // =====================================
  if (!crossingActive) {

    tactileMove();
  }

  // =====================================
  // BUTTON PRESS DETECTION
  // =====================================
  if (digitalRead(BUTTON) == LOW && !crossingActive) {

    delay(50);

    if (digitalRead(BUTTON) == LOW) {

      crossingActive = true;

      Serial.println("---------------------------------");
      Serial.println("Pedestrian Request Detected");

      // =====================================
      // STOP TACTILE MOVEMENT
      // =====================================
      tactileServo.write(90);

      Serial.println("Tactile Feedback Stopped");

      // =====================================
      // GREEN OFF
      // =====================================
      digitalWrite(GREEN_LED, LOW);

      Serial.println("Green Signal OFF");

      // =====================================
      // YELLOW ON
      // =====================================
      digitalWrite(YELLOW_LED, HIGH);

      Serial.println("Yellow Signal ON");

      delay(2000);

      digitalWrite(YELLOW_LED, LOW);

      Serial.println("Yellow Signal OFF");

      // =====================================
      // RED ON
      // =====================================
      digitalWrite(RED_LED, HIGH);

      Serial.println("Red Signal ON");
      Serial.println("Crossing Mode Activated");

      delay(1000);

      // =====================================
      // NORMAL BEEPS
      // 15 SECONDS
      // =====================================
      Serial.println("Countdown Started");

      for (int i = 15; i > 0; i--) {

        Serial.print("Time Remaining: ");
        Serial.print(i);
        Serial.println(" sec");

        digitalWrite(BUZZER, HIGH);
        delay(500);

        digitalWrite(BUZZER, LOW);
        delay(500);
      }

      // =====================================
      // FAST BEEPS
      // LAST 5 SECONDS
      // =====================================
      Serial.println("Fast Warning Beeps Activated");

      for (int i = 5; i > 0; i--) {

        Serial.print("Final Warning: ");
        Serial.print(i);
        Serial.println(" sec");

        for (int j = 0; j < 5; j++) {

          digitalWrite(BUZZER, HIGH);
          delay(100);

          digitalWrite(BUZZER, LOW);
          delay(100);
        }
      }

      // =====================================
      // ULTRASONIC EXTENSION
      // =====================================
      Serial.println("Checking Pedestrian Crossing");

      int clearCount = 0;

      while (clearCount < 5) {

        long distance = getDistance();

        Serial.print("Ultrasonic Distance: ");
        Serial.print(distance);
        Serial.println(" cm");

        // =====================================
        // PERSON DETECTED
        // =====================================
        if (distance > 0 && distance < 50) {

          clearCount = 0;

          Serial.println("Pedestrian Still Crossing");
          Serial.println("Crossing Time Extended");

          digitalWrite(BUZZER, HIGH);
          delay(200);

          digitalWrite(BUZZER, LOW);
          delay(200);
        }

        else {

          clearCount++;

          Serial.println("Crossing Path Clear");

          delay(300);
        }
      }

      // =====================================
      // RETURN TO NORMAL
      // =====================================
      digitalWrite(RED_LED, LOW);

      digitalWrite(GREEN_LED, HIGH);

      Serial.println("Red Signal OFF");
      Serial.println("Green Signal ON");

      Serial.println("Traffic Resumed");

      // =====================================
      // REACTIVATE TACTILE SYSTEM
      // =====================================
      Serial.println("Tactile Feedback Reactivated");

      // allow loop() to continue tactile motion
      crossingActive = false;

      Serial.println("---------------------------------");

      delay(1000);
    }
  }
}