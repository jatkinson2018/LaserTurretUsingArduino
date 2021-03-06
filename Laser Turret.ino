#include <Servo.h>
Servo tilt, pan; // Create servo object
int joyX = A0; // Analog pin connected to x-axis servo
int joyY = A1; // Analog pin connected to y-axis servo
int x, y; // Variables to read values

void setup() {
tilt.attach(9); // Attach tilt servo on pin 9 to the servo object
pan.attach(10); // Attach pan servo on pin 10 to the servo object
}

void loop() {
x = joyX; // Read value of x-axis (between 0 and 1023)
y = joyY; // Read value of y-axis (between 0 and 1023)
x = map(analogRead(joyX), 0, 1023, 900, 2100); // Scale it to use
// with servo between
// 900 to 2100
// microseconds

y = map(analogRead(joyY), 0, 1023, 900, 2100);
tilt.write(x); // Set servo position according to scaled value
pan.write(y);
delay(15); // Wait for servos to get to new position
}