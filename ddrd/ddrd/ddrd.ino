#include <avr/io.h>
#include <util/delay.h>

void setup() {
  DDRB |= (1 << DDB5);
  DDRD &= ~(1 << DDD2);
  PORTD |= (1 << PORTD2);
}

void loop() {
  if (!(PIND & (1 << PIND2)))
    PINB = (1 << PINB5);
  delay(50);
}
