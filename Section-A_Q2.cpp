int potPin = A0;      // Potentiometer pin

int redPin = 9;       // RGB LED pins
int greenPin = 10;
int bluePin = 11;

int ledPin = 3;       // Normal LED

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {

  int potValue = analogRead(potPin);  // Read potentiometer (0–1023)

  // Convert to RGB values (0–255)
  int redValue   = map(potValue, 0, 1023, 0, 255);
  int greenValue = map(potValue, 0, 1023, 255, 0);
  int blueValue  = map(potValue, 0, 1023, 50, 255);

  // Set RGB LED color
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);

  // Control blinking speed (optimized range)
  int delayTime = map(potValue, 0, 1023, 80, 400);

  // Blink normal LED
  digitalWrite(ledPin, HIGH);
  delay(delayTime);

  digitalWrite(ledPin, LOW);
  delay(delayTime);
}