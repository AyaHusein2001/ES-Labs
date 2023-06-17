//Slave
uint8_t count;

void SPI_Init()
{

DDRB &= ~(1<<PB3) |(1<<PB5) |(1<<PB2); 
DDRB |= (1<<PB4);

SPCR = (1<<SPE);


}

void SPI_Send(char data)
{
char flush_buffer:
SPDR = data;
while (! (SPSR & (1<<SPIF)));

flush_buffer = SPDR; 
}

char SPI_Recieve(){

  while (! (SPSR & (1<<<SPIF)))
  return (SPDR);
}


void setup() {
SPI_Init();

serial.begin(9600);
count=0;
}

void loop() {
count=(uint8_t)SPI_Recieve(); 
Serial.println(count);
count=count+100;
_delay_ms(1000);
SPI_Send((char)count);
_delay_ms(1000);


}
