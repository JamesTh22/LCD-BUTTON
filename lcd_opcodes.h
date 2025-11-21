#ifndef LCD_OPCODES_H
#define LCD_OPCODES_H

#include <stdint.h>

// LCD command opcodes
#define LCD_OPCODE_CLEAR             0x01
#define LCD_OPCODE_HOME              0x02
#define LCD_OPCODE_ENTRY_MODE        0x04
#define LCD_OPCODE_DISPLAY_CTRL      0x08
#define LCD_OPCODE_SHIFT             0x10
#define LCD_OPCODE_FUNCTION_SET      0x20
#define LCD_OPCODE_SET_CGRAM         0x40
#define LCD_OPCODE_SET_DDRAM         0x80

#define LCD_OPCODE_ENTRY_INC         0x02
#define LCD_OPCODE_ENTRY_DEC         0x00
#define LCD_OPCODE_ENTRY_SHIFT_ON    0x01
#define LCD_OPCODE_ENTRY_SHIFT_OFF   0x00

#define LCD_OPCODE_DISPLAY_ON        0x04
#define LCD_OPCODE_DISPLAY_OFF       0x00
#define LCD_OPCODE_CURSOR_ON         0x02
#define LCD_OPCODE_CURSOR_OFF        0x00
#define LCD_OPCODE_BLINK_ON          0x01
#define LCD_OPCODE_BLINK_OFF         0x00

#define LCD_OPCODE_8BIT              0x10
#define LCD_OPCODE_4BIT              0x00
#define LCD_OPCODE_2LINE             0x08
#define LCD_OPCODE_1LINE             0x00
#define LCD_OPCODE_FONT_5x10         0x04
#define LCD_OPCODE_FONT_5x8          0x00

// API prototypes
void port_initialize_lcd(void);
void lcd_initialize_power_up(void);

void lcd_command(unsigned char data);
void lcd_write_to(unsigned char data);

void lcd_clear(void);
void lcd_display_on(void);
void lcd_display_off(void);
void lcd_cursor_on(void);
void lcd_cursor_off(void);
void lcd_blink_on(void);
void lcd_blink_off(void);
void lcd_init(void);
void lcd_home(void);
void lcd_goto(uint8_t col, uint8_t row);
void lcd_putc(char c);
void lcd_puts(const char *s);
void lcd_puts_at(uint8_t col, uint8_t row, const char *s);
void lcd_clear_line(uint8_t row);

#endif

