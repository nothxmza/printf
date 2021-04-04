/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <hterras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 23:07:29 by jbarette          #+#    #+#             */
/*   Updated: 2021/03/18 17:22:55 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int		ft_is_in_type_list(char type)
{
	return ((type == 'c') || (type == 's') || (type == 'd') || (type == 'i') ||
			(type == 'u') || (type == 'p') || (type == 'x') || (type == 'X'));
}

int		ft_is_in_flag_list(char flag)
{
	return ((flag == '-') || (flag == '0') || (flag == '.') ||
			(flag == '*') || (flag == '%'));
}

int		ft_add_space(int width)
{
	int		i;

	i = 0;
	while (width > 0)
	{
		ft_putchar_fd(' ', 1);
		i++;
		width--;
	}
	return (i);
}

int		ft_take_width(const char *str, int i)
{
	char	nbr[100];
	int		j;
	int		width;
	int		x;

	x = i;
	j = 0;
	while (ft_isdigit(str[x]))
	{
		nbr[j] = str[x];
		j++;
		x++;
		g_i++;
	}
	nbr[j] = '\0';
	width = ft_atoi(nbr);
	return (width);
}
