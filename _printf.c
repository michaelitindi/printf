#include <stdarg.h> 
#include <unistd.h>
#include <stdio.h>
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
count = 0;
va_start(args, format);
while (*format)
{
if (*format == '%')
{
format++;
if (*format == 'c')
count += write(1, &va_arg(args, int), 1);
else if (*format == 's')
count += write(1, va_arg(args, char *), 1);
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
va_end(args);
return (count);
}
