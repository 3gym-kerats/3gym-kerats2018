int trigPin1 = 2;
int echoPin1 = 3;

int trigPin2 = 5;
int echoPin2 = 6;

void setup() {
  
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);

  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

}

void beepFirst(){
   // play a note on pin 10 
  tone(10, 340, 100);
  delay(30);
  // turn off tone function for pin 10:
  noTone(10);
}

void beepSecond(){
   // play a note on pin 10 
  tone(10, 240, 100);
  delay(20);
  // turn off tone function for pin 10:
  noTone(10);
}


void firstsensor(){ // This function is for first sensor.
  int duration1, distance1;
  digitalWrite (trigPin1, HIGH);
  delayMicroseconds (10);
  digitalWrite (trigPin1, LOW);
  duration1 = pulseIn (echoPin1, HIGH);
  distance1 = (duration1/2) / 29.1;


  if (distance1 >=65) {  // Change the number for long or short distances.
     beepFirst();
  } else {
//-----
  }   
}

void secondsensor(){ // This function is for second sensor.
    int duration2, distance2;
    digitalWrite (trigPin2, HIGH);
    delayMicroseconds (10);
    digitalWrite (trigPin2, LOW);
    duration2 = pulseIn (echoPin2, HIGH);
    distance2 = (duration2/2) / 29.1;

  
    if (distance2 <=60) {  // Change the number for long or short distances.
     beepSecond();
    }
 else {
//-----
    }   
}

void loop() {
  
firstsensor();
delay(150);
secondsensor();
delay(150);
}
