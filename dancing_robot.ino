#define ENA 5
#define IN1 8
#define IN2 9

#define ENB 6
#define IN3 10
#define IN4 11

#define SPEED 255

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  randomSeed(analogRead(A0));

  stopCar();
}

void loop() {

  int moveType = random(0, 6);

  switch (moveType) {

    case 0:
      forward();
      delay(random(500, 2500));
      break;

    case 1:
      backward();
      delay(random(500, 2500));
      break;

    case 2:
      left();
      delay(random(300, 1800));
      break;

    case 3:
      right();
      delay(random(300, 1800));
      break;

    case 4:
      rotateLeft();
      delay(random(700, 2200));
      break;

    case 5:
      rotateRight();
      delay(random(700, 2200));
      break;
  }

  // Small random pause
  stopCar();
  delay(random(100, 700));
}


// ---------- FORWARD ----------
void forward() {
  analogWrite(ENA, SPEED);
  analogWrite(ENB, SPEED);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}


// ---------- BACKWARD ----------
void backward() {
  analogWrite(ENA, SPEED);
  analogWrite(ENB, SPEED);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}


// ---------- LEFT ----------
void left() {
  analogWrite(ENA, SPEED);
  analogWrite(ENB, SPEED);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}


// ---------- RIGHT ----------
void right() {
  analogWrite(ENA, SPEED);
  analogWrite(ENB, SPEED);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}


// ---------- ROTATE LEFT ----------
void rotateLeft() {
  analogWrite(ENA, SPEED);
  analogWrite(ENB, SPEED);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}


// ---------- ROTATE RIGHT ----------
void rotateRight() {
  analogWrite(ENA, SPEED);
  analogWrite(ENB, SPEED);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}


// ---------- STOP ----------
void stopCar() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
