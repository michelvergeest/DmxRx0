#include <DmxRx0.h>

// create instance
DmxRx0 Dmx0Receiver;

ISR (SIG_USART0_RECV)
{
    Dmx0Receiver.receive(UCSR0A, UDR0);
}

// init and enable uart
void DmxRx0::begin()
{

    //call base class function
    DmxRx::setMemory();

    cli();
    UBRR0 = DMXRX_BAUDRATE;
    UCSR0A |= DMXRX_UCSRA;
    UCSR0C |= DMXRX_UCSRC;  // 8N2
    UCSR0B |= DMXRX_UCSRB;  // enable rx interrupts
    sei();
}

