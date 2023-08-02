#include "mbed.h"
#include "MKL25Z4.h"
#include "lcd_h"
pantalla_lcd(0x27, 15, 4);

int main(){
 led.inicio();
 led.borrar();
 led.establecercursor(0, 0);
 led.imprimir("Hoy me levante con ganas de matar un par");
}