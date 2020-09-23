#include "ft_printf.h"

static int			ft_pf_write_int_hdl(t_type *type)
{

	int rst;

	rst = 0;
	if (type->is_left)
	{
		if (type->is_space && !type->is_signed)
			rst += write(1, " ", 1);
		if (type->sign)
			rst += write(1, &(type->sign), 1);
		rst += ft_pf_write_padding(type->prec_len, '0');
		rst += ft_pf_write_put_base(type->temp, BASE_10);
		rst += ft_pf_write_padding(type->pad_len, type->padding);
	}
	else
	{
		if (type->is_space && !type->is_signed)
		{
printf("if (type->is_space && !type->is_signed)\n");
printf("is_space = %d, is_signed = %d\n", type->is_space, type->is_signed);
			rst += write(1, " ", 1);

		}
		rst += ft_pf_write_padding(type->pad_len, type->padding);
		if (type->sign)
			rst += write(1, &(type->sign), 1);
		rst += ft_pf_write_padding(type->prec_len, '0');
		rst += ft_pf_write_put_base(type->temp, BASE_10);
	}
	return (rst);
}


int					ft_pf_write_int(va_list vl, t_type *type)
{
fprintf(stderr, "ft_pf_write_int\n");
	if (type->is_left)
		type->padding = ' ';
	if (type->type == 'd' || type->type == 'i')
	{
		type->temp = (int)va_arg(vl, int);
		type->len = ft_pf_write_nlen(type->temp, 10);
		type->prec_len = type->precision - type->len;
		type->prec_len = (type->prec_len > 0) ? type->prec_len : 0;
		type->len = type->len + ft_pf_write_get_sign(&(type->temp), type);
		type->pad_len = type->width - type->len - type->prec_len;
		return (ft_pf_write_int_hdl(type));
	}
	return (0);
}