#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	sayi;

	sayi = -12345;
	printf("\n%d", ft_printf("%d", sayi));
	return (0);
}
