#include "ft_printf.h"

int					ft_pf_write_str(va_list vl, t_type *type)
{
fprintf(stderr, "ft_pf_write_str\n");

	char *temp;
	int len;
	int p_len;
	int rst;

	if (type->type == 's')
	{
		temp = va_arg(vl, char *);
		len = ft_pf_strlen(temp);
		p_len = type->width - len;
		rst = len + p_len;
		if (type->is_left)
		{
			ft_pf_write_n(temp, len);
			ft_pf_write_padding(p_len, ' ');
		}
		else
		{
			ft_pf_write_padding(p_len, ' ');
			ft_pf_write_n(temp, len);
		}
		return (rst);
	}
	return (0);
}