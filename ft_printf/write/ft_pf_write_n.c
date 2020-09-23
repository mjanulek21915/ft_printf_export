#include "ft_printf.h"
int					ft_pf_write_n(char *str, int n)
{
fprintf(stderr, "ft_pf_write_n\n");

	int rst;

	rst = 0;
	if (!str)
		return (-1);
	if (n == -1)
		while (*str)
			rst += write(1, str++, 1);
	else
		rst = write(1, str, n);
	return (rst);
}