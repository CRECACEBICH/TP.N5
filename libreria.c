#include "lcd_h"
#include "MKL25Z4.h"

const uint8_t LCD_LINE_ADDRESS[LCD_NUM_FIL] = {0x00, 0x40};
#define LCD_SET_DD_RAM_ADDRESS 0x80

#define LCD_ADDR 0x27

void lcd_delay(void){
    volatile int i;
    for (i = 0; i < 50; i++){
        __asm("nop");
    }
}

void lcd_inicio(void){41
    lcd0_C1 |= lcdc_C1_MST_MASK | lcd_C1_TX_MASK;
    lcd_delay();
}

void lcd_inicio(void){
    SIM_SCGC4 |= SIM_SCGC4_I2C0_MASK;
    SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK;
    PORTB_PCR0 = PORT_PCR_MUX(2) | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;
    PORTB_PCR1 = PORT_PCR_MUX(2) | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;
    lcd0_C1 = 0;
    lcd0_C2 = 0;
    lcd0_F = 0x14;
    lcd0_C1 |= LCD_C1_IICEN_MASK;
    lcd_command(0x33);
    lcd_command(0x32);
    lcd_command(0x28);
    lcd_command(0x0C);
    lcd_command(0x06);
    lcd_command(0x01);
}

void lcd_establecercursor(uint8_t fila, uint8_t columna){
    uint8_t direccion = LCD_LINE_ADDRESS[fila] + columna;

    lcd_send_command(LCD_SET_DD_RAM_ADDRESS | direccion);
}

void lcd_imprimir(char mensaje){
    while (mensaje){
        lcd_send_character(mensaje++);
    }
}

void lcd_limpiar(){
    lcd_send_command(LCD_COMMAND_LIMPIAR_DISPLAY);
}#include "lcd_h"
#include "MKL25Z4.h"

const uint8_t LCD_LINE_ADDRESS[LCD_NUM_FIL] = {0x00, 0x40};
#define LCD_SET_DD_RAM_ADDRESS 0x80

#define LCD_ADDR 0x27

void lcd_delay(void){
    volatile int i;
    for (i = 0; i < 50; i++){
        __asm("nop");
    }
}

void lcd_inicio(void){41
    lcd0_C1 |= lcdc_C1_MST_MASK | lcd_C1_TX_MASK;
    lcd_delay();
}

void lcd_inicio(void){
    SIM_SCGC4 |= SIM_SCGC4_I2C0_MASK;
    SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK;
    PORTB_PCR0 = PORT_PCR_MUX(2) | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;
    PORTB_PCR1 = PORT_PCR_MUX(2) | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;
    lcd0_C1 = 0;
    lcd0_C2 = 0;
    lcd0_F = 0x14;
    lcd0_C1 |= LCD_C1_IICEN_MASK;
    lcd_command(0x33);
    lcd_command(0x32);
    lcd_command(0x28);
    lcd_command(0x0C);
    lcd_command(0x06);
    lcd_command(0x01);
}

void lcd_establecercursor(uint8_t fila, uint8_t columna){
    uint8_t direccion = LCD_LINE_ADDRESS[fila] + columna;

    lcd_send_command(LCD_SET_DD_RAM_ADDRESS | direccion);
}

void lcd_imprimir(char mensaje){
    while (mensaje){
        lcd_send_character(mensaje++);
    }
}

void lcd_limpiar(){
    lcd_send_command(LCD_COMMAND_LIMPIAR_DISPLAY);
}
