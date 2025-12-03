int gasSensor = A0;
int buzzer = 7;
int led = 8;

void setup() {
  Serial.begin(9600);
  
  pinMode(gasSensor, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  int gasValue = analogRead(gasSensor); 
  Serial.print("Gas Level: ");
  Serial.println(gasValue);

  if (gasValue > 400) { 
    digitalWrite(buzzer, HIGH);
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(buzzer, LOW);
    digitalWrite(led, LOW);
  }

  delay(500);
}
