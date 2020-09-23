#include "ft_printf.h"

static int			ft_pf_write_uint_hdl(t_type *type)
{
fprintf(stderr, "ft_pf_write_uint_hdl\n");

	int rst;

	rst = 0;
	if (type->is_left)
	{
		rst += ft_pf_write_padding(type->prec_len, '0');
		rst += ft_pf_write_put_base(type->temp, BASE_10);
		rst += ft_pf_write_padding(type->pad_len, type->padding);
	}
	else
	{
		rst += ft_pf_write_padding(type->pad_len, type->padding);
		rst += ft_pf_write_padding(type->prec_len, '0');
		rst += ft_pf_write_put_base(type->temp, BASE_10);
	}
	return rst;
}


int					ft_pf_write_uint(va_list vl, t_type *type)
{
	if (type->is_left)
		type->padding = ' ';
	if (type->type == 'u')
	{
		type->temp = (unsigned int)va_arg(vl, int);
		type->len = ft_pf_write_nlen(type->temp, 10);
		type->prec_len = type->precision - type->len;
		type->prec_len = (type->prec_len > 0) ? type->prec_len : 0;
		type->pad_len = type->width - type->len - type->prec_len;

		return (ft_pf_write_uint_hdl(type));
	}
	return (0);
}