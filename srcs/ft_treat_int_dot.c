/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_int_dot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <hterras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:56:42 by jbarette          #+#    #+#             */
/*   Updated: 2021/03/18 17:21:45 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_treat_int_dot(int nbr, int width)
{
	int		char_count;
	int		i;
	int		x;
	char	*d_i;

	char_count = 0;
	i = 0;
	x = nbr;
	if (x < 0)
		nbr *= -1;
	d_i = ft_itoa(nbr);
	if (x < 0 && x > -2147483648)
		char_count += ft_putchar('-');
	char_count += ft_treat_int_dot1(width, d_i);
	if (nbr != 0 || width != 0)
	{
		while (d_i[i])
			char_count += ft_putchar(d_i[i++]);
	}
	free(d_i);
	return (char_count);
}

int		ft_treat_int_dot1(int width, char *d_i)
{
	int		char_count;
	int		diff;

	char_count = 0;
	diff = 0;
	if (width > 0)
	{
		diff = width - ft_strlen(d_i);
		while (diff > 0)
		{
			char_count += ft_putchar('0');
			diff--;
		}
	}
	return (char_count);
}
