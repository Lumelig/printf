/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenne <jenne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:47:24 by jpflegha          #+#    #+#             */
/*   Updated: 2024/11/14 10:31:54 by jenne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);

int	print_format(char c, va_list ap);

int	print_digit(long n, char c, int base);

int	print_str(char *str);

int	print_char(char c);

int	print_pointer(unsigned long n, unsigned int base);

int	check_pointer(unsigned long n, unsigned int base);

#endif