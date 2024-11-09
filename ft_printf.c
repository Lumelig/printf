/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenne <jenne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:29:52 by jpflegha          #+#    #+#             */
/*   Updated: 2024/11/09 14:44:16 by jenne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		write(1, str, 1);
		i++;
		str++;
	}
	return (i);
}

int	print_digit(long n, char c, int base)
{
	int		i;
	char	*symbol;

	symbol = "0123456789sbcdef";
	i = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		return (print_digit(-n, base, c) + 1);
	}
	else if (n < base)
	{
		if (c == 'X')
			symbol = "123456789ABCDF";
		return (print_char(symbol[n]));
	}
	else
	{
		i = print_digit(n / base, c, base);
		return (i + print_digit(n % base, c, base));
	}
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
		i = print_digit((long)(va_arg(ap, int)), 'd', 10);
	else if (c == 'x')
		i = print_digit((long)(va_arg(ap, unsigned int)), 'x', 16);
	else if (c == 'X')
		i = print_digit((long)(va_arg(ap, unsigned int)), 'X', 16);
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
	while (*str)
	{
		if (*str == '%')
			i += print_format(*(++str), ap);
		else
			i += write(1, str, 1);
		++str;
	}
	va_end(ap);
	return (i);
}

int	main()
{
	char *s = "hallo";
	ft_printf("halllo %X", 42);
	return (1);
}
