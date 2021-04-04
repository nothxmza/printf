/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treatment_type_number.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <hterras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 23:23:26 by jbarette          #+#    #+#             */
/*   Updated: 2021/03/18 17:22:42 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_treat_string_number(const char *str, int width)
{
	int		i;
	int		char_count;

	i = 0;
	char_count = 0;
	if (!str)
		str = "(null)";
	while (str[i])
		i++;
	if (width > 0)
		char_count += ft_add_space(width - i);
	i = 0;
	while (str[i])
		char_count += ft_putchar(str[i++]);
	if (width < 0)
	{
		width *= -1;
		char_count += ft_add_space(width - i);
	}
	return (char_count);
}

int		ft_treat_character_number(char c, int width)
{
	int		char_count;

	char_count = 0;
	if (width > 0)
		char_count += ft_add_space(width - 1);
	char_count += ft_putchar(c);
	if (width < 0)
	{
		width *= -1;
		char_count += ft_add_space(width - 1);
	}
	return (char_count);
}

int		ft_treat_u_number(unsigned int nbr, int width)
{
	int		char_count;
	int		i;
	char	*nbrc;

	char_count = 0;
	i = 0;
	nbr = (unsigned int)(4294967295 + 1 + nbr);
	nbrc = ft_u_itoa(nbr);
	if (width > 0)
		char_count += ft_add_space(width - ft_strlen(nbrc));
	while (nbrc[i])
		char_count += ft_putchar(nbrc[i++]);
	if (width < 0)
	{
		width *= -1;
		char_count += ft_add_space(width - ft_strlen(nbrc));
	}
	free(nbrc);
	return (char_count);
}

int		ft_treat_pointer_number(unsigned long long pointer, int width)
{
	int		char_count;
	int		i;
	int		total_convert;
	char	*str;

	char_count = 0;
	i = 0;
	total_convert = 0;
	str = convert_base(pointer, 16);
	total_convert = ft_strlen(str);
	if (width > 0)
		char_count += ft_add_space(width - (total_convert + 2));
	char_count += ft_putchar('0');
	char_count += ft_putchar('x');
	while (str[i])
		char_count += ft_putchar(ft_tolower(str[i++]));
	if (width < 0)
	{
		width *= -1;
		char_count += ft_add_space(width - (total_convert + 2));
	}
	free(str);
	return (char_count);
}

int		ft_treat_u_number_zero(unsigned int nbr, int width)
{
	int		char_count;
	char	*nbrc;
	int		diff;
	int		i;

	i = 0;
	diff = 0;
	char_count = 0;
	nbr = (unsigned int)(4294967295 + 1 + nbr);
	nbrc = ft_u_itoa(nbr);
	if (width > 0)
	{
		diff = width - ft_strlen(nbrc);
		while (diff > 0)
		{
			char_count += ft_putnbr(0);
			diff--;
		}
	}
	while (nbrc[i])
		char_count += ft_putchar(nbrc[i++]);
	free(nbrc);
	return (char_count);
}
