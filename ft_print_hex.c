/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevyesil <sevyesil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 20:57:13 by sevyesil          #+#    #+#             */
/*   Updated: 2026/02/28 01:07:51 by sevyesil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_print_hex(unsigned int n, char type)
{
	char	*base_upper;
	char	*base_lower;
	int		i;
	char	c;

	i = 0;
	base_upper = "0123456789ABCDEF";
	base_lower = "0123456789abcdef";
	if (n >= 16)
	{
		i += ft_print_hex(n / 16, type);
	}
	if (type == 'x')
	{
		c = base_lower[n % 16];
	}
	else if (type == 'X')
	{
		c = base_upper[n % 16];
	}
	write(1, &c, 1);
	i++;
	return (i);
}
