void setup() {
pinMode(2,INPUT);
pinMode(3,OUTPUT);
}

void loop() {
int a = digitalRead(2);
if(a == HIGH){
  digitalWrite(3,LOW);
}
else{
  digitalWrite(3,HIGH);
}
}
