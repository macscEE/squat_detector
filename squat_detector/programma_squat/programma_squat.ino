#define echoPin 1 //pin fisico 6
#define trigPin 0  //pin fisico 5
#define button 2 //pin fisico 2
#define sound 4 //pin fisico 3
int distance = 0;
int distanceVar = 0;
boolean activated = false;
void setup()
{
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);   
    pinMode(button, INPUT);
    pinMode(sound, OUTPUT); 
    int count = 0;
    do
    {
        if(digitalRead(button) == LOW)
        {
            count = 1;
            digitalWrite(trigPin, LOW);
            delayMicroseconds(10);
            digitalWrite(trigPin, HIGH);
            delayMicroseconds(15);  //Attivo il trig per 15 uS
            digitalWrite(trigPin, LOW);
            long tempo = pulseIn(echoPin, HIGH);
            distance = (tempo * 0.034) / 2;
        }
    } while (count == 0);
}

void loop()
{
    digitalWrite(trigPin, LOW);
    delayMicroseconds(10);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(15);  //Attivo il trig per 15 uS
    digitalWrite(trigPin, LOW);
    long tempo = pulseIn(echoPin, HIGH);
    distanceVar = (tempo * 0.034) / 2;
    
    if (distanceVar < distance + 10  && distanceVar > distance - 10)
    { 
        digitalWrite(sound, HIGH);
        activated = true;
        delay(500);
    }

    if(activated)
    {
        activated = false;
        digitalWrite(sound, LOW);
    }
    
}
