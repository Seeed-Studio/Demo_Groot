#include <avr/wdt.h>
#define wdt_init(X)     wdt_enable(X)
#define feed()          wdt_reset()

#include <Servo.h> 
#define pos_begin  80
#define pos_end    100

const int pin_sound = A5;
Servo myservo;  
 
int potpin = A5;  
int val;    


const long interval = 50;
unsigned long previousMillis = 0;
unsigned long currentMillis  = 0;


void setup()
{
	wdt_init(WDTO_2S);   
	feed();
	myservo.attach(5); 
	previousMillis = millis();
	Serial.begin(9600);
	myservo.write(90); 
}


void loop()
{	
	currentMillis = millis();
	if(currentMillis - previousMillis > interval)
 	{	
	feed();
		int val_sound = (analogRead(pin_sound));
		//Serial.println (val_sound);
		if ((val_sound > 150)&&(val_sound < 200))
		{		 		
			myservo.write(pos_begin - 10);   
			delay(5*10);
			myservo.write(pos_end + 10);  	
			delay(5*10);
		}	
		if ((val_sound > 200)&&(val_sound < 300))
		{		 
			myservo.write(pos_begin);   
			delay(5*20);
			myservo.write(pos_end);  	
			delay(5*20);
		}	
		if ((val_sound > 300)&&(val_sound < 350))
		{		 		
			myservo.write(pos_begin - 10);   
			delay(5*40);
			myservo.write(pos_end + 10);  	
			delay(5*40);
		}	
		if ((val_sound > 350)&&(val_sound < 400))
		{		 	
			myservo.write(pos_begin - 20);   
			delay(5*60);
			myservo.write(pos_end + 20);  	
			delay(5*60);
		}	
		if ((val_sound > 400)&&(val_sound < 450))
		{		 		
			myservo.write(pos_begin - 30);   
			delay(5*80);
			myservo.write(pos_end + 30);  	
			delay(5*80);
		}
		currentMillis = millis();
		previousMillis = currentMillis;
	}	
}