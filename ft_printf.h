/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevyesil <sevyesil@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 06:04:25 by sevyesil          #+#    #+#             */
/*   Updated: 2026/03/07 19:52:18 by sevyesil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_print_hex(unsigned int n, char type);
int	ft_print_char(int c);
int	ft_print_nbr(int n);
int	ft_print_unsigned(unsigned int n);
int	ft_print_str(char *str);
int	ft_print_hex(unsigned int n, char type);
int	ft_print_ptr(void *ptr);
int	ft_printf(const char *format, ...);

#endif