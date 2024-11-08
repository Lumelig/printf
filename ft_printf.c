/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpflegha <jpflegha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:29:52 by jpflegha          #+#    #+#             */
/*   Updated: 2024/11/08 17:30:33 by jpflegha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

int	ft_printf(char *format, ...)
{
	va_list	ap;
	int i;

	i = 0;
	va_start(ap, format);
	while (format[i] != '/0')
	{
		if (format[i] == '%')
			if (format[++i] == '%')
				write(1, '%', 1);
			else if (format[++i] == 'c')
			else if (format[i++] == 's')
			else if (format[i++] == 'p')
			else if (format[i++] == 'd')
			else if (format[i++] == 'i')
			else if (format[i++] == 'x' || 'X')
		i++;
	}
}
