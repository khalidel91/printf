#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

/**
 * _putchar - print a character
 * @c: the character to be printed
 * Return: 1 on success, -1 on failure
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _printf - custom printf function
 * @format: a string containing zero or more directives to print
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	char buffer[BUFFER_SIZE];
	char *ptr = buffer;
	const char *s;
	int c, n = 0;

	va_start(args, format);

	for (s = format; *s; ++s)
	{
		if (*s != '%')
		{
			*ptr++ = *s;
			if (ptr == buffer + BUFFER_SIZE)
			{
				n += write(1, buffer, BUFFER_SIZE);
				ptr = buffer;
			}
		}
		else
		{
			switch (*++s)
			{
				case 'c':
					c = va_arg(args, int);
					*ptr++ = c;
					if (ptr == buffer + BUFFER_SIZE)
					{
						n += write(1, buffer, BUFFER_SIZE);
						ptr = buffer;
					}
					break;
				case 's':
					for (char *str = va_arg(args, char *); *str; ++str)
					{
						*ptr++ = *str;
						if (ptr == buffer + BUFFER_SIZE)
						{
							n += write(1, buffer, BUFFER_SIZE);
							ptr = buffer;
						}
					}
					break;
				default:
					break;
			}
		}
	}
	va_end(args);

	if (ptr > buffer)
		n += write(1, buffer, ptr - buffer);

	return (n);
}
