/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevyesil <sevyesil@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 02:35:51 by sevyesil          #+#    #+#             */
/*   Updated: 2026/03/07 19:52:12 by sevyesil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_print_unsigned(unsigned int n)
{
	char			transform;
	unsigned int	i;
	int				temp;

	temp = 0;
	i = 0;
	if (n > 9)
	{
		temp = ft_print_unsigned(n / 10);
		if (temp == -1)
			return (-1);
		i = i + temp;
	}
	transform = n % 10 + '0';
	if (write(1, &transform, 1) == -1)
		return (-1);
	i++;
	return (i);
}
