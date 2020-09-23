#include "ft_printf.h"

int					ft_pf_write_char(va_list vl, t_type *type)
{
	char temp;
	int p_len;
	int rst;
fprintf(stderr, "ft_pf_write_char\n");

	rst = 0;
	p_len = type->width - 1;
	if (type->type == 'c')
	{
		temp = (char) va_arg(vl, int);
		if (type->is_left)
		{
			rst += write(1, &temp, 1);
			rst += ft_pf_write_padding(p_len, ' ');
		}
		else
		{
			rst += ft_pf_write_padding(p_len, ' ');
			rst += write(1, &temp, 1);
		}
	}
	printf("ft_pf_write_char : %d\n", rst);
	return (rst);
}