#define trigPin 1
#define echoPin 0
#define led 3
long distance = 0;
void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(30);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(30);  //Attivo il trig per 15 uS
  digitalWrite(trigPin, LOW);
  long tempo = pulseIn(echoPin, HIGH);
  distance = (tempo * 0.034) / 2;

  if (distance < 20)
  {
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
  }

}
