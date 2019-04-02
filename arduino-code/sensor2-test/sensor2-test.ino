
int trigPin2 = 12;
int echoPin2 = 11;
int duration = 100 ;


void setup() {
   Serial.begin (9600);

  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(13, OUTPUT);   // setting the pin modes, the "13" buzer  
  
}

void beep(){
   // παίξε έναν τόνο στον ακροδέκτη 13
  tone(13, 340, duration);
  delay(duration);
  // απενεργοποιήστε τη λειτουργία τόνου για τον ακροδέκτη 13
  noTone(13);
}




void sensor2(){ //Αυτή η λειτουργία είναι για τον δεύτερο αισθητήρα , του πεζοδρόμιου
    int duration2, distance2;
    digitalWrite (trigPin2, HIGH);
    delayMicroseconds (10);
    digitalWrite (trigPin2, LOW);
    duration2 = pulseIn (echoPin2, HIGH);
    distance2 = (duration2/2) / 29.1;
      Serial.print("2nd Sensor: ");
      Serial.print(distance2); 
      Serial.print("cm    ");  
    if (distance2 <=15 && distance2 >=1) {  // Αλλάξτε τον αριθμό για μεγάλες ή μικρές αποστάσεις.
     duration = 600;
     beep();
    } else if (distance2 <=40 && distance2 >=16) {  // Αλλάξτε τον αριθμό για μεγάλες ή μικρές αποστάσεις.
      delay(250);
     duration = 300;
     beep();   
     } else if (distance2 <=65 && distance2 >=41) {  // Αλλάξτε τον αριθμό για μεγάλες ή μικρές αποστάσεις.
      delay(500);
     duration = 50;
     beep();    
    } else {
      // Μην κάνεις τίποτα
  }  
 }

void loop() {
Serial.println("\n");
sensor2(); //ανιχνευση πεζοδρομιων
delay(150);

}
