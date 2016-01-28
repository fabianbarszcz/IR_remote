#include <IRremote.h>

int IRpin = 3;  // pin for the IR sensor
int LED1 = 7;    // LED pin  
int LED2 = 8;     // LED on pin 8
int LED3 = 10;  
int LED4 = 11;
int LED5 = 12;
int LED6 = 9;

IRrecv irrecv(IRpin);
decode_results results;
#define code1 16724175
#define code2 16718055
#define code3 16743045
#define code4 16716015
#define code5 16726215
#define code6 16734885
int z=300;    //delay 
int LED1on=0; // initializing LEDon as true
int LED2on=0;
int LED3on=0;
int LED4on=0;
int LED5on=0;
int LED6on=0;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  irrecv.blink13(true);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);  
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);  
}

void loop() 
{
   
  if (irrecv.decode(&results)) 
    {
     
      switch (results.value)
      {
          default:
            LED1on=0;
            delay(z); 
            break;
        
      case code1: 
      
        if(LED1on==0)
                {
                LED1on=1;
                digitalWrite(LED1, HIGH);
                delay(z); 
                }
         else 
                {
                 LED1on=0;
                 digitalWrite(LED1, LOW); 
                 delay(z); 
                }
        break;

      case code2: 
      
        if(LED2on==0)
                {
                LED2on=1;
                digitalWrite(LED2, HIGH);
                delay(z); 
                }
         else 
                {
                 LED2on=0;
                 digitalWrite(LED2, LOW); 
                 delay(z); 
                }
        break;

      case code3: 
    
      if(LED3on==0)
              {
              LED3on=1;
              digitalWrite(LED3, HIGH);
              delay(z); 
              }
       else 
              {
               LED3on=0;
               digitalWrite(LED3, LOW); 
               delay(z); 
              }
      break;

      case code4: 
    
      if(LED4on==0)
              {
              LED4on=1;
              digitalWrite(LED4, HIGH);
              delay(z); 
              }
       else 
              {
               LED4on=0;
               digitalWrite(LED4, LOW); 
               delay(z); 
              }
      break;
      
      case code5: 
    
      if(LED5on==0)
              {
              LED5on=1;
              digitalWrite(LED5, HIGH);
              delay(z); 
              }
       else 
              {
               LED5on=0;
               digitalWrite(LED5, LOW); 
               delay(z); 
              }
      break;

      case code6: 
    
      if(LED6on==0)
              {
              LED6on=1;
              digitalWrite(LED6, HIGH);
              delay(z); 
              }
       else 
              {
               LED6on=0;
               digitalWrite(LED6, LOW); 
               delay(z); 
              }
      break;
      }
      /*
      if (results.decode_type == NEC) {
      Serial.print("NEC: ");
      } else if (results.decode_type == SONY) {
        Serial.print("SONY: ");
      } else if (results.decode_type == RC5) {
        Serial.print("RC5: ");
      } else if (results.decode_type == RC6) {
        Serial.print("RC6: ");
      } else if (results.decode_type == UNKNOWN) {
        Serial.print("UNKNOWN: ");
      }
      
      Serial.println(results.value, DEC);*/
      irrecv.resume(); // Receive the next value 
    }

}

     
