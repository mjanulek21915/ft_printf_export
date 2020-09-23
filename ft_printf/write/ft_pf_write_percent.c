#include "ft_printf.h"

int					ft_pf_write_percent(t_type *type)
{
fprintf(stderr, "ft_pf_write_percent\n");

	if (type->type == '%')
	{
fprintf(stderr, "ft_pf_write_percent is type\n");
		write(1, "%", 1);
		return (1);
	}
	return (0);
}