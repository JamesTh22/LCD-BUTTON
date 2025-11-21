#ifndef BUTTON_OPCODES_H
#define BUTTON_OPCODES_H
#include <stdint.h>

// Functions for button handling
void buttons_init(void);
void buttons_poll_1ms(void);
uint8_t button_pressed(uint8_t id);
uint8_t button_down(uint8_t id);

// Debounced helpers
uint8_t isPressedFalling_RC0(void);
uint8_t isPressedFalling_RC2(void);
uint8_t isPressedFalling_RC3(void);

#endif