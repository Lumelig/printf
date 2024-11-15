/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpflegha <jpflegha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:27:59 by jenne             #+#    #+#             */
/*   Updated: 2024/11/15 13:06:21 by jpflegha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"

int	print_pointer(unsigned long n, unsigned int base)
{
	int				i;
	char			*symbol;

	symbol = "0123456789abcdef";
	i = 0;
	if (n < base)
	{
		return (print_char(symbol[n]));
	}
	if (n >= base)
		i += print_pointer(n / base, base);
	i += print_pointer(n % base, base);
	return (i);
}

// int	check_pointer(unsigned long long n, unsigned int base)
// {
// 	int	i;

// 	i = 0;
// 	if (n == 0)
// 	{
// 		return (write(1, "(nil)", 5));
// 	}
// 	else
// 	{
// 		i += write(1, "0x", 2);
// 		i += print_pointer(n, base);
// 	}
// 	return (i);
// }
