#include "main.h"

#include <stdio.h>

/**
* iditoa - converts integer to character.
* @num: int argument passed.
* @s: pointer to buffer.
* @base: base of int passed.
* Return: pointer to string.
*/

char *iditoa(long num, char *s, long base)

{

	long i = 0, neg = 0, r, n = num;

	if (n == 0)
	{
		s[0] = '0';
		s[1] = '\0';
	}
	if (n < 0 && base == 10)
	{
		neg = 1;
		n = -n;
	}

	while (n > 0)

	{
		r = n % base;
		if (r > 9)
			s[i] = (r - 10) + 'a';
		else
			s[i] = r + '0';
		n = n / base;
		i++;
	}

	if (neg == 1)
		s[i] = '-';
	if (s)
		reverse(s);
	return (s);
	free(s);
}

/**
* _atoi - converts char to int.
* @s: string to be converted.
* Return: int or 0;
*/

int _atoi(char *s)

{

	long negcounter = 0;
	long number;
	long maxnum = 2147483647;
	long minnum = -2147483648;

	while (*s)

	{

		if (*s == '-')
		{
			negcounter++;
			s++;
		}

		else if (*s >= '0' && *s <= '9')

		{
			number = *s - '0';
			s++;
			while (*s >= '0' && *s <= '9')

			{

				if (number + (*s - '0') > (maxnum / 10))
					return ((negcounter % 2 == 0) ? (maxnum) : (minnum));
				number = (number * 10) + (*s - '0');
				s++;
			}

			if (negcounter % 2 == 1)
				return (number * (-1));
			else
				return (number);
		}
		else
			s++;
	}
	return (0);
}

/**
* counter - counter the difference in space between % and specifier.
* @i: index.
* @f: format.
* @spec: struct of specifiers.
* Return: length or -1.
*/

int counter(int i, const char *f, s *spec)

{
	int len;
	int j;

	for (len = 0, i = i + 1; f[i] != '\0'; i++, len++)

	{
		for (j = 0; *spec[j].c != '\0'; j++)
		{
			if (f[i] == *spec[j].c)
			{
				return (len);
			}
		}
	}
	return (-1);
}

/**
* f_S - prints \x followed by two character hexidecimal for special characters/
* @args: arg passed.
* Return: pointer to char.
*/

char *f_S(va_list args, char *s __attribute__((unused)))

{
	char *tmp, *tmp2;
	int i = 0, j = 0, c = 0, r = 0, t = 0,  q = 0;
	char ch;

	tmp = va_arg(args, char *);
	if (!tmp)
		return (NULL);
	for (i = 0; tmp[i] != '\0'; i++)
		;
	for (j = 0; tmp[j] != '\0'; j++)
	{
		ch = tmp[j];
		if ((ch < 32 && ch > 0) || (ch >= 127))
			c++; }
	t = i + c * 3;
	tmp2 = malloc(sizeof(char) * (t + 1));
	if (!tmp2)
		return (NULL);
	if (tmp2)
	{
		for (i = 0, j = 0; tmp[j] != '\0'; i++, j++)
			{ ch = tmp[j];
			if ((ch < 32) || (ch >= 127))
				{  tmp2[i] = '\\';
				tmp2[i + 1] = 'x';
				q = ch / 16;
				r = ch % 16;
				if (q > 9)
					tmp2[i + 2] = q + 'A';
				else
					tmp2[i + 2] = q + '0';
				if (r > 9)
					tmp2[i + 3] = r + 'A';
				else
					tmp2[i + 3] = r + '0';
				i += 3; }
			else
				tmp2[i] = ch; }}
	tmp2[i] = '\0';
	return (tmp2); }
