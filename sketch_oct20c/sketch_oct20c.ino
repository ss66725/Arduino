void setup() {
  pinMode(2, INPUT); 
  pinMode(3, OUTPUT); 
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

int pressCount = 0;
void loop() {
  int buttonState = digitalRead(2);
  if (buttonState == LOW){
    delay(20);
    while (digitalRead(2) == LOW){
    }
    pressCount++;

    if (pressCount == 1){
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
    }

    if (pressCount == 2){
      digitalWrite(4, HIGH);
      digitalWrite(3, LOW);
      digitalWrite(5, LOW);
    }

    if (pressCount == 3){
      digitalWrite(5, HIGH);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      pressCount = 0;
    }

    tone(6, 600 + pressCount* 150);
    delay(100);
    noTone(6);
    tone(6, 300 + pressCount* 150);
    delay(50);
    noTone(6);
  }
}

