/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevyesil <sevyesil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 17:39:46 by sevyesil          #+#    #+#             */
/*   Updated: 2026/02/27 20:23:10 by sevyesil         ###   ########.fr       */
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
		write(1, "-", 1);
		num = -num;
		count++;
	}
	if (num > 9)
	{
		count += ft_print_nbr(num / 10);
	}
	trans = (num % 10) + '0';
	write(1, &trans, 1);
	count++;
	return (count);
}
