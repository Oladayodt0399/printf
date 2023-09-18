#include "main.h"
/**
 * _printf - formatted text printf function
 * @format: format string
 * @...: Variable arguments to format and print
 * Return: Number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	const char *str;

	va_start(args, format);
	while (format && *format)
	{
	if (*format != '%')
	{
		if (is_putchar(*format) == -1)
		{
			va_end(args);
			return -1;
		}
		count++;
	} else
	{
		format++;
		switch (*format)
		{
			case 'c':
				if (*format == 'c')
				{	
					is_putchar(va_arg(args, int));
				}
				count++;
				break;
			case 's':
				str = va_arg(args, const char *);
				if (str == NULL)
					str = "(null)";
				while (*str)
				{
					is_putchar(*str);
					str++;
					count++;
				} break;
			case '%':
				is_putchar('%');
				count++;
				break;
			default:
				is_putchar('%');
				is_putchar(*format);
				count += 2;
				break;
		}
	} format++;
	}
	va_end(args);
	return count;
}
