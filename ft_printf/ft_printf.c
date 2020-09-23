#include "ft_printf.h"

int					ft_printf(const char *str, ...)
{
	va_list va;

	char *temp;
	int rst;
	temp = (char *)str;
	va_start(va, str);
	while (*temp)
	{

		if (*temp == '%')
		{
			temp++;
			rst = ft_read(&temp, va);
		}
		rst += ft_putchar(temp);
		temp++;
	}
	return (rst);
}