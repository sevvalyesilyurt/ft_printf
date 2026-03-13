/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevyesil <sevyesil@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 18:17:22 by sevyesil          #+#    #+#             */
/*   Updated: 2026/03/07 19:52:51 by sevyesil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_print_nbr(int n)
{
	long	num;
	int		temp;
	int		count;

	temp = 0;
	count = 0;
	num = (long)n;
	if (num < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		num = -num;
		count++;
	}
	if (num > 9)
	{
		temp = ft_print_nbr(num / 10);
		if (count == -1)
			return (-1);
		count = count + temp;
	}
	if (ft_print_char((num % 10) + '0') == -1)
		return (-1);
	count++;
	return (count);
}
