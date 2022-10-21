/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarsenio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:29:21 by aarsenio          #+#    #+#             */
/*   Updated: 2022/03/21 16:37:09 by aarsenio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int s)
{
	write(1, &s, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n, int i)
{
	if (n == -2147483648)
		i += ft_putstr("-2147483648");
	else if (n < 0)
	{
		ft_putchar('-');
		i += ft_putnbr(-n, i);
		i++;
	}
	else if (n > 9)
	{
		i += ft_putnbr(n / 10, i);
		i += ft_putchar(n % 10 + '0');
	}
	else
		i += ft_putchar(n + '0');
	return (i);
}

int	ft_write_number(t_llu n, t_llu base, int x, char s)
{
	if (s == 'x')
	{
		if (n > base - 1)
			x += ft_write_number(n / base, base, x, s);
		write(1, &"0123456789abcdef"[n % base], 1);
	}
	else if (s == 'X')
	{
		if (n > base - 1)
			x += ft_write_number(n / base, base, x, s);
		write(1, &"0123456789ABCDEF"[n % base], 1);
	}
	return (++x);
}

int	ft_putpointer(t_llu ptr)
{
	int		i;

	i = 0;
	i += ft_putstr("0x");
	i += ft_write_number(ptr, 16, 0, 'x');
	return (i);
}
