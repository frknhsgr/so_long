/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhosgor <fhosgor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:00:16 by fhosgor           #+#    #+#             */
/*   Updated: 2023/10/28 15:42:36 by fhosgor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checkop(char c)
{
	if (c == 'c' || c == 's' || c == 'd' || c == 'i' || c == 'u' || c == 'x'
		|| c == 'X' || c == 'p' || c == '%')
		return (1);
	else
		return (0);
}

int	ft_check(char c, va_list ap)
{
	if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(ap, int), 0));
	else if (c == 'u')
		return (ft_putuns(va_arg(ap, unsigned int), 0));
	else if (c == 'x' || c == 'X')
		return (ft_printhex(va_arg(ap, unsigned int), c));
	else if (c == 'p')
		return (ft_printp(va_arg(ap, unsigned long), 1));
	else
		return (0);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (ft_checkop(str[i + 1]))
				len += ft_check(str[i++ + 1], ap);
			i++;
		}
		else
		{
			len += ft_putchar(str[i]);
			i++;
		}
	}
	va_end(ap);
	return (len);
}
