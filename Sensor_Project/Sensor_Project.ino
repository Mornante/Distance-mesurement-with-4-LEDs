#define trigPin 7
#define echoPin 6

#define Led1 11
#define Led2 10
#define Led3 9
#define Led4 8

long duration;
float distanceCM;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(Led1, LOW);
    digitalWrite(Led2, LOW);
    digitalWrite(Led3, LOW);
    digitalWrite(Led4, LOW);
    
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distanceCM = duration * 0.034/2;

   Serial.print("Distance: ");
   Serial.print(distanceCM);
   Serial.print(" cm - ");
   Serial. print('\n'); 

   if (distanceCM <= 40 && distanceCM >= 31){
    digitalWrite(Led4, HIGH);
    }else if (distanceCM <= 30 && distanceCM >= 21){
    digitalWrite(Led3, HIGH);
    digitalWrite(Led4, HIGH);
    }else if (distanceCM <= 20 && distanceCM >= 11){
    digitalWrite(Led2, HIGH);
    digitalWrite(Led3, HIGH);
    digitalWrite(Led4, HIGH);
    }else if (distanceCM <= 10 && distanceCM >= 1){
    digitalWrite(Led1, HIGH);
    digitalWrite(Led2, HIGH);
    digitalWrite(Led3, HIGH);
    digitalWrite(Led4, HIGH);
    }
   
   delay(100);
}
