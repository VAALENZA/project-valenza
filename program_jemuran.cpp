#include <Servo.h>

Servo servoJemuran;

// Pin
const int pinSensor = A0;
const int pinServo  = 8;
const int pinLED    = 2;

// Atur posisi servo
const int posisiBuka  = 0;
const int posisiTutup = 90;

// Batas sensor hujan
const int batasHujan = 500;

// Menyimpan kondisi jemuran
bool jemuranTertutup = false;

void setup() {
  Serial.begin(9600);

  pinMode(pinSensor, INPUT);
  pinMode(pinLED, OUTPUT);

  servoJemuran.attach(pinServo);

  // Kondisi awal
  servoJemuran.write(posisiBuka);
  digitalWrite(pinLED, LOW);

  Serial.println("Sistem Jemuran Otomatis");
  Serial.println("------------------------");
}

void loop() {

  int nilaiSensor = analogRead(pinSensor);

  Serial.print("Nilai Sensor: ");
  Serial.println(nilaiSensor);

  // Jika sensor terkena air / hujan
  if (nilaiSensor < batasHujan) {

    if (!jemuranTertutup) {

      Serial.println("HUJAN TERDETEKSI");
      Serial.println("Jemuran ditutup");

      digitalWrite(pinLED, HIGH);

      servoJemuran.write(posisiTutup);

      jemuranTertutup = true;][[][]\0
      ]
    }

  }

  // Jika tidak hujane999
  else {

    if (jemuranTertutup) {

      Serial.println("TIDAK HUJAN");
      Serial.println("Jemuran dibuka");

      digitalWrite(pinLED, LOW);

      servoJemuran.write(posisiBuka);

      jemuranTertutup = false;
    }
  }

  delay(500);
} 