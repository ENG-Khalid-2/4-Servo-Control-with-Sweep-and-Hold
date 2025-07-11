# 🤖 4-Servo-Control & Walking Algorithm

## 🧠 Track Info

> This is the **second task** in the **electronics Track**.

---

## ✅ Task 1: 4-Servo Control with Sweep and Hold

### 💡 Project Idea
This project demonstrates how to control **4 servo motors** using an Arduino Uno. The servos simulate humanoid robot joints. All servos perform a **Sweep movement** for 2 seconds, then **hold at 90°**, representing a stable standing posture.

---

### 🧰 Components Used

| Component             | Quantity | Purpose                                 |
|-----------------------|----------|-----------------------------------------|
| Arduino Uno           | 1        | Controls the servos                     |
| Servo Motor           | 4        | Simulate leg joints                     |
| Jumper Wires          | 14       | Connect servos to Arduino               |
| External Power (optional) | 1    | Power servos more reliably if needed    |

---

### 🔌 Arduino Pin Connections

| Servo Motor | Arduino Pin |
|-------------|-------------|
| Servo1      | 8          |
| Servo2      | 6          |
| Servo3      | 4         |
| Servo4      | 2          |



---

### 💻 Arduino Code

```cpp
#include <Servo.h>

Servo servo1, servo2, servo3, servo4;
unsigned long startTime;
int pos = 0;

void setup() {
  servo1.attach(8);
  servo2.attach(6);
  servo3.attach(4);
  servo4.attach(2);

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
      delay(5);
    }

    // Sweep backward
    for (pos = 180; pos >= 0; pos -= 1) {
      servo1.write(pos);
      servo2.write(pos);
      servo3.write(pos);
      servo4.write(pos);
      delay(5);
    }
  } else {
    // Hold all at 90 degrees
    servo1.write(90);
    servo2.write(90);
    servo3.write(90);
    servo4.write(90);
    while (true); // Stop looping
  }
}
```
# 🤖  Walking Algorithm
The humanoid robot is designed with the following servo configuration:

- **4 Servo Motors Total:**
  - **2 Hip Servos**: Control forward and backward leg movement
  - **2 Knee Servos**: Control leg bending
 
  - 1. **Initialize Posture**
   - Set all 4 servos to 90°, representing a standing position.

2. **Lift Left Leg**
   - Bend the **left knee** (e.g., 120°)
   - Move the **left hip** forward (e.g., 60°)
   

3. **Place Left Leg Forward**
   - Return **left knee** to 90° (leg straight)
   - Maintain **left hip** forward

4. **Shift Weight to Left Leg**
   - Center of gravity moves over the left leg
   - (If ankle servos are present, shift accordingly)

5. **Lift Right Leg**
   - Bend the **right knee** (e.g., 120°)
   - Move the **right hip** forward (e.g., 120°)

6. **Place Right Leg Forward**
   - Return **right knee** to 90°
   - Maintain **right hip** position

7. **Repeat Steps 2–6**
   - Alternate legs continuously to simulate walking
