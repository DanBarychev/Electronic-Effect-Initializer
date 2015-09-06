#include <LiquidCrystal.h>

LiquidCrystal lcd (10, 9, 5, 4, 3, 2);

int reply;
 
const int opto = 12;

const int opto2 = 11;

const int knockSensor = A0;     

const int knockSensor2 = A1;

const int knockSensor3 = A2;

boolean distortion = false;

boolean chorus = false;

boolean bothEffects = false;

byte val;

byte val2;

byte val3;

int LOWTHRESHOLD = 10;

int HIGHTHRESHOLD = 300;


void setup() {
  
 lcd.begin(16, 2);
 
 lcd.print("Chorus Off");
 
 lcd.setCursor(0, 1);
 
 lcd.print("Distortion Off");
 
 pinMode(opto, OUTPUT); 
 
 pinMode(opto2, OUTPUT);

 digitalWrite (opto, LOW);
 
 digitalWrite (opto2, HIGH);
 
 distortion = false;
 
 chorus = false;
 
 Serial.begin(9600);

}



void loop() {
  
  val = analogRead(knockSensor); //Reading piezo closer to the neck

  val2 = analogRead(knockSensor2);
  
  val3 = analogRead(knockSensor3);
  
  if (val >= 25) //Effect 1 (chorus)
  { 
    Serial.println(val);
    
     if(!chorus)
     {       
       digitalWrite(opto, HIGH);
       
       delay(50);
       
       digitalWrite(opto, LOW);
       
       lcd.clear();
       
       lcd.print("Chorus On");
       
       chorus = true;
       
       if(!distortion)
       {
         lcd.setCursor(0, 1);
         
         lcd.print("Distortion Off");
       }
       
       else
       {
         lcd.setCursor(0, 1);
         
         lcd.print("Distortion On");
       }
     }
  
     else 
     {
       digitalWrite(opto, HIGH);
       
       delay(50);
       
       digitalWrite(opto, LOW);
       
       lcd.clear();
       
       lcd.print("Chorus Off");
       
       chorus = false;
       
       if(!distortion)
       {
         lcd.setCursor(0, 1);
         
         lcd.print("Distortion Off");
       }
       
       else
       {
         lcd.setCursor(0, 1);
         
         lcd.print("Distortion On");
       }
        
     }
  
  }
  
  if (val2 >= 25) //Effect 2 (distortion)
  {    
    Serial.println(val2);
    
     if(!distortion)
     {       
       digitalWrite(opto2, LOW);

       lcd.clear();
       
       lcd.setCursor(0, 1);
       
       lcd.print("Distortion On");
       
       distortion = true;
       
       if(!chorus)
       {         
         lcd.setCursor(0, 0);
         
         lcd.print("Chorus Off");
       }
       
       else
       {
         lcd.setCursor(0, 0);
         
         lcd.print("Chorus On");
       }
               
     }
  
     else 
     {       
       digitalWrite(opto2, HIGH);
       
       lcd.setCursor(0, 1);
       
       lcd.print("Distortion Off");
       
       distortion = false;
       
       if(!chorus)
       {         
         lcd.setCursor(0, 0);
         
         lcd.print("Chorus Off");
       }
       
       else
       {
         lcd.setCursor(0, 0);
         
         lcd.print("Chorus On");
       }
           
     }
  
  }
  
  if (val3 >= 15) //Turning both effects on and off
  {
   Serial.println(val3);
   
   if (!chorus && !distortion)
   {
   
   digitalWrite(opto, HIGH);
       
   delay(50);
       
   digitalWrite(opto,LOW);
   
   chorus = true;
   
   digitalWrite(opto2, LOW);

   distortion = true;
   
   lcd.clear();
   lcd.print("Chorus On");
   lcd.setCursor(0, 1);
   lcd.print("Distortion On");
   }
   else
   {
   digitalWrite(opto, HIGH);
       
   delay(50);
       
   digitalWrite(opto,LOW);
   
   chorus = false;
   
   digitalWrite(opto2, HIGH); 
   
   distortion = false;
   
   lcd.clear();
   lcd.print("Chorus Off");
   lcd.setCursor(0, 1);
   lcd.print("Distortion Off");
   }
  }

  delay(200);  

}
