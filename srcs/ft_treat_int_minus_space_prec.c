/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_int_minus_space_prec.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <hterras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:08:14 by jbarette          #+#    #+#             */
/*   Updated: 2021/03/18 17:21:49 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_treat_int_minus_space_prec(int nbr,
										int width, int width_prec)
{
	int		char_count;
	int		i;
	int		x;
	int		diff;
	char	*d_i;

	char_count = 0;
	i = 0;
	x = nbr;
	diff = 0;
	if (x < 0)
		nbr *= -1;
	d_i = ft_itoa(nbr);
	if (x < 0 && x > -2147483648)
		char_count += ft_putchar('-');
	char_count += ft_treat_int_minus_space_prec1(width_prec, d_i, width, x);
	if (width < 0)
		width *= -1;
	if (width > 0)
		char_count += ft_add_space(width - char_count);
	free(d_i);
	return (char_count);
}

int		ft_treat_int_minus_space_prec1(int width_prec, char *d_i,
										int width, int x)
{
	int		char_count;
	int		diff;
	int		i;

	char_count = 0;
	diff = 0;
	i = 0;
	if (width_prec > ft_strlen(d_i))
	{
		diff = width_prec - ft_strlen(d_i);
		while (diff > 0)
		{
			char_count += ft_putchar('0');
			diff--;
		}
	}
	if (width_prec != 0 || x != 0)
	{
		while (d_i[i])
			char_count += ft_putchar(d_i[i++]);
	}
	else if (width != 0 && width_prec != 0 && x != 0)
		char_count += ft_add_space(1);
	return (char_count);
}
