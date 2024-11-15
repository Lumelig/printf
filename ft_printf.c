/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpflegha <jpflegha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:29:52 by jpflegha          #+#    #+#             */
/*   Updated: 2024/11/15 13:07:14 by jpflegha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"

int	print_char(char c)
{
	int	i;

	i = 0;
	i += write(1, &c, 1);
	if (i == -1)
		return (-1);
	return (i);
}

int	print_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		i = write(1, "(null)", 6);
		return (i);
	}
	while (*str)
	{
		i += print_char(*str);
		str++;
	}
	return (i);
}

int	print_digit(long n, char c, int base)
{
	int		i;
	char	*symbol;

	symbol = "0123456789abcdef";
	i = 0;
	if (n < 0 && c != 'u' && c != 'x' && c != 'X')
	{
		i += write(1, "-", 1);
		n *= -1;
	}
	if (n < base)
	{
		if (c == 'X')
			symbol = "0123456789ABCDEF";
		i += print_char(symbol[n]);
		return (i);
	}
	if (n >= base)
		i += print_digit(n / base, c, base);
	i += print_digit(n % base, c, base);
	return (i);
}

int	print_format(char c, va_list ap)
{
	int	i;

	i = 0;
	if (c == 'c')
		i = print_char(va_arg(ap, int));
	else if (c == 's')
		i = print_str(va_arg(ap, char *));
	else if (c == 'd' || c == 'i')
		i = print_digit((long)(va_arg(ap, int)), 'd', 10);
	else if (c == 'u')
		i = print_digit(va_arg(ap, unsigned int), 'u', 10);
	else if (c == 'p')
	{
		i += write(1, "0x", 2);
		i += print_pointer((unsigned long long)va_arg(ap, void *), 16);
	}
	else if (c == 'x')
		i += print_digit((long)(va_arg(ap, unsigned int)), 'x', 16);
	else if (c == 'X')
		i += print_digit((long)(va_arg(ap, unsigned int)), 'X', 16);
	else
		i += print_char(c);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;

	i = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str)
				i += print_format(*str, ap);
		}
		else
			i += write(1, str, 1);
		++str;
	}
	va_end(ap);
	return (i);
}

// int	main()
// {
// 	int j = -15; 
//     unsigned int i = 42;
// 	char *s = "hallo";
//     i = ft_printf("%p %p\n", 12, 15);
// 	printf("%i \n", i);
//     i = printf("%p %p\n", 12, 15);
// 	printf("%i \n", i);
// 	return (1);
// }
