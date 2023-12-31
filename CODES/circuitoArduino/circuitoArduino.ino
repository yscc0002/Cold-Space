const int tmpSensorPin = A0;
const int blueLEDPin = 2;
const int yellowLEDPin = 3;
const int redLEDPin = 4;

void setup() {
  Serial.begin(9600);
  pinMode(blueLEDPin, OUTPUT);
  pinMode(yellowLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);  
}

void loop() {
  int tmpSensorValue = analogRead(tmpSensorPin);
  float voltage = (tmpSensorValue / 1024.0) * 5;

  Serial.print("Temperature (C): ");
  float temperature = (voltage - .5) * 100;
  Serial.print("Temperatura (C): ");
  Serial.println(temperature);

  // RANGO DE TEMPERATURAS (PARA EL CARIBE: REPUBLICA DOMINICANA)

  if (temperature < 25){
    digitalWrite(blueLEDPin, HIGH);
    digitalWrite(yellowLEDPin, LOW);
    digitalWrite(redLEDPin, LOW);
  }
  else if (temperature >= 25 && temperature <= 30){
    digitalWrite(blueLEDPin, LOW);
    digitalWrite(yellowLEDPin, HIGH);
    digitalWrite(redLEDPin, LOW);
  }
  else if (temperature > 30){
    digitalWrite(blueLEDPin, LOW);
    digitalWrite(yellowLEDPin, LOW);
    digitalWrite(redLEDPin, HIGH);
  }
  delay(1000);
}