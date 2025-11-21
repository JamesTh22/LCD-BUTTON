#ifndef BUTTON_PINMAP_H
#define BUTTON_PINMAP_H
#include <xc.h>

#define BUTTON_UP    PORTCbits.RC0
#define BUTTON_OK    PORTCbits.RC2
#define BUTTON_DOWN  PORTCbits.RC3

static inline void buttons_ports_init(void) {
    ANSELC &= ~((1u<<0) | (1u<<2) | (1u<<3)); // Digital mode for RC0, RC2, RC3
    TRISCbits.TRISC0 = 1; // RC0 input
    TRISCbits.TRISC2 = 1; // RC2 input
    TRISCbits.TRISC3 = 1; // RC3 input
    // Enable weak pull-ups for Port C
    WPUB = 0x00; // Disable Port B pull-ups (not needed)
    INTCON2bits.RBPU = 0; // Enable weak pull-ups globally
}
#endif

