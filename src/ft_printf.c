/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 05:20:14 by asoria            #+#    #+#             */
/*   Updated: 2025/06/16 02:14:56 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
cspdiuxX%
 malloc, free, write, va_start, va_arg, va_copy, va_end.
*/

#include "ft_printf.h"

int	printf_write(char sel, va_list args)
{
	int	count;

	count = 0;
	if (sel == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (sel == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (sel == 'd' || sel == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (sel == 'p')
		count += print_addr(va_arg(args, void *));
	else if (sel == 'u')
		count += print_unsigned(va_arg(args, unsigned int));
	else if (sel == 'x')
		count += print_hex(va_arg(args, unsigned int),
				"0123456789abcdef");
	else if (sel == 'X')
		count += print_hex(va_arg(args, unsigned int),
				"0123456789ABCDEF");
	else if (sel == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *fmt, ...)
{
	int		i;
	int		count;
	va_list	args;

	va_start(args, fmt);
	i = 0;
	count = 0;
	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%')
		{
			i++;
			count += printf_write(fmt[i], args);
		}
		else
			count += ft_putchar(fmt[i]);
		i++;
	}
	va_end(args);
	return (count);
}
