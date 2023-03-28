#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"
/**
 * _printf - Print formatted output to stdout
 * @format: Format string
 * Return: Number of characters printed
 */

int _printf(const char *format, ...)
{
va_list args;
int count;
char c;
char *s;
int i;
count = 0;

if (format == NULL)
	return (-1);
va_start(args, format);

while (*format)
{
if (*format == '%')
{
	format++;
	if (*format == '\0')
		return (-1);
	if (*format == 'c')
	{
		c = va_arg(args, int);
		count += write(1, &c, 1);
	}
	else if (*format == 's')
	{
		s = va_arg(args, char *);
		count += write(1, s, strlen(s));
	}
	 if (*format == 'i')
	{
		i = va_arg(args, int);
		printf("---TEST--");
		count += print_number(i);
	}
	else if (*format == 'd')
	{
		i = va_arg(args, int);
		count += print_number(i);	
	}
	else if (*format == '%')
                count += write(1, "%", 1);
	else
		count += write(1, "%", 1) + write(1, &*format, 1);
	}
else
{
	count += write(1, &*format, 1);
}
	format++;
}
write(1, '\0', 1);
va_end(args);
return (count);
}

/**
 * print_number - uses write() to print numbers
 * @n: number
 *
 * Return: number of chars printed
 */
int print_number(int n)
{
  int count = 0;
  char digit;

  if (n < 0)
  {
    count += write(1, "-", 1);
    n *= -1;
  }

  if (n / 10)
  {
    count += print_number(n / 10);
  }

  digit = (n % 10) + '0';
  count += write(1, &digit, 1);

  return count;
}

