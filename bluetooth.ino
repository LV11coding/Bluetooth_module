#include <SoftwareSerial.h>
SoftwareSerial BTSerial (2, 3);

char target = 'A';
int num = 0;

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);

}


void loop() {
  if (BTSerial.available()) {
    //  Serial.write(BTSerial.read());

    if (BTSerial.read() == target) {
      Serial.println(":0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0");
      num = 0;
    }
    else if (BTSerial.read() != target) {
      Serial.println("wrong");
      num++;
    }
    if (num > 4) {
      num = 0;
      Serial.println("Entered cooldown mode: Try again after 1 minute");
       BTSerial.end();
       delay(60000);
       BTSerial.begin(9600);
    }
  }
}
