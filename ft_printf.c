/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpflegha <jpflegha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:29:52 by jpflegha          #+#    #+#             */
/*   Updated: 2024/11/09 18:23:30 by jpflegha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

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

	symbol = "0123456789abcdef";
	i = 0;
	if (n < 0 && c != 'u')
	{
		i += write(1, "-", 1);
		i += print_digit(-n, base, c);
	}
	else if (n < base)
	{
		if (c == 'X')
			symbol = "0123456789ABCDF";
		return (print_char(symbol[n]));
	}
	else
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
	else if (c == 'd' || c == 'u')
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
    int i = 0;
	char *s = "hallo";
	i = ft_printf("halllo %% %d %u %d \n", -42, -42, i);
    ft_printf("%d \n", i);
    i = printf("halllo %% %X %u %p\n", -42, -42, i);
	return (1);
}
