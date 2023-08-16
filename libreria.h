#ifndef lcd_h
#define lcd_h
#define en_pin 1
#define rs_pin 2
#define data_pin PORTB

void lcd_comando();
void lcd_inicio();
void lcd_borrar();
void lcd_comienzo();
void lcd_escribir();
void imprimir();

#endif
