#include "main.h"


/**
* f_b - sends arg to be converted to binary.
* @str: argument passed.
* @s: buffer passed.
* Return: pointer to buffer
*/

char *f_b(va_list str, char *s)

{

	s = itoa(va_arg(str, int), s, 2);

	return (s);

}

/**
* f_o - sends an arg to be converted to octal.
* @str: arg passed.
* @s: buffer passed.
* Return:pointer to buffer.
*/

char *f_o(va_list str, char *s)

{

	s = itoa(va_arg(str, int), s, 8);

	return (s);

}


/**
* f_x - sends an arg to be converted to lowercase hexidecimal.
* @str: srgument passed.
* @s: buffer passed.
* Return: pointer to buffer.
*/

char *f_x(va_list str, char *s)

{

	s = itoa(va_arg(str, int), s, 16);

	return (s);

}


/**
* f_X - sends an arg to be converted to uppwecase hexidecimal.
* @str: argument passed.
* @s: buffer passed.
* Return: pointer to buffer.
*/

char *f_X(va_list str, char *s)

{


	s = hex_X(va_arg(str, int), s, 16);

	return (s);

}

/**
* f_u - sends an unsigned arg to be converted to char.
* @s: buffer passed.
* @str: argument passed
* Return: pointer to buffer.
*/



char *f_u(va_list str, char *s)

{

	s = itoa(va_arg(str, int), s, 10);

	return (s);

}
