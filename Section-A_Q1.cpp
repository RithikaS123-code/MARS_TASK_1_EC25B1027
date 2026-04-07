// Define LED pins
#define LED1 8
#define LED2 9
#define LED3 10

// Store previous times
unsigned long previousTime1 = 0;
unsigned long previousTime2 = 0;
unsigned long previousTime3 = 0;

// Time intervals (in milliseconds)
const unsigned long interval1 = 500;
const unsigned long interval2 = 1000;
const unsigned long interval3 = 1500;

// LED states
int ledState1 = 0;
int ledState2 = 0;
int ledState3 = 0;

void setup() {
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);
}

void loop() {
    unsigned long currentTime = millis();

    // LED 1 (500 ms)
    if (currentTime - previousTime1 >= interval1) {
        previousTime1 = currentTime;
        ledState1 = !ledState1;
        digitalWrite(LED1, ledState1);
    }

    // LED 2 (1000 ms)
    if (currentTime - previousTime2 >= interval2) {
        previousTime2 = currentTime;
        ledState2 = !ledState2;
        digitalWrite(LED2, ledState2);
    }

    // LED 3 (1500 ms)
    if (currentTime - previousTime3 >= interval3) {
        previousTime3 = currentTime;
        ledState3 = !ledState3;
        digitalWrite(LED3, ledState3);
    }
}