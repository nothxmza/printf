/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_hexa_minus_space_prec.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <hterras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:10:03 by jbarette          #+#    #+#             */
/*   Updated: 2021/03/18 17:21:34 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_treat_hexa_minus_space_prec(unsigned int nbr, int lower,
										int width, int width_prec)
{
	int		char_count;
	int		diff;
	char	*hexa;

	char_count = 0;
	diff = 0;
	nbr = (unsigned int)(4294967295 + 1 + nbr);
	hexa = convert_base((unsigned long long)nbr, 16);
	if (width_prec > ft_strlen(hexa))
	{
		diff = width_prec - ft_strlen(hexa);
		while (diff > 0)
		{
			char_count += ft_putnbr(0);
			diff--;
		}
	}
	char_count += ft_treat_hexa_minus_space_prec1(width_prec, nbr, hexa, lower);
	if (width < 0)
		width *= -1;
	if (width > 0)
		char_count += ft_add_space(width - char_count);
	free(hexa);
	return (char_count);
}

int		ft_treat_hexa_minus_space_prec1(int width_prec, unsigned int nbr,
											char *hexa, int lower)
{
	int		char_count;
	int		i;

	char_count = 0;
	i = 0;
	if (width_prec != 0 || nbr != 0)
	{
		while (hexa[i])
		{
			if (lower == 1)
				char_count += ft_putchar(ft_tolower(hexa[i++]));
			else
				char_count += ft_putchar(hexa[i++]);
		}
	}
	return (char_count);
}
