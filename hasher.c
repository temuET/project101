#include "main.h"

/**
* hashparser - matches hash to hexidecimal upper, hexidecimal lower, or octal.
* @s: string to be matched.
* @spec: specifier that flag acts on.
* Return: pointer to string after its goes to its corresponding function.
*/

char *hashparser(char *s, char spec)

{

	if (spec == 'x')

		return (hasher_x(s));

	else if (spec == 'X')

		return (hasher_X(s));

	else if (spec == 'o')

		return (hasher_o(s));

	return (s);

}

/**
* hasher_X - Adds 0x to hexidecimal uppercase.
* @s: string to be ammended.
* Return: pointer to string.
*/

char *hasher_X(char *s)

{

	char *tmp, *tmp2;

	int i, j = 0;

	tmp = s;

	if (!tmp)

		return ("(null)");

	for (i = 0; tmp[i] != '\0'; ++i)

		;

	tmp2 = malloc(sizeof(char) * (i + 3));

	if (!tmp2)

		return (NULL);

	tmp2[0] = '0';

	tmp2[1] = 'X';

	for (j = 2, i = 0; tmp[i] != '\0'; j++, i++)

		tmp2[j] = tmp[i];

	tmp2[j] = '\0';

	free(s);

	return (tmp2);

	free(tmp2);

}


/**
* hasher_o - adds 0 to octal string.
* @s: string to be ammended.
* Return: pointer to string.
*/

char *hasher_o(char *s)

{

	char *tmp, *tmp2;

	int i, j = 0;

	tmp = s;

	if (!tmp)

		return ("(null)");

	for (i = 0; tmp[i] != '\0'; ++i)

		;

	tmp2 = malloc(sizeof(char) * (i + 2));

	if (!tmp2)

		return (NULL);

	tmp2[0] = '0';

	for (j = 1, i = 0; tmp[i] != '\0'; j++, i++)

		tmp2[j] = tmp[i];

	tmp2[j] = '\0';

	free(s);

	return (tmp2);

	free(tmp2);

}


/**
* hasher_x - adds 0x to hexidecimal lowercase string/
* @s: string to be evaluated.
* Return: pointer to string.
*/

char *hasher_x(char *s)

{

	char *tmp, *tmp2;

	int i, j;

	tmp = s;

	if (!tmp)

		return ("(null)");

	for (i = 0; tmp[i] != '\0'; ++i)

		;

	tmp2 = malloc(sizeof(char) * (i + 3));

	if (!tmp2)

		return (NULL);

	tmp2[0] = '0';

	tmp2[1] = 'x';

	for (j = 2, i = 0; tmp[i] != '\0'; j++, i++)

	{

		tmp2[j] = tmp[i];

	}

	tmp2[j] = '\0';

	free(s);

	return (tmp2);
	free(tmp2);

}
