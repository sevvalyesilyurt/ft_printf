/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevyesil <sevyesil@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 20:57:13 by sevyesil          #+#    #+#             */
/*   Updated: 2026/03/09 17:20:07 by sevyesil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_print_hex(unsigned int n, char type)
{
	char	*base_upper;
	char	*base_lower;
	int		i;
	char	c;
	int		temp;

	temp = 0;
	i = 0;
	base_upper = "0123456789ABCDEF";
	base_lower = "0123456789abcdef";
	if (n >= 16)
	{
		temp = ft_print_hex(n / 16, type);
		if (temp == -1)
			return (-1);
		i = temp + i;
	}
	if (type == 'x')
		c = base_lower[n % 16];
	else if (type == 'X')
		c = base_upper[n % 16];
	if (write(1, &c, 1) == -1)
		return (-1);
	i++;
	return (i);
}
