/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevyesil <sevyesil@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 00:59:07 by sevyesil          #+#    #+#             */
/*   Updated: 2026/03/09 17:15:44 by sevyesil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_ptr_to_hex(unsigned long n)
{
	int		count;
	int		temp;
	char	*base;
	char	c;

	base = "0123456789abcdef";
	temp = 0;
	count = 0;
	if (n >= 16)
	{
		temp = ft_ptr_to_hex(n / 16);
		if (temp == -1)
			return (-1);
		count = count + temp;
	}
	c = base[n % 16];
	if (write(1, &c, 1) == -1)
		return (-1);
	count++;
	return (count);
}

int	ft_print_ptr(void *ptr)
{
	unsigned long	address;
	int				i;
	int				temp;

	temp = 0;
	address = (unsigned long)ptr;
	if (ptr == NULL)
	{
		if (write(1, "(nil)", 5) == -1)
			return (-1);
		return (5);
	}
	if (write(1, "0x", 2) == -1)
		return (-1);
	i = 2;
	temp = ft_ptr_to_hex(address);
	if (temp == -1)
		return (-1);
	i = temp + i;
	return (i);
}
