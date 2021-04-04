/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <hterras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:06:06 by jbarette          #+#    #+#             */
/*   Updated: 2021/03/18 15:57:39 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_treat_hexa(unsigned int nbr, int lower, int width)
{
	int		char_count;
	int		i;
	char	*hexa;

	char_count = 0;
	i = 0;
	nbr = (unsigned int)(4294967295 + 1 + nbr);
	hexa = convert_base((unsigned long long)nbr, 16);
	while (hexa[i])
	{
		if (lower == 1)
			char_count += ft_putchar(ft_tolower(hexa[i++]));
		else
			char_count += ft_putchar(hexa[i++]);
	}
	if (width < 0)
		width *= -1;
	if (width > 0)
		char_count += ft_add_space(width - char_count);
	free(hexa);
	return (char_count);
}

int		ft_treat_hexa_prec(unsigned int nbr, int lower,
								int width)
{
	int		char_count;
	int		i;
	char	*hexa;

	char_count = 0;
	i = 0;
	nbr = (unsigned int)(4294967295 + 1 + nbr);
	hexa = convert_base((unsigned long long)nbr, 16);
	if (nbr != 0)
	{
		while (hexa[i])
		{
			if (lower == 1)
				char_count += ft_putchar(ft_tolower(hexa[i++]));
			else
				char_count += ft_putchar(hexa[i++]);
		}
	}
	if (nbr != 0)
		char_count += ft_add_space(width - ft_strlen(hexa));
	else if (width > 0)
		char_count += ft_add_space(width);
	free(hexa);
	return (char_count);
}

int		ft_treat_hexa_number_zero(unsigned int nbr, int lower, int width)
{
	int		char_count;
	int		i;
	char	*hexa;
	int		diff;

	char_count = 0;
	i = 0;
	diff = 0;
	nbr = (unsigned int)(4294967295 + 1 + nbr);
	hexa = convert_base((unsigned long long)nbr, 16);
	diff = width - ft_strlen(hexa);
	while (diff > 0)
	{
		char_count += ft_putnbr(0);
		diff--;
	}
	while (hexa[i])
	{
		if (lower == 1)
			char_count += ft_putchar(ft_tolower(hexa[i++]));
		else
			char_count += ft_putchar(hexa[i++]);
	}
	free(hexa);
	return (char_count);
}

int		ft_treat_hexa_number(unsigned int nbr, int lower, int width)
{
	int		char_count;
	int		i;
	char	*hexa;

	char_count = 0;
	i = 0;
	nbr = (unsigned int)(4294967295 + 1 + nbr);
	hexa = convert_base((unsigned long long)nbr, 16);
	if (width > 0)
		char_count += ft_add_space(width - ft_strlen(hexa));
	while (hexa[i])
	{
		if (lower == 1)
			char_count += ft_putchar(ft_tolower(hexa[i++]));
		else
			char_count += ft_putchar(hexa[i++]);
	}
	if (width < 0)
	{
		width *= -1;
		char_count += ft_add_space(width - char_count);
	}
	free(hexa);
	return (char_count);
}
