#include <avr/io.h>
#include <util/delay.h>
void setup() {
  // put your setup code here, to run once:
  DDRD = 0x40;
  PORTD = PORTD &(~(1<<PD6));
}

void loop() {
  // put your main code here, to run repeatedly:
  _delay_ms(1000);
  PORTD = PORTD |(1<<PD6);
  _delay_ms(1000);
  PORTD = PORTD &(~(1<<PD6));

}
