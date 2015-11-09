#include <EEPROM.h>

const int tledPin = 0;  
const int buttonPin = 1;  
const int knobPin = 2;
const int yPin = 3;
const int rtrigPin = 4; 
const int ltrigPin = 5; 
const int ltrigPinout = 6; 
const int rtrigPinout = 7; 
const int yPinout = 8;
const int lledPin = 9; 
const int rledPin = 10; 

int resetyValue = 0;
int buttonState = 0;
int yValue = 0;
int ystate = 0;
int ltrigValue = 0;
int rtrigValue = 0;
int knobValue = 0;

int mode = 0;
int delValue = 0;

int p1 = 0; 
int s1 = 0;
int p2 = 0;
int s2 = 0;
int p3 = 0;
int s3 = 0;
int p4 = 0; 
int s4 = 0;
int p5 = 0;
int s5 = 0;
int p6 = 0;
int s6 = 0;

void setup() {
  pinMode(tledPin, OUTPUT);      
  pinMode(buttonPin, INPUT); 
  pinMode(yPin, INPUT); 
  pinMode(yPinout, OUTPUT);  
  pinMode(lledPin, OUTPUT);      
  pinMode(rledPin, OUTPUT);   
}

void loop() {
  yValue = digitalRead(yPin);
  
  if (yValue == HIGH) {
    digitalWrite(yPinout, HIGH);
    delay(40);
    digitalWrite(yPinout, LOW); 
    delay(250);
    ystate = ystate++;
    
    if(ystate == 2) {
      ystate = 0;
    }
  } 
  
  buttonState = analogRead(buttonPin);
  
  if (buttonState > 900 && buttonState < 950) {
    mode = mode++;
    
    if(mode == 10) {
      mode = 0;
    }
    
    if(mode == 0) {
      digitalWrite(lledPin, HIGH); 
      delay(250);             
      digitalWrite(lledPin, LOW);
    }
    
    if(mode == 1) {
      digitalWrite(rledPin, HIGH); 
      digitalWrite(lledPin, HIGH); 
      delay(250);             
      digitalWrite(rledPin, LOW);
      digitalWrite(lledPin, LOW);
    }
    
    if(mode == 2) {
      digitalWrite(rledPin, HIGH); 
      digitalWrite(lledPin, HIGH); 
      delay(250);             
      digitalWrite(rledPin, LOW);
      digitalWrite(lledPin, LOW);
      delay(250);             
      digitalWrite(lledPin, HIGH); 
      delay(250);             
      digitalWrite(lledPin, LOW);
    }
    
    if(mode == 3) {
      digitalWrite(rledPin, HIGH); 
      digitalWrite(lledPin, HIGH); 
      delay(250);             
      digitalWrite(rledPin, LOW);
      digitalWrite(lledPin, LOW);
      delay(250);             
      digitalWrite(rledPin, HIGH); 
      digitalWrite(lledPin, HIGH); 
      delay(250);             
      digitalWrite(rledPin, LOW);
      digitalWrite(lledPin, LOW);
    }
    
    if(mode == 4) {
      digitalWrite(rledPin, HIGH); 
      digitalWrite(lledPin, HIGH); 
      delay(250);             
      digitalWrite(rledPin, LOW);
      digitalWrite(lledPin, LOW);
      delay(250);             
      digitalWrite(rledPin, HIGH); 
      digitalWrite(lledPin, HIGH); 
      delay(250);             
      digitalWrite(rledPin, LOW);
      digitalWrite(lledPin, LOW);
      delay(250);             
      digitalWrite(lledPin, HIGH); 
      delay(250);             
      digitalWrite(lledPin, LOW);
      
    }
    
    if(mode == 5) {
      digitalWrite(rledPin, HIGH); 
      digitalWrite(lledPin, HIGH); 
      delay(250);             
      digitalWrite(rledPin, LOW);
      digitalWrite(lledPin, LOW);
      delay(250);             
      digitalWrite(rledPin, HIGH); 
      digitalWrite(lledPin, HIGH); 
      delay(250);             
      digitalWrite(rledPin, LOW);
      digitalWrite(lledPin, LOW);
      delay(250);             
      digitalWrite(rledPin, HIGH); 
      digitalWrite(lledPin, HIGH); 
      delay(250);             
      digitalWrite(rledPin, LOW);
      digitalWrite(lledPin, LOW);
    }
    
    if(mode == 6) {
      digitalWrite(rledPin, HIGH); 
      digitalWrite(lledPin, HIGH); 
      delay(100);             
      digitalWrite(rledPin, LOW);
      digitalWrite(lledPin, LOW);
      delay(100);             
      digitalWrite(rledPin, HIGH); 
      digitalWrite(lledPin, HIGH); 
      delay(100);             
      digitalWrite(rledPin, LOW);
      digitalWrite(lledPin, LOW);
      delay(100);             
      digitalWrite(rledPin, HIGH); 
      digitalWrite(lledPin, HIGH); 
      delay(100);             
      digitalWrite(rledPin, LOW);
      digitalWrite(lledPin, LOW);
      
    }
    if(mode == 7) {
      digitalWrite(lledPin, HIGH); 
      delay(100);             
      digitalWrite(lledPin, LOW);
      delay(100);             
      digitalWrite(rledPin, HIGH); 
      delay(100);             
      digitalWrite(rledPin, LOW);
      delay(100);             
      digitalWrite(lledPin, HIGH); 
      delay(100);             
      digitalWrite(lledPin, LOW);
      delay(100);             
      digitalWrite(rledPin, HIGH); 
      delay(100);             
      digitalWrite(rledPin, LOW);
      delay(100);             
      digitalWrite(lledPin, HIGH); 
      delay(100);             
      digitalWrite(lledPin, LOW);
      delay(100);             
      digitalWrite(rledPin, HIGH); 
      delay(100);             
      digitalWrite(rledPin, LOW);
    }
    if(mode == 8) {
      digitalWrite(lledPin, HIGH); 
      delay(100);             
      digitalWrite(lledPin, LOW);
      delay(100);             
      digitalWrite(lledPin, HIGH); 
      delay(100);             
      digitalWrite(lledPin, LOW);
      delay(100);             
      digitalWrite(lledPin, HIGH); 
      delay(100);             
      digitalWrite(lledPin, LOW);
    }
    if(mode == 9) {
      digitalWrite(rledPin, HIGH); 
      delay(100);             
      digitalWrite(rledPin, LOW);
      delay(100);             
      digitalWrite(rledPin, HIGH); 
      delay(100);             
      digitalWrite(rledPin, LOW);
      delay(100);             
      digitalWrite(rledPin, HIGH); 
      delay(100);             
      digitalWrite(rledPin, LOW);
    }
  } 
  
  if (buttonState > 600 && buttonState < 750) {  
    delay(400);
    
    knobValue = analogRead(knobPin); 


      digitalWrite(lledPin, HIGH); 
      digitalWrite(rledPin, HIGH); 
      delay(100);             
      digitalWrite(lledPin, LOW);
      digitalWrite(rledPin, LOW);
      
    if(mode == 0) {
     if(ystate == 0) {
        EEPROM.write(10, knobValue / 4 );
      } else {
        EEPROM.write(11, knobValue / 4 );
      }
    }
    
    if(mode == 1) {
     if(ystate == 0) {
        EEPROM.write(20, knobValue / 4 );
      } else {
        EEPROM.write(21, knobValue / 4 );
      }
    }
    
    if(mode == 2) {
     if(ystate == 0) {
        EEPROM.write(30, knobValue / 4 );
      } else {
        EEPROM.write(31, knobValue / 4 );
      }
    }
    
    if(mode == 3) {
     if(ystate == 0) {
        EEPROM.write(40, knobValue / 4 );
      } else {
        EEPROM.write(41, knobValue / 4 );
      }
    }
    
    if(mode == 4) {
     if(ystate == 0) {
        EEPROM.write(50, knobValue / 4 );
      } else {
        EEPROM.write(51, knobValue / 4 );
      }
    }
    
    if(mode == 5) {
     if(ystate == 0) {
        EEPROM.write(60, knobValue / 4 );
      } else {
        EEPROM.write(61, knobValue / 4 );
      }
    }
  }
  
  if (buttonState > 750 && buttonState < 900) {  
    ystate = 0;
  }
  
  if(ystate == 0) {
    digitalWrite(tledPin, HIGH); 
  }  


  if(ystate == 1) {
    digitalWrite(tledPin, LOW); 
  }  
  
  rtrigValue = analogRead(rtrigPin);
  ltrigValue = analogRead(ltrigPin);
  
  if(mode == 0) {
    int p1 = EEPROM.read(10) * 4; 
    int s1 = EEPROM.read(11) * 4;
    
    analogWrite(ltrigPinout, 0);
    
    if (rtrigValue < 465) {
      analogWrite(rtrigPinout, 0); 
      delay(40);
      analogWrite(rtrigPinout, 255);
      
      if(ystate == 0) {
        delValue = p1;
      } else {
        delValue = s1;
      }
      
      rtrigValue = analogRead(rtrigPin); 
      if (rtrigValue < 1) {
         delValue = 0; 
      }
      delay(delValue/5); 
      
      rtrigValue = analogRead(rtrigPin); 
      if (rtrigValue < 1) {
         delValue = 0; 
      }
      delay(delValue/5); 
      
      rtrigValue = analogRead(rtrigPin); 
      if (rtrigValue < 1) {
         delValue = 0; 
      }
      delay(delValue/5); 
      
      rtrigValue = analogRead(rtrigPin); 
      if (rtrigValue < 1) {
         delValue = 0; 
      }
      delay(delValue/5); 
      
      rtrigValue = analogRead(rtrigPin); 
      if (rtrigValue < 1) {
         delValue = 0; 
      }
      delay(delValue/5); 
      
    } else {
    analogWrite(rtrigPinout, 255);
    }
  }
  
  if(mode == 1) {
    int p2 = EEPROM.read(20) * 4; 
    int s2 = EEPROM.read(21) * 4;
    
    analogWrite(ltrigPinout, 0);
    
    if (rtrigValue < 465) {
      analogWrite(rtrigPinout, 0); 
      delay(40);
      analogWrite(rtrigPinout, 255);
      
      if(ystate == 0) {
        delValue = p2;
      } else {
        delValue = s2;
      }
      
      rtrigValue = analogRead(rtrigPin); 
      if (rtrigValue < 1) {
         delValue = 0; 
      }
      delay(delValue/5); 
      
      rtrigValue = analogRead(rtrigPin); 
      if (rtrigValue < 1) {
         delValue = 0; 
      }
      delay(delValue/5); 
      
      rtrigValue = analogRead(rtrigPin); 
      if (rtrigValue < 1) {
         delValue = 0; 
      }
      delay(delValue/5); 
      
      rtrigValue = analogRead(rtrigPin); 
      if (rtrigValue < 1) {
         delValue = 0; 
      }
      delay(delValue/5); 
      
      rtrigValue = analogRead(rtrigPin); 
      if (rtrigValue < 1) {
         delValue = 0; 
      }
      delay(delValue/5); 
      
    } else {
    analogWrite(rtrigPinout, 255);
    }
  }
  
  if(mode == 2) {
    int p3 = EEPROM.read(30) * 4; 
    int s3 = EEPROM.read(31) * 4;
    
    analogWrite(ltrigPinout, 0);
    
    if (rtrigValue < 465) {
      analogWrite(rtrigPinout, 0); 
      delay(40);
      analogWrite(rtrigPinout, 255);
      
      if(ystate == 0) {
        delValue = p3;
      } else {
        delValue = s3;
      }
      
      rtrigValue = analogRead(rtrigPin); 
      if (rtrigValue < 1) {
         delValue = 0; 
      }
      delay(delValue/5); 
      
      rtrigValue = analogRead(rtrigPin); 
      if (rtrigValue < 1) {
         delValue = 0; 
      }
      delay(delValue/5); 
      
      rtrigValue = analogRead(rtrigPin); 
      if (rtrigValue < 1) {
         delValue = 0; 
      }
      delay(delValue/5); 
      
      rtrigValue = analogRead(rtrigPin); 
      if (rtrigValue < 1) {
         delValue = 0; 
      }
      delay(delValue/5); 
      
      rtrigValue = analogRead(rtrigPin); 
      if (rtrigValue < 1) {
         delValue = 0; 
      }
      delay(delValue/5); 
      
    } else {
    analogWrite(rtrigPinout, 255);
    }
  }
  
  if(mode == 3) {
    int p4 = EEPROM.read(40) * 4; 
    int s4 = EEPROM.read(41) * 4;
    
    analogWrite(ltrigPinout, 0);
    
    if (rtrigValue < 465) {
      analogWrite(rtrigPinout, 0); 
      delay(40);
      analogWrite(rtrigPinout, 255);
      
      if(ystate == 0) {
        delValue = p4;
      } else {
        delValue = s4;
      }
      
      rtrigValue = analogRead(rtrigPin); 
      if (rtrigValue < 1) {
         delValue = 0; 
      }
      delay(delValue/5); 
      
      rtrigValue = analogRead(rtrigPin); 
      if (rtrigValue < 1) {
         delValue = 0; 
      }
      delay(delValue/5); 
      
      rtrigValue = analogRead(rtrigPin); 
      if (rtrigValue < 1) {
         delValue = 0; 
      }
      delay(delValue/5); 
      
      rtrigValue = analogRead(rtrigPin); 
      if (rtrigValue < 1) {
         delValue = 0; 
      }
      delay(delValue/5); 
      
      rtrigValue = analogRead(rtrigPin); 
      if (rtrigValue < 1) {
         delValue = 0; 
      }
      delay(delValue/5); 
      
    } else {
    analogWrite(rtrigPinout, 255);
    }
  }
  
  if(mode == 4) {
    int p5 = EEPROM.read(50) * 4; 
    int s5 = EEPROM.read(51) * 4;
    
    analogWrite(ltrigPinout, 0);
    
    if (rtrigValue < 465) {
      analogWrite(rtrigPinout, 0); 
      delay(40);
      analogWrite(rtrigPinout, 255);
      
      if(ystate == 0) {
        delValue = p5;
      } else {
        delValue = s5;
      }
      
      rtrigValue = analogRead(rtrigPin); 
      if (rtrigValue < 1) {
         delValue = 0; 
      }
      delay(delValue/5); 
      
      rtrigValue = analogRead(rtrigPin); 
      if (rtrigValue < 1) {
         delValue = 0; 
      }
      delay(delValue/5); 
      
      rtrigValue = analogRead(rtrigPin); 
      if (rtrigValue < 1) {
         delValue = 0; 
      }
      delay(delValue/5); 
      
      rtrigValue = analogRead(rtrigPin); 
      if (rtrigValue < 1) {
         delValue = 0; 
      }
      delay(delValue/5); 
      
      rtrigValue = analogRead(rtrigPin); 
      if (rtrigValue < 1) {
         delValue = 0; 
      }
      delay(delValue/5); 
      
    } else {
    analogWrite(rtrigPinout, 255);
    }
  }
  
  if(mode == 5) {
    int p6 = EEPROM.read(60) * 4; 
    int s6 = EEPROM.read(61) * 4;
    
    analogWrite(ltrigPinout, 0);
    
    if (rtrigValue < 465) {
      analogWrite(rtrigPinout, 0); 
      delay(40);
      analogWrite(rtrigPinout, 255);
      
      if(ystate == 0) {
        delValue = p6;
      } else {
        delValue = s6;
      }
      
      rtrigValue = analogRead(rtrigPin); 
      if (rtrigValue < 1) {
         delValue = 0; 
      }
      delay(delValue/5); 
      
      rtrigValue = analogRead(rtrigPin); 
      if (rtrigValue < 1) {
         delValue = 0; 
      }
      delay(delValue/5); 
      
      rtrigValue = analogRead(rtrigPin); 
      if (rtrigValue < 1) {
         delValue = 0; 
      }
      delay(delValue/5); 
      
      rtrigValue = analogRead(rtrigPin); 
      if (rtrigValue < 1) {
         delValue = 0; 
      }
      delay(delValue/5); 
      
      rtrigValue = analogRead(rtrigPin); 
      if (rtrigValue < 1) {
         delValue = 0; 
      }
      delay(delValue/5); 
      
    } else {
    analogWrite(rtrigPinout, 255);
    }
  }
  
  if(mode == 6) {
    if (rtrigValue < 465) {
      knobValue = analogRead(knobPin); 
      
      analogWrite(rtrigPinout, 0); 
      analogWrite(ltrigPinout, 255); 
      delay(40);
      analogWrite(rtrigPinout, 255);
      analogWrite(ltrigPinout, 0);
      
      rtrigValue = analogRead(rtrigPin); 
      if (rtrigValue < 1) {
         knobValue = 0; 
      }
      delay(knobValue/5); 
      
      rtrigValue = analogRead(rtrigPin); 
      if (rtrigValue < 1) {
         knobValue = 0; 
      }
      delay(knobValue/5); 
      
      rtrigValue = analogRead(rtrigPin); 
      if (rtrigValue < 1) {
         knobValue = 0; 
      }
      delay(knobValue/5); 
      
      rtrigValue = analogRead(rtrigPin); 
      if (rtrigValue < 1) {
         knobValue = 0; 
      }
      delay(knobValue/5); 
      
      rtrigValue = analogRead(rtrigPin); 
      if (rtrigValue < 1) {
         knobValue = 0; 
      }
      delay(knobValue/5); 
      
    } else {
    analogWrite(rtrigPinout, 255);
    analogWrite(ltrigPinout, 0);
    }
  }
  
  if(mode == 7) {
    if (rtrigValue < 465) {
      knobValue = analogRead(knobPin); 
      
      analogWrite(rtrigPinout, 0); 
      delay(40);
      analogWrite(rtrigPinout, 255);
      
      rtrigValue = analogRead(rtrigPin); 
      if (rtrigValue < 1) {
         knobValue = 0; 
      }
      delay(knobValue/5); 
      
      rtrigValue = analogRead(rtrigPin); 
      if (rtrigValue < 1) {
         knobValue = 0; 
      }
      delay(knobValue/4); 
      
      analogWrite(ltrigPinout, 255); 
      delay(40);
      analogWrite(ltrigPinout, 0);
      
      rtrigValue = analogRead(rtrigPin); 
      if (rtrigValue < 1) {
         knobValue = 0; 
      }
      delay(knobValue/4); 
      
      rtrigValue = analogRead(rtrigPin); 
      if (rtrigValue < 1) {
         knobValue = 0; 
      }
      delay(knobValue/4); 
    
    } else {
    analogWrite(rtrigPinout, 255);
    analogWrite(ltrigPinout, 0);
    }
  }
  
  if(mode == 8) {
    analogWrite(rtrigPinout, 255);
    
    if (ltrigValue < 655) {
      knobValue = analogRead(knobPin); 
      
      analogWrite(ltrigPinout, 255); 
      delay(40);
      analogWrite(ltrigPinout, 0);
      
      ltrigValue = analogRead(ltrigPin); 
      if (ltrigValue < 1) {
         knobValue = 0; 
      }
      delay(knobValue/5); 
      
      ltrigValue = analogRead(ltrigPin); 
      if (ltrigValue < 1) {
         knobValue = 0; 
      }
      delay(knobValue/5); 
      
      ltrigValue = analogRead(ltrigPin); 
      if (ltrigValue < 1) {
         knobValue = 0; 
      }
      delay(knobValue/5); 
      
      ltrigValue = analogRead(ltrigPin); 
      if (ltrigValue < 1) {
         knobValue = 0; 
      }
      delay(knobValue/5); 
      
      ltrigValue = analogRead(ltrigPin); 
      if (ltrigValue < 1) {
         knobValue = 0; 
      }
      delay(knobValue/5); 
      
    } else {
    analogWrite(ltrigPinout, 0);
   }
  }
  
   if(mode == 9) { 
    analogWrite(ltrigPinout, 0);
    
    if (rtrigValue < 465) {
      knobValue = analogRead(knobPin); 
      
      analogWrite(rtrigPinout, 0); 
      delay(40);
      analogWrite(rtrigPinout, 255);
      delay(knobValue/5);
      analogWrite(rtrigPinout, 0); 
      delay(40);
      analogWrite(rtrigPinout, 255);
      delay(knobValue/5);
      analogWrite(rtrigPinout, 0); 
      delay(40);
      analogWrite(rtrigPinout, 255);
      delay(knobValue/5);
      analogWrite(rtrigPinout, 0); 
      delay(40);
      analogWrite(rtrigPinout, 255);
      delay(knobValue/5);
      analogWrite(rtrigPinout, 0); 
      delay(40);
      analogWrite(rtrigPinout, 255);
      delay(knobValue/5);
      analogWrite(rtrigPinout, 0); 
      delay(40);
      analogWrite(rtrigPinout, 255);
      delay(800);
    } else {
    analogWrite(rtrigPinout, 0);
    }
   }
}