/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_hexa_zero_space_prec.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <hterras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:38:36 by jbarette          #+#    #+#             */
/*   Updated: 2021/03/18 17:21:36 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_treat_hexa_zero_space_prec(unsigned int nbr, int lower,
										int width, int width_prec)
{
	int		char_count;
	int		i;
	char	*hexa;

	char_count = 0;
	i = 0;
	nbr = (unsigned int)(4294967295 + 1 + nbr);
	hexa = convert_base((unsigned long long)nbr, 16);
	char_count += ft_treat_hexa_zero_space_prec_utils2(width_prec, width, hexa);
	char_count += ft_treat_hexa_zero_space_prec_utils3(width, width_prec, hexa);
	char_count += ft_treat_hexa_zero_space_prec_utils1(width_prec, hexa);
	if (!(nbr == 0 && width_prec == 0))
	{
		while (hexa[i])
			char_count += (lower == 1) ? ft_putchar(
				ft_tolower(hexa[i++])) : ft_putchar(hexa[i++]);
	}
	else if (!(width == 0 && width_prec == 0 && nbr == 0))
		char_count += ft_add_space(1);
	char_count += ft_treat_hexa_zero_space_prec_utils4(width, width_prec, hexa);
	free(hexa);
	return (char_count);
}

int		ft_treat_hexa_zero_space_prec_utils1(int width_prec, char *hexa)
{
	int		char_count;
	int		diff;

	char_count = 0;
	diff = 0;
	if (width_prec >= ft_strlen(hexa))
	{
		diff = width_prec - ft_strlen(hexa);
		while (diff-- > 0)
			char_count += ft_putchar('0');
	}
	return (char_count);
}

int		ft_treat_hexa_zero_space_prec_utils2(int width_prec,
												int width, char *hexa)
{
	int		char_count;
	int		diff;

	char_count = 0;
	diff = 0;
	if (width_prec >= 0)
	{
		if (width_prec == 0)
			char_count += ft_add_space(width - ft_strlen(hexa));
		else
		{
			diff = ft_strlen(hexa);
			if (width_prec >= diff)
			{
				if (width > width_prec)
					char_count += ft_add_space(width - width_prec);
			}
			else
				char_count += ft_add_space(width - diff);
		}
	}
	return (char_count);
}

int		ft_treat_hexa_zero_space_prec_utils3(int width,
												int width_prec, char *hexa)
{
	int		char_count;
	int		diff;

	char_count = 0;
	diff = 0;
	if (width > 0)
	{
		if (width_prec < 0)
		{
			diff = width - ft_strlen(hexa);
			while (diff > 0)
			{
				char_count += ft_putchar('0');
				diff--;
			}
		}
	}
	return (char_count);
}

int		ft_treat_hexa_zero_space_prec_utils4(int width,
												int width_prec, char *hexa)
{
	int		char_count;

	char_count = 0;
	if (width < 0 && width_prec <= ft_strlen(hexa))
	{
		width *= -1;
		char_count += ft_add_space(width - ft_strlen(hexa));
	}
	return (char_count);
}
