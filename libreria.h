#ifndef lcd_h
#define lcd_h

#define registro_pin 0
#define readwrite_pin 1
#define habilitacion_pin 2
#define datos_pin 4

void lcd_inicio();
void lcd_borrar();
void lcd_comienzo();
void lcd_estcursor(int fil, int col);
void lcd_escribircaracter(char caracter);
void lcd_escribiroracion(const char oracion);
void lcd_crearcaracter(int posicion, const char posicionlcd);

#endif
