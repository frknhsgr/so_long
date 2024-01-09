/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhosgor <fhosgor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:04:41 by fhosgor           #+#    #+#             */
/*   Updated: 2023/10/21 18:04:42 by fhosgor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_printhex(unsigned int n, char format);
int	ft_putuns(unsigned int n, int i);
int	ft_putnbr(int n, int i);
int	ft_printp(unsigned long n, int c);
int	ft_printf(const char *str, ...);

#endif