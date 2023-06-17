//Master
uint8_t count;
uint8_t x;
void SPI_Init()
{

DDRB |= (1<<PB3) |(1<<PB5) |(1<<PB2); 
DDRB &= ~(1<<PB4);

PORTB = (1<<PB2);


SPCR = (1<<SPE) | (1<<MSTR) |(1<<SPR0);
SPSR &= ~(1<<SPI2X);



}

void SPI_Write(char data)
{
char flush_buffer;
SPDR = data;
// Serial.println((uint8_t)SPDR);
while (! (SPSR & (1<<SPIF)));

flush_buffer = SPDR; 
}

/* SPI read data function */

char SPI_Read(){
  SPDR = 0XFF; //??????????????????????
  while (! (SPSR & (1<<SPIF))){
    
  }
  return (SPDR);
}

void SS_Enable()
{
PORTB &= ~(1<<PB2);  
_delay_ms(1000);
}
void setup() {
  count=0;
SPI_Init();
SS_Enable();
Serial.begin(9600);
}

void loop() {
  if(count==101)
  count=0;
// Serial.println("Hi");
SPI_Write(count);
_delay_ms(2000);
x=(uint8_t)SPI_Read();
Serial.println(x);
_delay_ms(1000);
count=count+1;
}
