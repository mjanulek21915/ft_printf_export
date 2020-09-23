#include "ft_printf.h"

int				ft_pf_write_padding(int n, char c)
{
fprintf(stderr, "ft_pf_write_padding\n");

	int i;

	i = 0;
	while (i++ < n)
		write(1, &c, 1);
	return (n);
}