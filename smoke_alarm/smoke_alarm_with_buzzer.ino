const int buzzer = 9; //buzzer to arduino pin 9

int redpin = 10;      //select the pin for the red LED
int greenpin = 11;    // select the pin for the green LED


void setup(){

    pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output
    Serial.begin(9600); // Set serial baud rate to 9600 bps
  
    pinMode(redpin, OUTPUT);
    pinMode(greenpin, OUTPUT);
  
}

void loop(){

    int val;
    val=analogRead(0);  //Read Gas value from analog 0
    Serial.println(val,DEC);  //Print the value to serial port in Decimal form

    if (int(val) > 500) {   // 500 seems to be the threshold for detecting a lighter held near the sensor, ring the buzzer
        buzzerCall();   
    }
    else {
        nobuzzer();         // turn off the buzzer if the value from the sensor is less then 500
    }
       
    delay(100);
}


void buzzerCall(){
    flashRedLight();
    tone(buzzer, 500);  // Send 1KHz sound signal...
    delay(1000);        // ...for 1 sec
    noTone(buzzer);     // Stop sound...
    delay(1000);        // ...for 1sec
}

void nobuzzer(){
    flashGreenLight();
    noTone(buzzer);     // turn off the alarm
}


void flashRedLight(){
      analogWrite(11,0);
      analogWrite(10, 254);
}

void flashGreenLight(){
      analogWrite(10,0);
      analogWrite(11, 254);
}
