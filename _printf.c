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
    
