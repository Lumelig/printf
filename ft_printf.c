/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpflegha <jpflegha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:29:52 by jpflegha          #+#    #+#             */
/*   Updated: 2024/11/08 17:34:38 by jpflegha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

int	ft_printf(char *str, ...)
{
	va_list	ap;
	int i;

	i = 0;
	va_start(ap, str);
	while (str[i] != '/0')
	{
		if (str[i] == '%')
			if (str[++i] == '%')
				write(1, '%', 1);
			else if (str[++i] == 'c')
			else if (str[i++] == 's')
			else if (str[i++] == 'p')
			else if (str[i++] == 'd')
			else if (str[i++] == 'i')
			else if (str[i++] == 'x' || 'X')
		i++;
	}
}
