#ifndef MAIN_H

#define MAIN_H



#include <stdlib.h>

#include <stdarg.h>





typedef struct s

{

	char *c;

	char *(*sp)(va_list, char *);



}s;



typedef struct f

{

	char *c;

	char *(*fl)(char *);

}f;





int _printf(const char *format, ...);

int counter(int i, const char *f, s *spec);

char *reverse(char *s);

char *itoa(unsigned int num, char *s, unsigned int base);

char *hex_X(unsigned int num, char *s, unsigned int base);

char *iditoa(long num, char *s, long base);



int _atoi(char *s);



char *f_s(va_list str, char *s);

char *f_c(va_list str, char *s);

char *f_r(va_list str, char *s);

char *f_id(va_list str, char *s);

char *f_o(va_list str, char *s);

char *f_b(va_list str, char*s);

char *f_u(va_list str, char*s);

char *f_x(va_list str, char*s);

char *f_X(va_list str, char*s);

char *f_R(va_list str, char*s);

char *f_S(va_list str, char*s);



int _putchar(char c);

char *f_plus(char *s);

char *f_space(char *s);

char *f_pres(char *s, char *num, char sp);

char *f_zero(char *s, char *num);

char *f_width(char *s, char *num, int neg);



char *hashparser(char *s, char spec);

char *hasher_x(char *s);

char *hasher_o(char *s);

char *hasher_X(char *s);



#endif
