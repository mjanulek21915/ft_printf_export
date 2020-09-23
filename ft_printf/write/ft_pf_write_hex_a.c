#include "ft_printf.h"

int					ft_pf_write_hex_a(va_list vl, t_type *type)
{
fprintf(stderr, "ft_pf_write_hex_a\n");

	long long temp;
	int len;
	int p_len;
	int rst;

	rst = 0;
	if (type->is_left)
		type->padding = ' ';
	if (type->type == 'X')
	{
		temp = (unsigned int)va_arg(vl, int);
		len = ft_pf_write_nlen(temp, 16);
		p_len = type->width - len;
		if (type->is_left)
		{
			rst += ft_pf_write_put_base(temp, BASE_16A);
			rst += ft_pf_write_padding(p_len, type->padding);
		}
		else
		{
			rst += ft_pf_write_padding(p_len, type->padding);
			rst += ft_pf_write_put_base(temp, BASE_16A);
		}
	}
	return (rst);
}