/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevyesil <sevyesil@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 16:24:22 by sevyesil          #+#    #+#             */
/*   Updated: 2026/03/13 18:52:27 by sevyesil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

static int	ft_which_character(char c, va_list args)
{
	int	i;

	i = 0;
	if (c == 'c')
		return (ft_print_char(va_arg(args, int)));
	else if (c == 'd' || c == 'i')
		return (ft_print_nbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	else if (c == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (c == 'x' || c == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), c));
	else if (c == 'p')
		return (ft_print_ptr(va_arg(args, void *)));
	else if (c == '%')
		return (ft_print_char('%'));
	else
	{
		i += ft_print_char('%');
		i += ft_print_char(c);
	}
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1) != 0)
		{
			format++;
			count += ft_which_character(*format, args);
		}
		else if (*format == '%' && *(format + 1) == 0)
			return (-1);
		else if (write(1, format, 1) == -1)
			return (-1);
		else
			count++;
		format++;
	}
	va_end(args);
	return (count);
}
