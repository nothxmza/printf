/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_int_dot_space_prec.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <hterras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:39:22 by jbarette          #+#    #+#             */
/*   Updated: 2021/03/18 17:21:42 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_treat_int_dot_space_prec(int nbr, int width, int width_prec)
{
	int		char_count;
	int		x;
	int		diff;
	char	*d_i;

	char_count = 0;
	diff = 0;
	x = nbr;
	if (x < 0)
		nbr *= -1;
	d_i = ft_itoa(nbr);
	if (width_prec > 0)
		diff = (width_prec > ft_strlen(d_i)) ?
		width_prec - ft_strlen(d_i) : diff;
	else
		diff = 0;
	char_count += ft_treat_int_dot_space_prec2(width, d_i, diff, x);
	char_count += ft_treat_int_dot_space_prec1(width, width_prec, x, d_i);
	if (width < 0)
	{
		width *= -1;
		char_count += ft_add_space(width - char_count);
	}
	free(d_i);
	return (char_count);
}

int		ft_treat_int_dot_space_prec1(int width, int width_prec,
										int x, char *d_i)
{
	int		char_count;
	int		i;

	char_count = 0;
	i = 0;
	if (width_prec >= 0)
	{
		if (width_prec != 0 || x != 0)
		{
			while (d_i[i])
				char_count += ft_putchar(d_i[i++]);
		}
		else if (width != 0 || width_prec != 0 || x != 0)
			char_count += ft_add_space(1);
	}
	else
	{
		while (d_i[i])
			char_count += ft_putchar(d_i[i++]);
	}
	return (char_count);
}

int		ft_treat_int_dot_space_prec2(int width, char *d_i, int diff, int x)
{
	int		char_count;

	char_count = 0;
	if (width > (ft_strlen(d_i) + diff))
	{
		if (x < 0 && x > -2147483648)
			char_count += ft_add_space(width - (ft_strlen(d_i) + diff + 1));
		else
			char_count += ft_add_space(width - (ft_strlen(d_i) + diff));
	}
	if (x < 0 && x > -2147483648)
		char_count += ft_putchar('-');
	while (diff > 0)
	{
		char_count += ft_putchar('0');
		diff--;
	}
	return (char_count);
}
