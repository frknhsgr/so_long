/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ut.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhosgor <fhosgor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:18:36 by fhosgor           #+#    #+#             */
/*   Updated: 2023/10/28 15:42:48 by fhosgor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
		i += ft_putchar(str[i]);
	return (i);
}

int	ft_putnbr(int n, int i)
{
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		i += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		i = ft_putnbr(n / 10, i);
		i += ft_putchar(n % 10 + '0');
	}
	else
		i += ft_putchar(n + '0');
	return (i);
}

int	ft_putuns(unsigned int n, int i)
{
	if (n >= 10)
	{
		i = ft_putuns(n / 10, i);
		i += ft_putchar(n % 10 + '0');
	}
	else
		i += ft_putchar(n + '0');
	return (i);
}

int	ft_printhex(unsigned int n, char format)
{
	int	i;

	i = 0;
	if (n >= 16)
		i += ft_printhex(n / 16, format);
	if (format == 'x')
		i += ft_putchar("0123456789abcdef"[n % 16]);
	else if (format == 'X')
		i += ft_putchar("0123456789ABCDEF"[n % 16]);
	return (i);
}

int	ft_printp(unsigned long n, int c)
{
	int	i;

	i = 0;
	if (c == 1)
	{
		i += ft_putchar('0');
		i += ft_putchar('x');
	}
	if (n >= 16)
		i += ft_printp(n / 16, 0);
	i += ft_putchar("0123456789abcdef"[n % 16]);
	return (i);
}
