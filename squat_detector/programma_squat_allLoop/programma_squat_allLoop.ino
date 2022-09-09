#define echoPin 1 //pin fisico 6
#define trigPin 2  //pin fisico 7
#define button 3 //pin fisico 2
#define sound 4 //pin fisico 3
int distance = 0;
int distanceVar = 0;
boolean activated = false;
int count = 0;

void setup()
{
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);   
    pinMode(button, INPUT);
    pinMode(sound, OUTPUT); 
}

void loop()
{
    while(count == 0)
    {
        if(digitalRead(button) == LOW)
        {
            count = 1;
            digitalWrite(trigPin, LOW);
            delayMicroseconds(20);
            digitalWrite(trigPin, HIGH);
            delayMicroseconds(30);  //Attivo il trig per 15 uS
            digitalWrite(trigPin, LOW);
            long tempo = pulseIn(echoPin, HIGH);
            distance = (tempo * 0.034) / 2;
        }
    } 

    
    digitalWrite(trigPin, LOW);
    delayMicroseconds(10);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(40);  //Attivo il trig per 15 uS
    digitalWrite(trigPin, LOW);
    long tempo = pulseIn(echoPin, HIGH);
    distanceVar = (tempo * 0.034) / 2;
    
    if (distanceVar < distance + 5  && distanceVar > distance - 5)
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
