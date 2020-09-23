#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdarg.h>

# define CONV "cspdiuxX%"
# define BASE_10 "0123456789"
# define BASE_16 "0123456789abcdef"
# define BASE_16A "0123456789ABCDEF"

# define TEST "cesi est un test"

typedef struct	s_type
{
	int is_percent;
	int	is_left;
	int is_signed;
	int is_space;
	char padding;
	int width;
	int precision;
	char type;
	char sign;
	int len;
	int prec_len;
	int pad_len;
	long long temp;
}               t_type;

int					ft_putchar(char *str);
int					ft_printf(const char *str, ...);
int					ft_read(char **str, va_list va);
int					ft_pf_strlen(char *str);
int					ft_write(t_type *type, va_list va);
int					ft_pf_write_uint(va_list vl, t_type *type);
int					ft_pf_write_str(va_list vl, t_type *type);
int					ft_pf_write_put_base(long long n, char *base);
int					ft_pf_write_ptr(va_list vl, t_type *type);
int					ft_pf_write_percent(t_type *type);
int					ft_pf_write_padding(int n, char c);
int					ft_pf_write_nlen(long long n, int base);
int					ft_pf_write_n(char *str, int n);
int					ft_pf_write_int(va_list vl, t_type *type);
int					ft_pf_write_hex(va_list vl, t_type *type);
int					ft_pf_write_hex_a(va_list vl, t_type *type);
int					ft_pf_write_get_sign(long long *temp, t_type *type);
int					ft_pf_write_char(va_list vl, t_type *type);


#endif