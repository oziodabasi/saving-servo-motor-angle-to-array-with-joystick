#include <Servo.h>
Servo nct;
int x_axis;
int y_axis;
int joy_buton;
int kayit_buton
int sayac = 0;
int i = 0;
int yeni = 0;

void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  nct.attach(4);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT);
  nct.write(0);
  Serial.begin(9600);
}

void loop() {

  joy_buton = digitalRead(2);
  kayit_buton = digitalRead(3);
  x_axis = analogRead(A0);
  y_axis = analogRead(A1);

  if (x_axis > 0 && x_axis < 250) {
    sayac = sayac - 5;
    nct.write(sayac);
    delay(30);
  }
  if (x_axis > 750 && x_axis < 1023) {
    sayac = sayac + 5;
    nct.write(sayac);
    delay(30);
  }

  if (joy_buton == 0 && i < sizeof(kayit) / sizeof(kayit[0])) {
    delay(200);
    kayit[i] = sayac;
    i++;
  }

  if (kayit_buton == 1) {
    nct.write(0);
    delay(1000);
    for (yeni = 0; yeni < i; yeni++) {
      nct.write(kayit[yeni]);
      Serial.print("yeni ");
      Serial.println(kayit[yeni]);
      delay(1000);
    }

    delay(50);
    yeni = 0;
    nct.write(0);
  }

  if (sayac > 180) {
    sayac = 180;
  }
  if (sayac < 0) {
    sayac = 0;
  }

  Serial.print("sayac ");
  Serial.println(sayac);
  Serial.print("k ");
  Serial.println(yeni);
  Serial.print("i ");
  Serial.println(i);

  delay(50);
}
