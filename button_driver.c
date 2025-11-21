#include <xc.h>
#include "button_pinmap.h"
#include "button_opcodes.h"

#define _XTAL_FREQ 20000000UL
#define DEBOUNCE_MS 30

uint8_t isPressedFalling_RC0(void) {
    static uint8_t prev = 1;
    uint8_t cur = BUTTON_UP;
    if (prev == 1 && cur == 0) {
        __delay_ms(DEBOUNCE_MS);
        if (BUTTON_UP == 0) { prev = 0; return 1; }
    }
    prev = cur;
    return 0;
}

uint8_t isPressedFalling_RC2(void) {
    static uint8_t prev = 1;
    uint8_t cur = BUTTON_OK;
    if (prev == 1 && cur == 0) {
        __delay_ms(DEBOUNCE_MS);
        if (BUTTON_OK == 0) { prev = 0; return 1; }
    }
    prev = cur;
    return 0;
}

uint8_t isPressedFalling_RC3(void) {
    static uint8_t prev = 1;
    uint8_t cur = BUTTON_DOWN;
    if (prev == 1 && cur == 0) {
        __delay_ms(DEBOUNCE_MS);
        if (BUTTON_DOWN == 0) { prev = 0; return 1; }
    }
    prev = cur;
    return 0;
}

void buttons_init(void) {
    buttons_ports_init();
}