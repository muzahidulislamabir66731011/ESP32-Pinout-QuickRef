#define TRIG_PIN 5
#define ECHO_PIN 18
#define BUZZER_PIN 23

int prevDistance = 0;  // stores last distance reading

void setup() {
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  // --- Trigger pulse ---
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // --- Measure echo ---
  long duration = pulseIn(ECHO_PIN, HIGH);
  int distance = duration * 0.034 / 2;  // cm

  // --- Print reading ---
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // --- Compare with previous reading ---
  if (prevDistance > 0) {  // skip first loop
    if (distance != prevDistance) {
      digitalWrite(BUZZER_PIN, HIGH);  // object is getting closer
    } else {
      digitalWrite(BUZZER_PIN, LOW);   // object is going away or steady
    }
  }

  prevDistance = distance;  // update for next loop
  delay(200);
}

