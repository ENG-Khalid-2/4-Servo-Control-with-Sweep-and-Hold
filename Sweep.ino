#include <Servo.h>

Servo servo1, servo2, servo3, servo4, servo5, servo6;
unsigned long startTime;
int pos = 0;

void setup() {
  servo1.attach(2);
  servo2.attach(8);
  servo3.attach(6);
  servo4.attach(4);


  startTime = millis();
}

void loop() {
  unsigned long currentTime = millis();

  if (currentTime - startTime < 2000) {
    // Sweep forward
    for (pos = 0; pos <= 180; pos += 1) {
      servo1.write(pos);
      servo2.write(pos);
      servo3.write(pos);
      servo4.write(pos);
      servo5.write(pos);
      servo6.write(pos);
      delay(5);
    }

    // Sweep backward
    for (pos = 180; pos >= 0; pos -= 1) {
      servo1.write(pos);
      servo2.write(pos);
      servo3.write(pos);
      servo4.write(pos);
      servo5.write(pos);
      servo6.write(pos);
      delay(5);
    }
  } else {
    // Hold all motors at 90 degrees
    servo1.write(90);
    servo2.write(90);
    servo3.write(90);
    servo4.write(90);
    servo5.write(90);
    servo6.write(90);
    while (true); // Stop looping
  }
}
