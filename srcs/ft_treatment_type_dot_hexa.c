/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treatment_type_dot_hexa.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <hterras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:01:43 by jbarette          #+#    #+#             */
/*   Updated: 2021/03/18 17:22:25 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_treat_x_dot_space(unsigned long long nbr, int lower, int width)
{
	int		i;
	int		char_count;
	char	*nbrc;
	int		diff;

	diff = 0;
	i = 0;
	char_count = 0;
	nbr = (unsigned int)(4294967295 + 1 + nbr);
	nbrc = convert_base(nbr, 16);
	diff = width - ft_strlen(nbrc);
	char_count += ft_add_space(diff);
	char_count += ft_treat_hexa_dot_no_prec_utils4(nbr, nbrc, lower);
	free(nbrc);
	return (char_count);
}

int		ft_treat_hexa_dot(unsigned int nbr, int lower, int width)
{
	int		char_count;
	int		i;
	char	*hexa;

	char_count = 0;
	i = 0;
	nbr = (unsigned int)(4294967295 + 1 + nbr);
	hexa = convert_base((unsigned long long)nbr, 16);
	char_count += ft_treat_hexa_dot_no_prec_utils3(width, hexa);
	i = 0;
	if (width != 0 || nbr != 0)
	{
		if (lower == 1)
		{
			while (hexa[i])
				char_count += ft_putchar(ft_tolower(hexa[i++]));
		}
		else
		{
			while (hexa[i])
				char_count += ft_putchar(hexa[i++]);
		}
	}
	free(hexa);
	return (char_count);
}

int		ft_treat_hexa_zero(unsigned int nbr, int lower, int width)
{
	int		char_count;
	int		i;
	char	*hexa;

	char_count = 0;
	i = 0;
	nbr = (unsigned int)(4294967295 + 1 + nbr);
	hexa = convert_base((unsigned long long)nbr, 16);
	char_count += ft_treat_hexa_dot_no_prec_utils3(width, hexa);
	i = 0;
	if (lower == 1)
	{
		while (hexa[i])
			char_count += ft_putchar(ft_tolower(hexa[i++]));
	}
	else
	{
		while (hexa[i])
			char_count += ft_putchar(hexa[i++]);
	}
	free(hexa);
	return (char_count);
}

int		ft_treat_hexa_dot_space_prec(unsigned int nbr, int lower,
										int width, int width_prec)
{
	int		char_count;
	int		diff;
	int		i;
	char	*hexa;

	char_count = 0;
	diff = 0;
	i = 0;
	nbr = (unsigned int)(4294967295 + 1 + nbr);
	hexa = convert_base((unsigned long long)nbr, 16);
	char_count += ft_treat_hexa_dot_no_prec_utils1(width, width_prec, hexa);
	if (!(width_prec == 0 && nbr == 0))
	{
		while (hexa[i])
			char_count += (lower == 1) ? ft_putchar(
				ft_tolower(hexa[i++])) : ft_putchar(hexa[i++]);
	}
	else
		char_count += ft_treat_hexa_dot_no_prec_utils5(width);
	char_count += ft_treat_hexa_dot_no_prec_utils2(width, diff, hexa);
	free(hexa);
	return (char_count);
}

int		ft_treat_hexa_dot_no_prec(unsigned long long nbr, int lower)
{
	int		char_count;
	int		i;
	char	*str;
	int		total_convert;

	char_count = 0;
	i = 0;
	str = convert_base(nbr, 16);
	total_convert = ft_strlen(str);
	if (nbr)
	{
		while (str[i])
		{
			if (lower == 1)
				char_count += ft_putchar(ft_tolower(str[i++]));
			else
				char_count += ft_putchar(str[i++]);
		}
	}
	free(str);
	return (char_count);
}
