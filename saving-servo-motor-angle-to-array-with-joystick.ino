#include <Servo.h>
Servo servo;
int x_axis;
int y_axis;
int record_button;
int play_button;
int counter = 0;
int i = 0;
int x = 0;
int record[10]={};
void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  servo.attach(4);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT);
  servo.write(0);
  Serial.begin(9600);
}

void loop() {

  record_button = digitalRead(2);
  play_button = digitalRead(3);
  x_axis = analogRead(A0);
  y_axis = analogRead(A1);

  if (x_axis > 0 && x_axis < 250) {
    counter = counter - 5;
    servo.write(counter);
    delay(30);
  }
  if (x_axis > 750 && x_axis < 1023) {
    counter = counter + 5;
    servo.write(counter);
    delay(30);
  }

  if (record_button == 0 && i < sizeof(record) / sizeof(record[0])) {
    delay(150);
    record[i] = counter;
    i++;
  }

  if (play_button == 1) {
    servo.write(0);
    delay(1000);
    for (x = 0; x < i; x++) {
      servo.write(record[x]);
      Serial.print("x ");
      Serial.println(record[x]);
      delay(1000);
    }

    delay(50);
    x = 0;
    servo.write(0);
  }

  if (counter > 180) {
    counter = 180;
  }
  if (counter < 0) {
    counter = 0;
  }

  Serial.print("counter ");
  Serial.println(counter);
  Serial.print("k ");
  Serial.println(x);
  Serial.print("i ");
  Serial.println(i);

  delay(50);
}
