const int ledPin = 9;
const int buttonPin = 2;

unsigned long ledOnTime;
unsigned long reactionTime;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop() {

  int waitTime = random(1000, 5000);  // random delay (1–5 sec)
  delay(waitTime);

  digitalWrite(ledPin, HIGH);         // LED ON
  ledOnTime = millis();               // store start time

  while (digitalRead(buttonPin) == HIGH) {
    // wait until button is pressed
  }

  reactionTime = millis() - ledOnTime;

  Serial.print("Reaction Time: ");
  Serial.print(reactionTime);
  Serial.println(" ms");

  digitalWrite(ledPin, LOW);          // LED OFF

  delay(2000);                        // wait before next round
}