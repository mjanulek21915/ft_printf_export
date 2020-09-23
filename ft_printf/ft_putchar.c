#include "ft_printf.h"

int					ft_putchar(char *str)
{
	int i;
	i = write(1, str, 1);
	return (i);
}