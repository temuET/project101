#include "main.h"
/**
*_printf - used to print string farmating
*@format: format parameter
*
*Return: the number of charactors
*/

int _printf(const char *format, ...)

{

	int length, i = 0, neg = 0, count = 0, x, y, j, z, f;
	char *num;
	char *str, hashsp;
	va_list args;

	s spec[] = {


		{"s", f_s},

		{"c", f_c},

		{"r", f_r},

		{"i", f_id},

		{"d", f_id},

		{"b", f_b},

		{"o", f_o},

		{"u", f_u},

		{"x", f_x},

		{"X", f_X},

		{"R", f_R},

		{"S", f_S},

		{"", NULL}

	};

	struct f flag[] = {

		{"+", f_plus},

		{" ", f_space},

		{"", NULL}

	};

	str = malloc(sizeof(char) * 1024);

	if (!str)

		return (-1);

	for (j = 0; j < 1024; j++)

		str[j] = '\0';

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))

		return(-1);

	va_start(args, format);

	while (format[i] != '\0')

	{

		if (format[i] == '%' && format[i + 1] == '\0' && format[i - 1] != '%')

		{

			return (-1);

		}

		if (format[i] == '%' && format[i + 1] == '%')

		{

			_putchar('%');

			i = i + 2;

			count++;

		}

		else if (format[i] == '%')

		{

			length = counter(i, format, spec);

			if (length == -1)

			{

				_putchar(format[i]);

				i++;

				count++;

			}

			if (length >= 0)

			{

				for (x = 0; *spec[x].c != '\0'; x++)

				{



					if (format[i + (length + 1)] == *spec[x].c)

					{

						str = spec[x].sp(args, str);

						if (str == NULL)

							return (-1);

						hashsp = *spec[x].c;

					}

				}

				if (length >= 1)

				{

					for (j = i + 1; j <= i + length; j++)

					{



						for (x = 0; *flag[x].c != '\0'; x++)

						{

							if (format[j] == *flag[x].c)

							{

								str = flag[x].fl(str);

								if (str == NULL)

									return (-1);

							}

						}

						if (format[j] == '#')

						{

							str = hashparser(str, hashsp);

							if (str == NULL)

								return (-1);

						}

						if ((format[j] == '.') || (format[j] == '0'))

						{

							num = malloc(sizeof(char) * ((i + length + 1) - j));

							if(!num)

								return(-1);

							for (z = j + 1, f = 0; z <= i + length; z++, f++)

							{

								num[f] = format[z];

							}

							num[f] = '\0';


							if (format[j] == '.')

								str = f_pres(str, num, hashsp);

							else if (format[j] == '0')

								str = f_zero(str, num);

							if (str == NULL)

									return (-1);

							free(num);

						}

						else if ((format[j] > '0' && format[j] < '9') || (format[j] == '-'))

						{

							if (format[j] == '-')

							{

								neg = 1;

								j++;

							}

							num = malloc(sizeof(char) * ((i + length + 2) - j));

							if (!num)

								return (-1);

							for (z = j, f = 0; z <= i + length; z++, f++)

							{

								num[f] = format[z];

							}

							num[f] = '\0';

							str = f_width(str, num, neg);

							if (str == NULL)

								return (-1);

							free(num);

						}

					}

				}



				for (y = 0; str[y] != '\0'; y++, count++)

				{

					_putchar(str[y]);

					str[y] = '\0';

				}

				i = i + (length + 2);

			}


		}

		else

		{

			_putchar(format[i]);

			i++;

			count++;

		}

	}



	free(str);

	return (count);

}
