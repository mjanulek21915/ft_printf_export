#include "ft_printf.h"

int					main()
{
	char c = 'a';
	int rst = ft_printf("test int = %c\n", c);
	printf("rst = %d\n", rst);
}