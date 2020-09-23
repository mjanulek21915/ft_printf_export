#include "ft_printf.h"

int			ft_pf_write_get_sign(long long *temp, t_type *type)
{
fprintf(stderr, "ft_pf_write_get_sign\n");

	type->sign = 0;
	if (*temp < 0)
	{
		type->sign = '-';
		*temp = -*temp;
		return (1);
	}
	else if (type->is_signed)
	{
		type->sign = '+';
		return (1);
	}
	else if (type->is_space)
	{
		type->sign = 0;
		return (1);
	}
	type->sign = 0;
	return (0);
}