int sensor = A0;
int relay = 7;
int moistureValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  pinMode(relay, OUTPUT);
  
  digitalWrite(relay, LOW); 
}

void loop() {
  moistureValue = analogRead(sensor);
  Serial.print("Soil Moisture Value: ");
  Serial.println(moistureValue);

  if (moistureValue < 400) {
    // Soil is dry → Pump ON
    digitalWrite(relay, HIGH);
  } 
  else {
    // Soil is wet → Pump OFF
    digitalWrite(relay, LOW);
  }

  delay(500);
}

