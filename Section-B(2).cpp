#include <Keypad.h>
#include <Servo.h>
#include <LiquidCrystal.h>

// LCD and Servo
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
Servo myServo;

// Keypad setup
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {6, 7, 8, 13};
byte colPins[COLS] = {A0, A1, A2, A3};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Hardware pins
int buzzer = 10;
int greenLED = A4;
int redLED = A5;

// Password variables
String password = "1234";
String input = "";
int attempts = 0;

// Door and timing
bool doorOpen = false;
unsigned long doorOpenTime = 0;
const int autoCloseDelay = 5000;

// LCD message timing
bool showAccess = false;
unsigned long lcdMessageTime = 0;

// Password change flags
bool verifyOldPass = false;
bool changeMode = false;

void setup() {
  myServo.attach(9);
  myServo.write(0);

  pinMode(buzzer, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  lcd.begin(16, 2);
  lcd.print("Smart Door Lock");
  delay(2000);
  lcd.clear();
  lcd.print("Enter Password");
}

void loop() {
  char key = keypad.getKey();

  // Auto-close door
  if (doorOpen && millis() - doorOpenTime >= autoCloseDelay) {
    myServo.write(0);
    doorOpen = false;
    lcd.clear();
    lcd.print("Door Closed");
    delay(1500);
    lcd.clear();
    lcd.print("Enter Password");
  }

  // Reset after 3 wrong attempts
  if (attempts >= 3) {
    lcd.clear();
    lcd.print("SYSTEM LOCKED");
    tone(buzzer, 500);
    delay(5000);
    noTone(buzzer);
    attempts = 0;
    lcd.clear();
    lcd.print("Enter Password");
  }

  // Keep "Access Granted" visible
  if (showAccess && millis() - lcdMessageTime >= 2000) {
    lcd.clear();
    lcd.print("Enter Password");
    digitalWrite(greenLED, LOW);
    showAccess = false;
  }

  if (key) {
    // Manual close
    if (key == 'D') {
      myServo.write(0);
      doorOpen = false;
      lcd.clear();
      lcd.print("Door Closed");
      delay(1500);
      lcd.clear();
      lcd.print("Enter Password");
      return;
    }

    // Clear input
    if (key == '*') {
      input = "";
      lcd.clear();
      lcd.print("Cleared");
      delay(1000);
      lcd.clear();
      lcd.print("Enter Password");
      return;
    }

    // Confirm / Enter
    if (key == '#') {
      lcd.clear();

      // Step 1: Verify old password for change
      if (verifyOldPass) {
        if (input == password) {
          lcd.print("Enter New Pass");
          changeMode = true;
        } else {
          lcd.print("Wrong Old Pass");
          delay(2000);
        }
        verifyOldPass = false;
      }

      // Step 2: Set new password
      else if (changeMode) {
        password = input;
        lcd.print("Password Changed");
        changeMode = false;
        delay(2000);
      }

      // Normal login
      else if (input == password) {
        lcd.clear();
        lcd.print("Access Granted");
        digitalWrite(greenLED, HIGH);
        tone(buzzer, 1000, 300);

        myServo.write(90);       // Open door
        doorOpen = true;
        doorOpenTime = millis();

        lcdMessageTime = millis(); // Start message timer
        showAccess = true;

        attempts = 0;
      }

      // Wrong password
      else {
        attempts++;
        lcd.print("Wrong Password");
        digitalWrite(redLED, HIGH);
        tone(buzzer, 500, 1000);
        delay(2000);
        digitalWrite(redLED, LOW);

        lcd.clear();
        lcd.print("Attempts Left:");
        lcd.setCursor(0,1);
        lcd.print(3 - attempts);
        delay(2000);
      }

      input = "";
      if (!showAccess) {
        lcd.clear();
        lcd.print("Enter Password");
      }
    }

    // Start password change process
    else if (key == 'A') {
      lcd.clear();
      lcd.print("Enter Old Pass");
      verifyOldPass = true;
      input = "";
    }

    // Normal key input
    else {
      input += key;
      lcd.setCursor(0,1);
      for (int i = 0; i < input.length(); i++) {
        lcd.print("*");
      }
    }
  }
}