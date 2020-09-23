#include "ft_printf.h"

static int			ft_pf_write_int_hdl_hdl(t_type *type)
{
	int rst;

	rst = 0;
	if (type->is_space && !type->is_signed)
	{
		rst += write(1, " ", 1);
		type->pad_len--;
	}
	return (rst);
}

static int			ft_pf_write_ptr_hdl(t_type *type)
{
	int rst;

	rst = 0;
	if (type->is_left)
	{
		rst += ft_pf_write_int_hdl_hdl(type);
		if (type->sign)
			rst += write(1, &(type->sign), 1);
		rst += write(1, "0x", 2);
		rst += ft_pf_write_put_base(type->temp, BASE_16);
		rst += ft_pf_write_padding(type->pad_len, type->padding);
	}
	else
	{
		rst += ft_pf_write_padding(type->pad_len, type->padding);
		rst += ft_pf_write_int_hdl_hdl(type);
		if (type->sign)
			rst += write(1, &(type->sign), 1);
		rst += write(1, "0x", 2);
		rst += ft_pf_write_put_base(type->temp, BASE_16);
	}
	return (rst);
}
int					ft_pf_write_ptr(va_list vl, t_type *type)
{
fprintf(stderr, "ft_pf_write_ptr\n");

	if (type->is_left)
		type->padding = ' ';
	if (type->type == 'p')
	{
		type->temp = (unsigned long)va_arg(vl, long int);
		type->len = ft_pf_write_nlen(type->temp, 16);
		type->prec_len = type->precision - type->len;
		type->len += ft_pf_write_get_sign(&(type->temp), type);
		type->pad_len = type->width - type->len - 2;
		return (ft_pf_write_ptr_hdl(type));
	}
	return (0);
}