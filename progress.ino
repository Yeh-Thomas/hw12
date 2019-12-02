#include <IRremote.h>
#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;

int RECV_PIN = 9;
IRrecv irrecv(RECV_PIN);
decode_results results;


//void pose1() {
//  // start position (home button)
//
//  servo1.write(135);
//  servo2.write(45);
//}
//void pick() {
//  // pick up  (ok button)
//  servo1.write(90);
//  servo2.write(90);
//}


void setup() {
  // put your setup code here, to run once:

  //IR remote
  Serial.begin(19200);
  Serial.println("Startup");
  irrecv.enableIRIn();
  //irrecv.blink13(true);

  servo1.attach(3);
  servo2.attach(5);
  servo3.attach(7);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (irrecv.decode(&results)) {
    Serial.println(results.value);

    // results.value = key_value;
    if (results.value == 551508645) {
      servo1.write(70);
      servo2.write(0);  // (ok) to pick up items
      delay(500);
    }

    if (results.value == 551506605) {
      servo1.write(135);
      servo2.write(45); // (home) to release items
      delay(500);
    }

    if (results.value == 551512725) {
      servo3.write(0); // (up) to return to original
      delay(500);
    }

    if (results.value == 551545365) {
      servo3.write(180); // (down) to return to original
      delay(500);
    }

    if (results.value == 551520375) {
      servo3.write(15); // (1) turn 15 degree
      delay(500);
    }

    if (results.value == 551504055) {
      servo3.write(30); // (2) turn 30 degree
      delay(500);
    }
    if (results.value == 551536695) {
      servo3.write(45); // (3) turn 45 degree
      delay(500);
    }
    
    if (results.value == 551495895) {
      servo3.write(60); // (4) turn 60 degree
      delay(500);
    }
    
    if (results.value == 551528535) {
      servo3.write(75); // (5) turn 75 degree
      delay(500);
    }

    if (results.value == 551512215) {
      servo3.write(90); // (6) turn 90 degree
      delay(500);
    }

    if (results.value == 551544855) {
      servo3.write(105); // (7) turn 105 degree
      delay(500);
    }

    if (results.value == 551491815) {
      servo3.write(120); // (8) turn 120 degree
      delay(500);
    }

    if (results.value == 551524455) {
      servo3.write(135); // (9) turn 135 degree
      delay(500);
    }

    if (results.value == 551487735) {
      servo3.write(150); // (0) turn 150 degree
      delay(500);
    }
    irrecv.resume();
  }
}
