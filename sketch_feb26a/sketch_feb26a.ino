#include <avr/io.h>
#include <avr/interrput.h>

ISR(INT0_vect)
{
  PORTC=PORTC ^ (1<<PC0);
}
void INT0_Init(void)
{
  SREG &=~(1<<7);
  DDRD &=(~(1<<PD2));
  EIMSK |=(1<<INT0);
  ETCRA |=(1<<ISC00) | (1<<ISC01);
  SREG |=(1<<7); 
}
void setup() {
  // put your setup code here, to run once:
  INT0_Init();
  DDRC=DDRC | (1<<PC0);
  PORTC = PORTC | (1<<PC0);


}

void loop() {
  // put your main code here, to run repeatedly:

}
