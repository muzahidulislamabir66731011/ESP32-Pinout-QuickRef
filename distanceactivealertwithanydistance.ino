#define TRIG_PIN 5
#define ECHO_PIN 18
#define BUZZER_PIN 23

int prevDistance = 0;  

void setup() {
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  int distance = duration * 0.034 / 2;  

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (prevDistance > 0) { 
    if (distance != prevDistance) {
      digitalWrite(BUZZER_PIN, HIGH);  
    } else {
      digitalWrite(BUZZER_PIN, LOW);  
    }
  }

  prevDistance = distance;  
  delay(200);
}

