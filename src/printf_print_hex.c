/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_print_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42imadrid.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 22:39:07 by asoria            #+#    #+#             */
/*   Updated: 2025/06/18 07:48:45 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(unsigned int nr, char *base)
{
	int		nr_base[16];
	int		i;
	int		result;

	i = 0;
	result = 0;
	if (nr == 0)
		result += ft_putchar('0');
	while (nr)
	{
		nr_base[i] = nr % 16;
		nr = nr / 16;
		i++;
	}
	while (--i >= 0)
		result += ft_putchar(base[nr_base[i]]);
	return (result);
}
