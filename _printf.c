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
else if (*format == '%')
count += write(1, "%", 1);
else
return (-1);
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
