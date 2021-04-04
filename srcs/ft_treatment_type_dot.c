/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treatment_type_dot.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <hterras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 23:23:26 by jbarette          #+#    #+#             */
/*   Updated: 2021/03/18 17:22:38 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_treat_character_dot_space(char c, int width)
{
	int		i;
	int		char_count;

	i = 0;
	char_count = 0;
	char_count += ft_add_space(width - 1);
	char_count += ft_putchar(c);
	return (char_count);
}

int		ft_treat_percent_dot_space(int width)
{
	int		i;
	int		char_count;

	i = 0;
	char_count = 0;
	width -= 1;
	while (width > 0)
	{
		char_count += ft_putnbr(0);
		width--;
	}
	char_count += ft_putchar('%');
	return (char_count);
}

int		ft_treat_character_dot_prec(char c)
{
	int		char_count;

	char_count = 0;
	char_count += ft_putchar(c);
	return (char_count);
}

int		ft_treat_number_space_prec(int width)
{
	int		char_count;

	char_count = 0;
	if (width > 1)
	{
		width -= 1;
		while (width > 0)
		{
			char_count += ft_putnbr(0);
			width--;
		}
	}
	char_count += ft_putchar('%');
	return (char_count);
}
