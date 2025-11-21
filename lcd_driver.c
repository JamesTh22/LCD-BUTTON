#include <xc.h>
#include <stdint.h>
#include "lcd_pinmap.h"
#include "lcd_opcodes.h"

#pragma config FOSC = HSHP
#pragma config PLLCFG = OFF
#pragma config PRICLKEN = ON
#pragma config WDTEN = OFF
#pragma config MCLRE = EXTMCLR
#pragma config LVP = OFF

#define _XTAL_FREQ 20000000UL
#define LCD_COLS 16

void port_initialize_lcd(void) {
    ANSELB = 0x00;
    TRISB = 0x00;
    LATB = 0x00;
}

// Send a nibble
static inline void send_lcd_4bit(unsigned char data) {
    LCD_D4 = (data >> 0) & 0x01;
    LCD_D5 = (data >> 1) & 0x01;
    LCD_D6 = (data >> 2) & 0x01;
    LCD_D7 = (data >> 3) & 0x01;

    LCD_E = 1;
    __delay_us(1);
    LCD_E = 0;
    __delay_us(40);
}

void lcd_command(unsigned char data) {
    LCD_RS = 0;
    send_lcd_4bit(data >> 4);
    send_lcd_4bit(data);
    if (data == LCD_OPCODE_CLEAR || data == LCD_OPCODE_HOME) __delay_ms(2);
}

void lcd_write_to(unsigned char data) {
    LCD_RS = 1;
    send_lcd_4bit(data >> 4);
    send_lcd_4bit(data);
}

void lcd_clear(void) { lcd_command(LCD_OPCODE_CLEAR); }
void lcd_display_on(void) { lcd_command(LCD_OPCODE_DISPLAY_CTRL | LCD_OPCODE_DISPLAY_ON); }
void lcd_display_off(void) { lcd_command(LCD_OPCODE_DISPLAY_CTRL | LCD_OPCODE_DISPLAY_OFF); }
void lcd_cursor_on(void) { lcd_command(LCD_OPCODE_DISPLAY_CTRL | LCD_OPCODE_DISPLAY_ON | LCD_OPCODE_CURSOR_ON); }
void lcd_cursor_off(void) { lcd_command(LCD_OPCODE_DISPLAY_CTRL | LCD_OPCODE_DISPLAY_ON | LCD_OPCODE_CURSOR_OFF); }
void lcd_blink_on(void) { lcd_command(LCD_OPCODE_DISPLAY_CTRL | LCD_OPCODE_DISPLAY_ON | LCD_OPCODE_BLINK_ON); }
void lcd_blink_off(void) { lcd_command(LCD_OPCODE_DISPLAY_CTRL | LCD_OPCODE_DISPLAY_ON | LCD_OPCODE_BLINK_OFF); }

void lcd_putc(char c) { lcd_write_to((unsigned char)c); }

void lcd_puts(const char *s) {
    while (*s) lcd_putc(*s++);
}

void lcd_puts_at(uint8_t col, uint8_t row, const char *s) {
    lcd_goto(col, row);
    lcd_puts(s);
}

void lcd_clear_line(uint8_t row) {
    lcd_goto(0, row);
    for (uint8_t i = 0; i < LCD_COLS; i++) lcd_putc(' ');
    lcd_goto(0, row);
}

void lcd_home(void) {
    lcd_command(LCD_OPCODE_HOME);
    __delay_ms(2);
}

void lcd_goto(uint8_t col, uint8_t row) {
    static const uint8_t base[2] = {0x00, 0x40};
    lcd_command(LCD_OPCODE_SET_DDRAM | (base[row & 1] + (col & 0x0F)));
}

void lcd_initialize_power_up(void) {
    port_initialize_lcd();
    __delay_ms(50);
    LCD_RS = 0; LCD_E = 0;
    send_lcd_4bit(0x03); __delay_ms(5);
    send_lcd_4bit(0x03); __delay_us(150);
    send_lcd_4bit(0x03); __delay_us(150);
    send_lcd_4bit(0x02); __delay_us(150);
    lcd_command(LCD_OPCODE_FUNCTION_SET | LCD_OPCODE_4BIT | LCD_OPCODE_2LINE | LCD_OPCODE_FONT_5x8);
    lcd_command(LCD_OPCODE_DISPLAY_CTRL | LCD_OPCODE_DISPLAY_OFF);
    lcd_clear();
    lcd_command(LCD_OPCODE_ENTRY_MODE | LCD_OPCODE_ENTRY_INC | LCD_OPCODE_ENTRY_SHIFT_OFF);
    lcd_command(LCD_OPCODE_DISPLAY_CTRL | LCD_OPCODE_DISPLAY_ON | LCD_OPCODE_CURSOR_OFF | LCD_OPCODE_BLINK_OFF);
}

void lcd_init(void) {
    lcd_initialize_power_up();
}