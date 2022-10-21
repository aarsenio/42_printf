/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarsenio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:54:27 by aarsenio          #+#    #+#             */
/*   Updated: 2022/03/21 18:35:28 by aarsenio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef unsigned long long	t_llu;

int	ft_printf(const char *s, ...);
int	ft_putchar(int s);
int	ft_putstr(char *s);
int	ft_putnbr(int n, int i);
int	ft_putpointer(t_llu ptr);
int	ft_write_number(t_llu n, t_llu base, int x, char s);

#endif