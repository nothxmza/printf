/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_u_minus_space_prec.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <hterras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:08:42 by jbarette          #+#    #+#             */
/*   Updated: 2021/03/18 17:22:05 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_treat_u_minus_space_prec(unsigned int nbr,
										int width, int width_prec)
{
	int		char_count;
	int		count_nbr;
	int		x;
	char	*nbrc;

	char_count = 0;
	x = 0;
	nbr = (unsigned int)(4294967295 + 1 + nbr);
	nbrc = ft_u_itoa(nbr);
	count_nbr = ft_strlen(nbrc);
	char_count += ft_treat_u_minus_space_prec1(width_prec, count_nbr);
	if (width_prec != 0 || nbr != 0)
	{
		while (nbrc[x])
			char_count += ft_putchar(nbrc[x++]);
	}
	if (width < 0)
		width *= -1;
	if (width > 0)
		char_count += ft_add_space(width - (char_count));
	free(nbrc);
	return (char_count);
}

int		ft_treat_u_minus_space_prec1(int width_prec, int count_nbr)
{
	int		char_count;
	int		diff;

	char_count = 0;
	diff = 0;
	if (width_prec > count_nbr)
	{
		diff = width_prec - count_nbr;
		while (diff > 0)
		{
			char_count += ft_putnbr(0);
			diff--;
		}
	}
	return (char_count);
}
