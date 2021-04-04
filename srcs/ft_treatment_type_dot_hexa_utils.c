/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treatment_type_dot_hexa_utils.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <hterras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:18:06 by jbarette          #+#    #+#             */
/*   Updated: 2021/03/18 17:22:23 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_treat_hexa_dot_no_prec_utils1(int width, int width_prec, char *hexa)
{
	int		char_count;
	int		diff;

	char_count = 0;
	diff = 0;
	if (width_prec < 0)
		width_prec *= -1;
	if (width_prec > ft_strlen(hexa))
		diff = width_prec - ft_strlen(hexa);
	if ((width >= 0) && (width > (ft_strlen(hexa) + diff)))
		char_count += ft_add_space(width - (ft_strlen(hexa) + diff));
	while (diff > 0)
	{
		char_count += ft_putnbr(0);
		diff--;
	}
	return (char_count);
}

int		ft_treat_hexa_dot_no_prec_utils2(int width, int diff, char *hexa)
{
	int		char_count;

	char_count = 0;
	if ((width < 0))
	{
		width *= -1;
		if (width > (ft_strlen(hexa) + diff))
			char_count += ft_add_space(width - (ft_strlen(hexa) + diff));
	}
	return (char_count);
}

int		ft_treat_hexa_dot_no_prec_utils3(int width, char *hexa)
{
	int		char_count;
	int		i;

	char_count = 0;
	i = 0;
	if (width > ft_strlen(hexa))
	{
		i = width - ft_strlen(hexa);
		while (i > 0)
		{
			char_count += ft_putnbr(0);
			i--;
		}
	}
	return (char_count);
}

int		ft_treat_hexa_dot_no_prec_utils4(unsigned long long nbr,
											char *nbrc, int lower)
{
	int		char_count;
	int		i;

	char_count = 0;
	i = 0;
	if (nbr != 0)
	{
		if (nbr < 0)
			char_count += ft_putchar('-');
		if (nbr < 0)
			i -= 1;
		while (nbrc[i])
		{
			if (lower == 1)
				char_count += ft_putchar(ft_tolower(nbrc[i++]));
			else
				char_count += ft_putchar(nbrc[i++]);
		}
	}
	else
		char_count += ft_add_space(1);
	return (char_count);
}

int		ft_treat_hexa_dot_no_prec_utils5(int width)
{
	int		char_count;

	char_count = 0;
	if (width <= 0)
	{
		width *= -1;
		char_count += ft_add_space(width);
	}
	else
		char_count += ft_add_space(1);
	return (char_count);
}
