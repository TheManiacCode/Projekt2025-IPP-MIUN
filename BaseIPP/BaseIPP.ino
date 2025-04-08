#include <NewPing.h>
NewPing sonar(3, 2, 800); // Trig=3, Echo=2, Max distance=800cm

void setup() {
  Serial.begin(9600);
}

void loop() {
  int distance = sonar.ping_cm();
  Serial.print("Distance= ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(500);
}