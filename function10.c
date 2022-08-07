#include "main.h"

/**
* reverse - reverses a string.
* @s: string to be reversed.
* Return: pointer to string.
*/

char *reverse(char *s)

{

	char tmp;

	int i, l;

	if (!s)

		return ("(null)");

	for (l = 0; s[l] != '\0'; l++)

		;

	l = l - 1;

	for (i = 0; i < l; i++, l--)

	{

		tmp = s[i];

		s[i] = s[l];

		s[l] = tmp;

	}

	return (s);

}

/**
* f_c - returns a character.
* @s: buffer that saves char.
* @str: argument passed.
* Return: pointer to character.
*/

char *f_c(va_list str, char *s)

{

	*s = (va_arg(str, int));

	return (s);

}

/**
* f_s - returns string passed.
* @str: string passed.
* @s: buffer saving string.
* Return: pointer to string.
*/

char *f_s(va_list str, char *s)

{

	char *tmp, *tmp2;

	int i, l;

	free(s);

	tmp = va_arg(str, char*);

	for (l = 0; tmp[l] != '\0'; l++)

		;

	if (!tmp)

		tmp2 = "\0";

	for (i = 0; tmp[i] != '\0'; i++)

		;

	tmp2 = malloc(sizeof(char) * i + 1);

	if (!tmp)

		return (NULL);

	for (i = 0; tmp[i] != '\0'; i++)

		tmp2[i] = tmp[i];

	tmp2[i] = '\0';

	return (tmp2);

	free(tmp);

	free(tmp2);

}

/**
* f_r - function that sends a string to be reversed.
* @str: string passed.
* @s: buffer passed.
* Return: pointer to reversed string.
*/

char *f_r(va_list str, char *s)

{

	char *tmp, *tmp2;

	int i;

	free(s);

	tmp = va_arg(str, char*);

	if (!tmp)

		tmp2 = "(null)";

	for (i = 0; tmp[i] != '\0'; i++)

		;

	tmp2 = malloc(sizeof(char) * (i + 1));

	if (!tmp2)

		return (NULL);

	for (i = 0; tmp[i] != '\0'; i++)

		tmp2[i] = tmp[i];

	tmp2[i] = '\0';

	reverse(tmp2);

	return (tmp2);

}

/**
* f_id - sends an integer or digit to iditoa fucntion.
* @s: buffer to store s.
* @str: int/digit passed.
* Return: pointer to buffer.
*/

char *f_id(va_list str, char *s)

{

	s = iditoa(va_arg(str, int), s, 10);

	return (s);

}
