int ldr = A0;
int light = 7;
int value = 0;

void setup() {
  Serial.begin(9600);
  pinMode(light, OUTPUT);
}

void loop() {
  value = analogRead(ldr);
  Serial.println(value);

  if (value < 400) {     
    digitalWrite(light, HIGH);   
  } else {
    digitalWrite(light, LOW);    
  }

  delay(200);
}
