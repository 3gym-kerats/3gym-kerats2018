
int duration = 100 ;
//This code is to use with FC51 IR proximity sensor, when it detects an obstacle it lights the internal LED
//of the Arduino Board, refer to Surtrtech for more information
const int ProxSensor=5; //Declaring where the Out pin from the sensor is wired

void setup() {
  Serial.begin (9600);
  pinMode(13, OUTPUT);   // setting the pin modes, the "13" buzer  
  pinMode(ProxSensor,INPUT); // then we have the out pin from the module
}

void beep(){
  // παίξε έναν τόνο στον ακροδέκτη 13
  tone(13, 340, duration);
  delay(duration);
  // απενεργοποιήστε τη λειτουργία τόνου για τον ακροδέκτη 13
  noTone(13);
}

 void sensor3() {
   if(digitalRead(ProxSensor)==HIGH)      //Check the sensor output if it's high
             {
      Serial.print("3nd Sensor: ");
      Serial.print(ProxSensor); 
      Serial.print("logic    "); 
     duration = 600;
     beep();
     } else {
             //Μην κάνεις τίποτα
     }
 }
void loop() {
Serial.println("\n");
sensor3();
delay(100);
}
