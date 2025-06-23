#include <Arduino.h>

// Khai báo chân điều khiển
#define RPWM 25
#define LPWM 26
#define R_EN 32
#define L_EN 33

void setup() {
  Serial.begin(115200);

  // Cấu hình các chân là OUTPUT
  pinMode(RPWM, OUTPUT);
  pinMode(LPWM, OUTPUT);
  pinMode(R_EN, OUTPUT);
  pinMode(L_EN, OUTPUT);

  // Kích hoạt 2 chiều
  digitalWrite(R_EN, HIGH);
  digitalWrite(L_EN, HIGH);

  Serial.println("BTS7960 Test Starting...");
}

void loop() {
  Serial.println("Motor quay chiều phải");
  analogWrite(RPWM, 200); // PWM 200/255
  analogWrite(LPWM, 0);
  delay(3000);

  Serial.println("Dừng");
  analogWrite(RPWM, 0);
  analogWrite(LPWM, 0);
  delay(1000);

  Serial.println("Motor quay chiều trái");
  analogWrite(RPWM, 0);
  analogWrite(LPWM, 200);
  delay(3000);

  Serial.println("Dừng");
  analogWrite(RPWM, 0);
  analogWrite(LPWM, 0);
  delay(2000);
}
