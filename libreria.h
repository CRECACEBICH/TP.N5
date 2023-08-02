#ifndef lcd_h
#define lcd_h

#include <stdint.h>
#include "MKL25Z4.h"

#define LCD_LINE_ADDRESS 0x27

#define PORT_PCR_ODE_MASK (1u << 5)

#define LCD_COMMAND_LIMPIAR_DISPLAY 0x01
#define LCD_COMMAND_RETURN_HOME 0x02
#define LCD_COMMAND_DISPLAY_ON 0x0C
#define LCD_COMMAND_DISPLAY_OFF 0x08
#define LCD_COMMAND_CURSOR_ON 0x0E
#define LCD_COMMAND_CURSOR_OFF 0x0C
#define LCD_COMMAND_BLINK_ON 0x0F
#define LCD_COMMAND_BLINK_OFF 0x0C

#define LCD_NUM_FILAS 4
#define LCD_NUM_COLUMNAS 20

const uint8_t LCD_LINE_ADDRESS[LCD_NUM_FILAS];
#define LCD_SET_DD_RAM_ADDRESS 0x80

void lcd_inicio(void);

void lcd_imprimir(const char* text);

void lcd_limpiar();

void lcd_establecercursor(uint8_t fila, uint8_t columna);

#endif  
