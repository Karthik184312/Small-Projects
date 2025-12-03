int pirSensor = 7;
int light = 8;
int pirValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(pirSensor, INPUT);
  pinMode(light, OUTPUT);
}

void loop() {
  pirValue = digitalRead(pirSensor);
  Serial.println(pirValue);

  if (pirValue == HIGH) {
    digitalWrite(light, HIGH);   // Motion detected → Light ON
  } else {
    digitalWrite(light, LOW);    // No motion → Light OFF
  }

  delay(200);
}
