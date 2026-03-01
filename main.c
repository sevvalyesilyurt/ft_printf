#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int				intnum;
	char			c;
	char			*str;
	unsigned int	num2;
	int				xnum;
	int				Xnum;

	intnum = 123456;
	c = 'a';
	str = "sevval";
	num2 = 456784345;
	xnum = 255;
	Xnum = 255;
	printf(" %d \n", ft_printf("ft: %d", intnum));
	printf(" %d \n", ft_printf("ft: %c", c));
	printf(" %d \n", ft_printf("ft: %s", str));
	printf(" %d \n", ft_printf("ft: %u", num2));
	printf(" %d \n", ft_printf("ft: %x", xnum));
	printf(" %d \n", ft_printf("ft: %X", Xnum));
	printf(" %d \n", ft_printf("ft: %p", str));
	return (0);
}
