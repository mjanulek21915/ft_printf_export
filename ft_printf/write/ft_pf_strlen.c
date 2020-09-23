#include "ft_printf.h"

int					ft_pf_strlen(char *str)
{
fprintf(stderr, "ft_pf_strlen\n");

	int i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}