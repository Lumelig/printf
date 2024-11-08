/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenne <jenne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:29:52 by jpflegha          #+#    #+#             */
/*   Updated: 2024/11/08 22:15:34 by jenne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <unistd.h>

int	print_char(int c)
{
	return (write(1, &c, 1));
}

int	print_str(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i += write(1, &str, 1);
		str++;
	}
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
	else if (c == 'd')
		i = print_digit(va_arg(ap, int), 10);
	else if (c == 'x' || 'X')
		i = print_digit(va_arg(ap, int), 16);
	else
		i += write(1, &c, 1);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;

	i = 0;
	va_start(ap, str);
	while (str[i] != '/0')
	{
		if (*str == '%')
			i += print_format(*(++str) ap);
		else
			i += write(1, str, 1);
		++str;
	}
	va_end(ap);
	return (i);
}

int	main()
{
	ft_printf("halllo");
	return;
}
