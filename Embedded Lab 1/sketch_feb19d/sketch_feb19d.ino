#include <avr/io.h>
//#include <util/delay.h>
void setup() {
  // put your setup code here, to run once:
  DDRD = 0;
  DDRC = 0XFF;
  counter = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  if(PIND & 0b00010000)
  {
    if(counter == 9)
    {
      counter=0;
    }

    counter = counter +1;
    
  }
  

  
}
