#include <stdarg.h>
#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _putchar - print a charachter
 * @c: the character to be printed
 * Return: printed character
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * caseint - convert integer to string
 * @num: the integer to convert
 * @str: a buffer to store the resulting string
 * Return: the length of the resulting string
 */
int caseint(int num, char *str)
{
    int i = 0, sign = 0;
    int j = 0, len;
    if (num == 0)
    {
        str[i++] = '0';
    }
    else if (num < 0)
    {
        sign = 1;
        num = -num;
    }
    while (num != 0)
    {
        str[i++] = num % 10 + '0';
        num = num / 10;
    }
    if (sign)
    {
        str[i++] = '-';
    }
    str[i] = '\0';
    len = i;
    for (j = 0; j < len / 2; j++)
    {
        char tmp = str[j];
        str[j] = str[len - j - 1];
        str[len - j - 1] = tmp;
    }
    return len;
}
/**
 * _printf - function printf
 * @format: the format of arguments
 * Return: the numberof printed charachetrs
 */

int _printf(const char *format, ...)
{
	va_list args;
	int i, res = 0;
	char *str;

	va_start(args, format);

	if (format == NULL)
	{
		return (0);
	}
	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;

			if (format[i] == 'c')
			{
				_putchar(va_arg(args, int));
				res++;
			}
			else if (format[i] == 's')
			{
				str = va_arg(args, char *);
				if (str == NULL)
					str = "(null)";
				while (*str)
				{
					_putchar(*str);
					str++;
					res++;
				}
			}
			else if (format[i] == '%')
			{
				_putchar('%');
				res++;
			}
			else if (!format[i])
			{
				i--;
			}
			else if (format[i] == 'd' || format[i] == 'i')
			{
				int num = va_arg(args, int);
				char buffer[20];
				int j;
				int len = caseint(num, buffer);

				for (j = 0; j < len; j++)
				{
					_putchar(buffer[j]);
					res++;
				}
			}

		}

		else
		{
			_putchar(format[i]);
			res++;
		}
	}
	va_end(args);
	return (res);
}
