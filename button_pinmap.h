#ifndef BUTTON_PINMAP_H
#define BUTTON_PINMAP_H
#include <xc.h>

#define BUTTON_UP    PORTEbits.RE0
#define BUTTON_OK    PORTEbits.RE2
#define BUTTON_DOWN  PORTEbits.RE3

static inline void buttons_ports_init(void) {
    ANSELE &= ~((1u<<0) | (1u<<2) | (1u<<3)); // Digital mode for RE0, RE2, RE3
    TRISEbits.TRISE0 = 1; // RE0 input
    TRISEbits.TRISE2 = 1; // RE2 input
    TRISEbits.TRISE3 = 1; // RE3 input
    // PORTE does NOT have internal weak pull-ups on PIC18F45K22
    // So you need external resistors or handle active-high logic
}
#endif

