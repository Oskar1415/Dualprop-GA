const int sensorPin = 3;

volatile unsigned int pulseCount = 0;
unsigned long lastTime = 0;
const unsigned int measurementInterval = 1000;
float rpm = 0;

void setup() {
  pinMode(sensorPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(sensorPin), countPulse, RISING);

  Serial.begin(9600);
  Serial.println("RPM Measurement Initialized");
}

void loop() {
  unsigned long currentTime = millis();


  if (currentTime - lastTime >= measurementInterval) {
    noInterrupts();
    unsigned int pulseCountCopy = pulseCount;
    pulseCount = 0;
    interrupts();


    rpm = (pulseCountCopy / 7.5) * 60;


    Serial.print("RPM: ");
    Serial.println(rpm); //detta är inte exakt rpm, vi använder det bara för att jämföra

    lastTime = currentTime;
  }
}

void countPulse() {
  pulseCount++;
}
