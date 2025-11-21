#ifndef LCD_PINMAP_H
#define LCD_PINMAP_H

#include <xc.h>
#include <stdint.h>

#define LCD_RS   LATBbits.LATB4
#define LCD_E    LATBbits.LATB5
#define LCD_D4   LATBbits.LATB0
#define LCD_D5   LATBbits.LATB1
#define LCD_D6   LATBbits.LATB2
#define LCD_D7   LATBbits.LATB3

#endif