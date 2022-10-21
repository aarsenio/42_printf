/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarsenio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:54:31 by aarsenio          #+#    #+#             */
/*   Updated: 2022/03/22 11:43:13 by aarsenio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_type_arg(va_list args, const char *s, int i)
{
	if (s[i + 1] == 'c')
		return (ft_putchar((char)va_arg(args, int)));
	else if (s[i + 1] == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (s[i + 1] == 'p')
		return (ft_putpointer(va_arg(args, t_llu)));
	else if (s[i + 1] == 'd' || s[i + 1] == 'i')
		return (ft_putnbr(va_arg(args, int), 0));
	else if (s[i + 1] == 'u')
		return (ft_write_number((t_llu)va_arg(args, unsigned int), 10, 0, 'x'));
	else if (s[i + 1] == 'x')
		return (ft_write_number((t_llu)va_arg(args, unsigned int), 16, 0, 'x'));
	else if (s[i + 1] == 'X')
		return (ft_write_number((t_llu)va_arg(args, unsigned int), 16, 0, 'X'));
	else if (s[i + 1] == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	size_t	i;
	int		sum;

	va_start(args, s);
	sum = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			sum += ft_type_arg(args, s, i);
			i++;
		}
		else
		{
			write(1, &s[i], 1);
			sum++;
		}
		i++;
	}
	va_end(args);
	return (sum);
}
