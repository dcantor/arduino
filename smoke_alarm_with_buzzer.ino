const int buzzer = 9; //buzzer to arduino pin 9

void setup(){

    pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output
    Serial.begin(9600); //Set serial baud rate to 9600 bps

}

void loop(){

    //buzzerCall();

    int val;
    val=analogRead(0);  //Read Gas value from analog 0
    Serial.println(val,DEC);  //Print the value to serial port

    if (int(val) > 500) {
        buzzerCall();
    }
    else {
        nobuzzer();
    }
    
    
    delay(100);
}


void buzzerCall(){
    tone(buzzer, 500);  // Send 1KHz sound signal...
    delay(1000);        // ...for 1 sec
    noTone(buzzer);     // Stop sound...
    delay(1000);        // ...for 1sec
}

void nobuzzer(){
    noTone(buzzer);     // turn off the alarm
}
