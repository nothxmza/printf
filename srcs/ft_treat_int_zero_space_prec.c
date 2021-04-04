/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_int_zero_space_prec.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <hterras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:09:29 by jbarette          #+#    #+#             */
/*   Updated: 2021/03/18 17:21:51 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_treat_int_zero_space_prec(int nbr, int width, int width_prec)
{
	int		char_count;
	int		x;
	int		y;
	char	*d_i;

	char_count = 0;
	x = nbr;
	if (x < 0)
		nbr *= -1;
	d_i = ft_itoa(nbr);
	char_count += ft_treat_int_zero_space_prec1(width_prec,
														width, x, d_i);
	if (x < 0 && x > -2147483648)
	{
		y = ft_strlen(d_i) + 1;
		char_count += ft_putchar('-');
	}
	else
		y = ft_strlen(d_i);
	char_count += ft_treat_int_zero_space_prec2(width, width_prec, d_i, y);
	char_count += ft_treat_int_zero_space_prec3(x, width_prec, d_i, width);
	char_count += ft_treat_int_zero_space_prec4(width, width_prec, y);
	free(d_i);
	return (char_count);
}

int		ft_treat_int_zero_space_prec1(int width_prec, int width,
											int x, char *d_i)
{
	int		char_count;
	int		diff;

	char_count = 0;
	diff = 0;
	if (width_prec >= 0)
	{
		if (width_prec == 0)
			char_count += (x < 0) ? ft_add_space(
			width - ft_strlen(d_i) - 1) : ft_add_space(width - ft_strlen(d_i));
		else
		{
			diff = (x < 0) ? ft_strlen(d_i) + 1 : ft_strlen(d_i);
			if (width_prec >= diff)
			{
				if (width > width_prec)
					char_count += (x < 0) ? ft_add_space(
					width - width_prec - 1) : ft_add_space(width - width_prec);
			}
			else
				char_count += ft_add_space(width - diff);
		}
	}
	return (char_count);
}

int		ft_treat_int_zero_space_prec2(int width, int width_prec,
											char *d_i, int y)
{
	int		char_count;
	int		diff;

	char_count = 0;
	diff = 0;
	if (width > 0)
	{
		if (width_prec < 0)
		{
			diff = width - y;
			while (diff-- > 0)
				char_count += ft_putchar('0');
		}
	}
	if (width_prec >= y)
	{
		diff = width_prec - ft_strlen(d_i);
		while (diff-- > 0)
			char_count += ft_putchar('0');
	}
	return (char_count);
}

int		ft_treat_int_zero_space_prec3(int x, int width_prec,
											char *d_i, int width)
{
	int		char_count;
	int		i;

	char_count = 0;
	i = 0;
	if (!(x == 0 && width_prec == 0))
	{
		while (d_i[i])
			char_count += ft_putchar(d_i[i++]);
	}
	else if (!(width == 0 && width_prec == 0 && x == 0))
		char_count += ft_add_space(1);
	return (char_count);
}

int		ft_treat_int_zero_space_prec4(int width, int width_prec, int y)
{
	int		char_count;

	char_count = 0;
	if (width < 0 && width_prec <= y)
	{
		width *= -1;
		char_count += ft_add_space(width - y);
	}
	return (char_count);
}
