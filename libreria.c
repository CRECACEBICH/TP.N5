#include "lcd.h"
#include "delay.h"

void lcd_comando(){
    data_pin= cmd;
    digitalWrite(rs_pin, LOW);
    digitalWrite(en_pin, HIGH);
    delay_us(1);
    digitalWrite(en_pin, LOW);
    delay_us(100);
}

void lcd_escribir(int data){
    data_pin= data;
    digitalWrite(rs_pin, HIGH);
    digitalWrite(en_pin, HIGH);
    delay_us(1);
    digitalWrite(en_pin, LOW);
    delay_us(100);
}

void lcd_inicio(){
    DDRB = 0xFF;
    pinMode(rs_pin, OUTPUT);
    pinMode(en_pin, OUTPUT);

    delay_ms(20);

    lcd_comando(0x38);
    lcd_comando(0x0E);
    lcd_comando(0x01);
    lcd_comando(0x06);
}

void lcd_imprimir(){
    void lcd_print(const char texto){
        while (texto){
        lcd_escribir(texto++);
        }
    }
}
