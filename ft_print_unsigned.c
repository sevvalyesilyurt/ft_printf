/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevyesil <sevyesil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 02:35:51 by sevyesil          #+#    #+#             */
/*   Updated: 2026/02/28 04:23:09 by sevyesil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_print_unsigned(unsigned int n)
{
	char			transform;
	unsigned int	i;

	i = 0;
	if (n > 9)
		i += ft_print_unsigned(n / 10);
	transform = n % 10 + '0';
	write(1, &transform, 1);
	i++;
	return (i);
}
