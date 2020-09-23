#include "ft_printf.h"

static int					ft_read_iz_in(char c, char *str)
{
fprintf(stderr, "ft_read_iz_in\n");
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

int						ft_read_atoi(char **str)
{
fprintf(stderr, "ft_read_atoi\n");

	int rst;

	rst = 0;
	if (**str == '*')
	{
		(*str)++;
		return (-1);
	}
	while (**str >= '0' && **str <= '9')
	{
		rst = rst * 10;
		rst = rst + **str - '0';
		(*str)++;
		if (rst < 0)
			return (0);
	}
	return (rst);
}

static void				ft_read_get_numbers(t_type *type, char **str, va_list vl)
{
fprintf(stderr, "ft_read_get_numbers\n");

	int temp;

	temp = ft_read_atoi(str);
	if (temp == -1)
		type->width = va_arg(vl, int);
	else
		type->width = temp;
	if (**str == '.')
	{
		temp = ft_read_atoi(str);
		if (temp == -1)
			type->precision = va_arg(vl, int);
		else
			type->precision = temp;
	}
}

static void				ft_read_get_flags(t_type *type, char **str)
{
fprintf(stderr, "ft_read_get_flags\n");

	while (**str == '+' || **str == '-' || **str == '0' || **str == ' ')
	{
		if (**str == '+')
			type->is_signed = 1;
		if (**str == '-')
			type->is_left = 1;
		if (**str == '0')
			type->padding = '0';
		if (**str == ' ')
			type->is_space = 1;
		(*str)++;
	}

}

void					ft_read_init(t_type *type)
{
fprintf(stderr, "ft_read_init\n");

		type->is_signed = 0;
		type->is_left = 0;
		type->padding = 0;
		type->is_space = 0;
		type->width = 0;
		type->precision = 0;
}

int						ft_read(char **str, va_list vl)
{
fprintf(stderr, "ft_read\n");

	t_type type;

	ft_read_init(&type);
	ft_read_get_flags(&type, str);
	ft_read_get_numbers(&type, str, vl);
	if (!(ft_read_iz_in(**str, CONV)))
		return (0);
	type.type = **str;
	(*str)++;
	return (ft_write(&type, vl));
}
