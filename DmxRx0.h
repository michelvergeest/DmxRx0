/* DmxRx0 */
#ifndef _DMXRX0_H
#define _DMXRX0_H

#include <DmxRx.h>

extern "C" {
    void SIG_USART0_RECV (void) __attribute__((__always_inline__));
}


class DmxRx0 : public DmxRx
{

    friend void SIG_USART0_RECV (void);

public:
    void    begin();
};

extern DmxRx0 Dmx0Receiver;

#endif // _DMXRX0_H