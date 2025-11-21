#include <xc.h>
#include "lcd_opcodes.h"
#include "lcd_pinmap.h"
#include "button_opcodes.h"
#include "button_pinmap.h"

#define _XTAL_FREQ 20000000UL

#pragma config FOSC = HSHP
#pragma config PLLCFG = OFF
#pragma config PRICLKEN = ON
#pragma config WDTEN = OFF
#pragma config MCLRE = EXTMCLR
#pragma config LVP = OFF

void main(void) {
    lcd_init();
    buttons_init();

    lcd_puts_at(0, 0, "Ready");

    while (1) {
        if (isPressedFalling_RC2()) { // OK button
            lcd_puts_at(0, 0, "hello world");
            lcd_puts_at(0, 1, "06:45 ALM 07:00");
        }
        if (isPressedFalling_RC0()) { // UP button
            lcd_puts_at(0, 0, "pizza");
        }
        if (isPressedFalling_RC3()) { // DOWN button
            lcd_puts_at(0, 0, "burger");
        }
    }
}