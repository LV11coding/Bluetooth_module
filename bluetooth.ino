#include <SoftwareSerial.h>
SoftwareSerial BTSerial(2, 3);
 
char target = 'A';
int num = 0;
 
void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
  Serial.println("Enter password:");
}
 
 
void loop() {
  if (BTSerial.available()) {
    //  Serial.write(BTSerial.read());
 
    if (BTSerial.read() == target) {
      Serial.println("Right");
      num = 0;
    } else if (BTSerial.read() != target) {
      Serial.println("Wrong");
      num++;
    }
    if (num > 4) {
      num = 0;
      Serial.println("Entered cooldown mode: Try again after 1 minute");
      BTSerial.end();
      delay(60000);
      BTSerial.begin(9600);
      Serial.println("Exited cooldown mode: Try again");
    }
  }
}
