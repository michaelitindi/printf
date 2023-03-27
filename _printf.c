#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
int count, i, num;
char *s;
char c;
va_list arg_list;
i = 0;
count = 0;
va_start(arg_list, format);
while (*format != '\0')
{
if (*format == '%')
{
format++;
if (*format == '%')
{
putchar('%');
count++;
}
else if (*format == 'c')
{
c = (char) va_arg(arg_list, int);
putchar(c);
count++;
}
else if (*format == 's')
{
s = va_arg(arg_list, char *);
while (s[i] != '\0')
{
putchar(s[i]);
count++;
i++;
}
}
else
{
putchar(*format);
count++;
}
format++;
}
va_end(arg_list);
return (count);
}
