const int plant1 = 34;
const int plant2 = 35;

void setup() {
  Serial.begin(115200);
  Serial.println("Sensor test begins...");
  delay(2000);
}

void loop() {
  int plant1 = analogRead(plant1);
  int plant2 = analogRead(plant2);

  Serial.print("Plant #1 (Pin 34): ");
  Serial.print(plant1);
  Serial.print("  |  Plant #2 (Pin 35): ");
  Serial.println(plant2);

  delay(3000);
}
