#include "main.h"
/**
*f_width - deal with width flag
*@s: char
*@num: char
*@neg: int
* Return: char
*/
char *f_width(char *s, char *num, int neg)
{
	int n = _atoi(num);
	int len, i, j;
	char *tmp;

	for (len = 0; s[len] != '\0'; len++)
		;
	if (len >= n)
		return (s);
	tmp = malloc(sizeof(char) * n);
	if (!tmp)
		return (NULL);
	if (neg == 1)
	{
		for (i = 0; s[i] != '\0'; i++)
			tmp[i] = s[i];
		for (; i < n; i++)
			tmp[i] = ' ';
		return (tmp);
		free(tmp);
	}
	else
	{
		for (i = 0; len < n; len++, i++)
			tmp[i] = ' ';
		for (j = 0; i < n; i++, j++)
			tmp[i] = s[j];
		return (tmp);
		free(tmp);
	}
}

/**
*f_pres - deal with precision flag
* @s: char
* @num: char
*@sp: string pointer
*Return: char
*/
char *f_pres(char *s, char *num, char sp)
{
	int n = _atoi(num);
	int len, i = 0, j;
	char *tmp = s;

	for (len = 0; s[len] != '\0'; len++)
		;
	if (len >= n)
	{
		if (sp == 's')
		{
			tmp = malloc(sizeof(char) * n);
		for (i = 0; i < n; i++)
			tmp[i] = s[i];
		return (tmp);
		}
		else
			return (s);
	}
	if (s[0] == '-')
	{
		tmp = malloc(sizeof(char) * n + 1);
		if (!tmp)
		return (NULL);
		tmp[0] = '-';
		n++;
		i = 1;
		for (; len < n; len++, i++)
			tmp[i] = '0';
		for (j = 1; i < n; i++, j++)
			tmp[i] = s[j];
		return (tmp);
	}
	else if (s[0] >= '0' && s[0] <= '9')
	{
		tmp = malloc(sizeof(char) * n);
		if (!tmp)
			return (NULL);
		for (; len < n; len++, i++)
			tmp[i] = '0';
		for (j = 0; i < n; i++, j++)
			tmp[i] = s[j];
		return (tmp);
	}
	return (s);
}
/**
*f_zero - deal with zero flag
*@s: char
*@num: char
*Return: char
*/
char *f_zero(char *s, char *num)
{
	int n = _atoi(num);
	int len, i = 0, j;
	char *tmp;

	for (len = 0; s[len] != '\0'; len++)
		;
	if (len >= n)
		return (s);
	tmp = malloc(sizeof(char) * n);
	if (!tmp)
		return (NULL);
	if (s[0] == '-')
	{
		tmp[0] = '-';
		i = 1;
		for (; len < n; len++, i++)
			tmp[i] = '0';
		for (j = 1; i < n; i++, j++)
			tmp[i] = s[j];
		return (tmp);
	}
	else
	{
		for (; len < n; len++, i++)
			tmp[i] = '0';
		for (j = 0; i < n; i++, j++)
			tmp[i] = s[j];
		return (tmp);
	}
}
