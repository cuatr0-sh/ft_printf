/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_print_addr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 09:32:42 by asoria            #+#    #+#             */
/*   Updated: 2025/06/22 20:41:15 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_addr(unsigned long addr, int *count)
{
	if (addr == 0)
	{
		count += ft_putchar('0');
		return (3);
	}
	else
		return (-1);
}

int	print_addr(void *ptr)
{
	unsigned long	addr;
	char			buffer[17];
	char			*digits;
	int				i;
	int				count;

	if (!ptr)
		return (ft_putstr("(nil)"));
	digits = "0123456789abcdef";
	count = 0;
	count += ft_putstr("0x");
	addr = (unsigned long)ptr;
	if (check_addr(addr, &count) == 3)
		return (3);
	i = 0;
	while (addr)
	{
		buffer[i++] = digits[addr & 0xF];
		addr >>= 4;
	}
	while (i--)
		count += ft_putchar(buffer[i]);
	return (count);
}
