#include "main.h"


/**
* f_space - adds a single space in front of positive numbers..
* @s: string passed.
* Return: pointer to string.
*/


char *f_space(char *s)

{


	int i, j;

	char *tmp;

	if (s[0] == '-')

		return (s);


	if ((s[0] >= '0' && s[0] <= '9'))

	{

		for (i = 0; s[i] != '\0'; i++)
			;
		tmp = malloc(sizeof(char) * (i + 2));

		if (!tmp)
			return (NULL);
		tmp[0] = ' ';
		for (i = 0, j = 1; s[i] != '\0'; i++, j++)
			tmp[j] = s[i];
		tmp[j] = '\0';
		free(s);
		return (tmp);
	}
	else
		return (s);
}


/**
* f_plus - adds a sign in front of positive numbers.
* @s: string passed.
* Return: pointer to string.
*/

char *f_plus(char *s)

{
	int i, j;
	char *tmp;

	if (!s)
		return (s);
	if (s[0] == '-')
		return (s);
	if (!(s[0] >= '0' && s[0] <= '9'))
		return (s);
	for (i = 0; s[i] != '\0'; i++)
		;
	tmp = malloc(sizeof(char) * (i + 2));
	if (!tmp)
		return (NULL);
	tmp[0] = '+';
	for (j = 1, i = 0; s[i] != '\0'; i++, j++)
		tmp[j] = s[i];
	tmp[j] = '\0';
	free(s);
	return (tmp);
}



/**
* f_R - rotates each character over 13 places.
* @s: buffer passed.
* @str: argument passed.
* Return: pointer to string.
*/

char *f_R(va_list str, char *s)

{
	char *tmp, *tmp2;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	int i, j;

	tmp = (va_arg(str, char *));
	if (!tmp)
		tmp2 = "(null)";
	for (i = 0; tmp[i] != '\0'; ++i)
		;
	tmp2 = malloc(sizeof(char) * (i + 1));
	if (!tmp2)
		return (NULL);
	for (i = 0; tmp[i] != '\0'; i++)
		tmp2[i] = tmp[i];
	tmp2[i] = '\0';
	for (i = 0; tmp2[i] != '\0'; i++)
		for (j = 0; in[j] != '\0'; j++)
		{

			if (tmp2[i] == in[j])
			{
				tmp2[i] = out[j];
				break;
			}
		}

	s = tmp2;
	return (s);
	free(tmp2);
}



/**
* itoa - converts integer to character.
* @num: int argument passed.
* @s: pointer to buffer.
* @base: base of int passed.
* Return: pointer to string.
*/

char *itoa(unsigned int num, char *s, unsigned int base)

{

	unsigned int i = 0, r, n = num;

	if (n == 0)

	{

		s[0] = '0';
		s[1] = '\0';

	}

	while (n > 0)

	{
		r = n % base;
		if (r > 9)
			s[i] = (r - 10) + 'a';
		else
			s[i] = r + '0';
		n = n / base;
		++i;
	}
	reverse(s);
	return (s);
	free(s);
}


/**
* hex_X - sends an int to be converted to hexidecimal upper char.
* @s: buffer passed.
* @num: number to be converted.
* @base: base of hexidecimal.
* Return: pointer to buffer.
*/



char *hex_X(unsigned int num, char *s, unsigned int base)

{

	unsigned int i = 0, r, n = num;

	if (n == 0)

	{
		s[0] = '0';
		s[1] = '\0';
	}

	while (n > 0)
	{
		r = n % base;
		if (r > 9)
			s[i] = (r - 10) + 'A';
		else
			s[i] = r + '0';
		n = n / base;
		i++;
	}
	reverse(s);
	return (s);
	free(s);
}
