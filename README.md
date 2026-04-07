## Section A

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

## Section B: Smart Distance Alert System

### Description
This project uses an ultrasonic sensor to detect the distance of nearby objects and alert the user when the object comes within a specific range. It is useful for obstacle detection and safety systems.

### Why I chose this project
I chose this project to understand how sensors work with Arduino and to learn real-time distance measurement and alert systems.

### Components Used
- Arduino Uno
- Ultrasonic Sensor (3-pin)
- LED
- Buzzer
- DC Motor
- Resistors and connecting wires

### Working
The ultrasonic sensor sends sound waves and receives the reflected signal to calculate distance. The Arduino processes this data and checks if the object is within the range of 2–20 cm. If the object is within this range, the LED glows, the buzzer sounds, and the motor turns ON. If the object is outside this range, all outputs remain OFF.

### Challenges Faced
- Unstable sensor readings were observed initially, which were fixed by adding delay and filtering conditions.
- Wiring confusion in the ultrasonic sensor connections was corrected after testing each component separately.

### Applications
- Vehicle parking assistance  
- Obstacle detection in robots  
- Aid for visually impaired people  
- Industrial safety systems  
- Automatic doors and security systems
  
### Tinkercad Link
https://www.tinkercad.com/things/futop1CPRuw-section-b

