#include "ft_printf.h"

int					ft_write(t_type *type, va_list vl)
{
	int rst;

	rst = 0;
	rst += ft_pf_write_str(vl, type);
	rst += ft_pf_write_hex(vl, type);
	rst += ft_pf_write_ptr(vl, type);
	rst += ft_pf_write_hex_a(vl, type);
	rst += ft_pf_write_int(vl, type);
	rst += ft_pf_write_uint(vl, type);
	rst += ft_pf_write_percent(type);
	rst += ft_pf_write_char(vl, type);
	return(rst);
}