/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 05:23:44 by asoria            #+#    #+#             */
/*   Updated: 2025/06/18 10:15:42 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_printf(char const *fmt, ...);
int	ft_putchar(int n);
int	ft_putnbr(int n);
int	ft_putstr(char *str);
int	print_addr(void *ptr);
int	print_unsigned(unsigned int n);
int	print_hex(unsigned int addr, char *dictionary);
int	printf_write(char sel, va_list args);

#endif
