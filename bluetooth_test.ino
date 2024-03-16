#include <SoftwareSerial.h>

SoftwareSerial blut(2, 3);

String target = "Wassup";
String check = "";
int num = 0;

void setup() {
  Serial.begin(9600);
  blut.begin(9600);
  Serial.println("Enter password:");
}

void loop() {
  while (blut.available()) {
    char origin = char(blut.read());
    check += origin;
    if (check.indexOf("Wassup") != -1) {
      Serial.println("good");
      check.remove(0);
      num = 0;
    }
    else {
      Serial.println("bad");
      num++;
    }
    if (num > 4) {
      num = 0;
      Serial.println("Entered cooldown mode: Try again after 1 minute");
      blut.end();
      delay(60000);
      blut.begin(9600);
      Serial.println("Exited cooldown mode: Try again");
    }

  }
}
