int motorPin = 9;
int speed = 0;

void setup() {
  pinMode(motorPin, OUTPUT);
  analogWrite(motorPin, speed);
  Serial.begin(9600);
  Serial.println("Enter a speed between 0 and 255:");
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    int newSpeed = input.toInt();

    if (newSpeed >= 0 && newSpeed <= 255) {
      speed = newSpeed;
      analogWrite(motorPin, speed);
      Serial.print("Speed set to: ");
      Serial.println(speed);
    } else {
      Serial.println("Invalid input. Enter a value between 0 and 255.");
    }
  }
}
