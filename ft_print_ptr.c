/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevyesil <sevyesil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 00:59:07 by sevyesil          #+#    #+#             */
/*   Updated: 2026/02/28 02:31:40 by sevyesil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_ptr_to_hex(unsigned long n)
{
	int		i;
	char	*base;
	char	c;

	base = "0123456789abcdef";
	i = 0;
	if (n >= 16)
	{
		i += ft_ptr_to_hex(n / 16);
	}
	c = base[n % 16];
	write(1, &c, 1);
	i++;
	return (i);
}

int	ft_print_ptr(void *ptr)
{
	unsigned long	address;
	int				i;

	address = (unsigned long)ptr;
	if (ptr == NULL)
	{
		write(1, "0x0", 3);
		return (3);
	}
	i = 2;
	write(1, "0x", 2);
	i += ft_ptr_to_hex(address);
	return (i);
}
