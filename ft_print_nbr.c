/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevyesil <sevyesil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 17:39:46 by sevyesil          #+#    #+#             */
/*   Updated: 2026/03/03 21:26:55 by sevyesil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_print_nbr(int n)
{
	long	num;
	char	trans;
	int		count;

	count = 0;
	num = (long)n;
	if (num < 0)
	{
		if (write(1, '-', 1) == -1)
			return (-1);
		write(1, "-", 1);
		num = -num;
		count++;
	}
	if (num > 9)
	{
		count = ft_print_nbr(num / 10);
		if (count == -1)
			return (-1);
	}
	trans = (num % 10) + '0';
	if (write(1, &trans, 1) == -1)
		return (-1);
	write(1, &trans, 1);
	count++;
	return (count);
}
