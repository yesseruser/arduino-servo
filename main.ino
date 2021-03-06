#include <Servo.h>
#define SERVO_PIN 9
#define POTENCIOMETER A0
Servo ourServo;
const float maxPotencioValue = 1024.0;
const float maxServoValue = 180.0;

void setup() {
  // put your setup code here, to run once:
  ourServo.attach(SERVO_PIN);
  pinMode(POTENCIOMETER, INPUT);
  Serial.begin(115200);
}

void loop() {
  uint16_t potencioValue = analogRead(POTENCIOMETER);
  float potencioRotation = potencioValue / maxPotencioValue;
  float servoRotation = potencioRotation * maxServoValue;
  ourServo.write((int)servoRotation);
  Serial.print("Servo je otočeno o ");
  Serial.print((int) servoRotation);
  Serial.println(" stupnu");
  delay(20);
}
