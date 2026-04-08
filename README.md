## Section A:

---

### Q1: Blinking LED with different time intervals

**Tinkercad Link:** https://www.tinkercad.com/things/eMBqTMqAhJ2-section-aq1

**Explanation:**
This circuit uses three LEDs connected to an Arduino Uno, each blinking at different time intervals (500ms, 1000ms, and 1500ms). Instead of using delay(), the millis() function is used to track time independently for each LED. This ensures all LEDs blink simultaneously without affecting each other’s timing. The program continuously checks elapsed time and toggles each LED accordingly.

**Concepts Used:** millis, digitalWrite, timing control

---

### Q2: Controlling RGB LED colour and LED blink speed using potentiometer

**Tinkercad Link:** https://www.tinkercad.com/things/5U15OaKKwJp-section-aq2

**Explanation:**
This circuit uses a potentiometer connected to an analog pin to control both the colour of an RGB LED and the blinking speed of a normal LED. The analog value from the potentiometer is read using analogRead() and mapped to PWM values using analogWrite(). As the potentiometer is turned, the RGB LED changes colour smoothly, and the blinking rate of the LED increases or decreases accordingly.

**Concepts Used:** analogRead, analogWrite, PWM, mapping

---

### Q3: Reaction Time Tester

**Tinkercad Link:** https://www.tinkercad.com/things/cDzm7Kp9n35-section-aq3

**Explanation:**
This circuit measures the user's reaction time using an LED and a pushbutton. The LED turns ON at a random time using the random() function. Once the LED glows, the user must press the button as quickly as possible. The reaction time is calculated by subtracting the time when the LED turned ON from the time when the button is pressed using millis(). The result is displayed in the Serial Monitor, and the system resets for the next test.

**Concepts Used:** millis, random, INPUT_PULLUP, timing calculation


---

## Section B:

## 1: Smart Distance Alert System

### Description
This project detects how close an object is using an ultrasonic sensor. When something comes near, it gives an alert using an LED, buzzer, and motor.

### Why I chose this project
I chose this project to learn how sensors work with Arduino and how we can use them in real-life situations like safety and alerts.

### Components Used
- Arduino Uno
- Ultrasonic Sensor (3-pin)
- LED
- Buzzer
- DC Motor
- Resistors and wires

### Working
The ultrasonic sensor checks the distance of objects in front of it.
If an object comes closer (between 2 cm and 20 cm):
- LED turns ON
- Buzzer makes sound
- Motor starts running

If the object is far away:
- Everything stays OFF

### Challenges Faced
- At first, the distance readings were not stable
- I fixed it by adjusting the code and adding small delays
- I also got confused with sensor connections, but solved it by testing step by step

### Applications
- Parking assistance in vehicles
- Obstacle detection in robots
- Help for visually impaired people
- Safety systems in industries
- Automatic doors
  
### Tinkercad Link
https://www.tinkercad.com/things/futop1CPRuw-section-b


---


##  2: Smart Door Lock System

### Description

This project is a simple smart door lock system using Arduino.
It allows a user to enter a password using a keypad. If the password is correct, the door opens using a servo motor. If the password is wrong, it gives a warning using LED and buzzer.

---

###  What this project does

I chose this project because it is a basic real-life application of electronics used in homes, lockers, and security systems.

---

### Components Used

* Arduino Uno → Main controller
* 4x4 Keypad → To enter password
* 16x2 LCD → To show messages
* Servo Motor → To open/close door
* Buzzer → Sound alert
* Green LED → Shows correct password
* Red LED → Shows wrong password
* Breadboard & wires → Connections

---

### What each part does

* **Keypad** → Takes input from user
* **LCD** → Displays messages like "Enter Password", "Access Granted"
* **Servo Motor** → Acts like a door (rotates to open/close)
* **Green LED** → Turns ON when password is correct
* **Red LED** → Turns ON when password is wrong
* **Buzzer** → Gives sound for success and error

---

###  How to use the system

* Enter numbers using keypad
* Press `#` to confirm
* Press `*` to clear input
* Press `A` to change password
* Press `D` to close door manually

---

###  Default Password

 The default password is: **1234**

To test the project:

1. Enter `1234`
2. Press `#`
3. Door will open

---

### Password Change

1. Press `A`
2. Enter current password
3. Enter new password
4. Password will be updated

---

### Working Explanation (Code Logic)

* The keypad reads user input and stores it in a string
* When `#` is pressed, input is checked with stored password
* If correct:

  * Servo rotates (door opens)
  * Green LED ON
  * Buzzer beeps
* After a few seconds:

  * Door closes automatically
* If wrong:

  * Red LED ON
  * Buzzer alert
  * Attempts increase
* If wrong password entered 3 times:

  * System locks for few seconds

The program uses a simple state system to control:

* Access granted
* Door closed

This helps in smooth working without delay issues.

---

### Challenges faced

* Initially, timing was not working properly because of delay
* Fixed it using millis() for better control
* LCD display was overlapping, fixed by clearing line before printing

---

### Output

* LCD shows messages clearly
* Servo opens and closes door
* LEDs indicate correct/wrong password
* Buzzer gives sound feedback

---

### Applications

* Home security systems
* Digital lockers
* Basic access control systems

---

### Tinkercad Link
https://www.tinkercad.com/things/fjtfWZDR7BZ-ingenious-tumelo-hillar


