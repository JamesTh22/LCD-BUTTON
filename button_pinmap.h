#ifndef BUTTON_PINMAP_H
#define BUTTON_PINMAP_H
#include <xc.h>

#define BUTTON_UP    PORTCbits.RC7
#define BUTTON_OK    PORTCbits.RC6
#define BUTTON_DOWN  PORTCbits.RC5

static inline void buttons_ports_init(void) {
    ANSELC &= ~((1u<<7) | (1u<<6) | (1u<<5)); // Digital mode for RC7, RC6, RC5
    TRISCbits.TRISC7 = 1; // RC7 input
    TRISCbits.TRISC6 = 1; // RC6 input
    TRISCbits.TRISC5 = 1; // RC5 input
    // Enable weak pull-ups for Port C
    WPUB = 0x00; // Disable Port B pull-ups (not needed)
    INTCON2bits.RBPU = 0; // Enable weak pull-ups globally
}
#endif

