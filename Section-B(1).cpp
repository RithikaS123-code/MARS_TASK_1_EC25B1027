#define sensorPin 9   // SIG pin of ultrasonic sensor
#define led 13
#define buzzer 8
#define motor 7

long duration;
int distance;

void setup() {
  Serial.begin(9600);

  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(motor, OUTPUT);
}

void loop() {

  //  Trigger pulse (same pin)
  pinMode(sensorPin, OUTPUT);
  digitalWrite(sensorPin, LOW);
  delayMicroseconds(2);

  digitalWrite(sensorPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(sensorPin, LOW);

  //  Read echo
  pinMode(sensorPin, INPUT);
  duration = pulseIn(sensorPin, HIGH, 30000); // timeout

  //  Convert to distance
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  //  CONDITION (with filtering)
  if(distance > 2 && distance < 20) {
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, HIGH);
    digitalWrite(motor, HIGH);
  } 
  else {
    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);
    digitalWrite(motor, LOW);
  }

  delay(200); // stability delay
}
