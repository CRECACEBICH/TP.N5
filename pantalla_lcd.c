#include "mbed.h"
#include "MKL25Z4.h"
#include "lcd.h"
#include "delay.h"

void setup(){
    lcd_inicio();
    lcd_borrar();
}

void loop(){
    lcd_comando(0x80);
    lcd_imprimir("El peluca");
    delay(1000);
    lcd_comando(0xC0);
    lcd_imprimir("SAAPE");
    delay(1000);
}
