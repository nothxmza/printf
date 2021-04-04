/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treatment_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <hterras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 23:23:26 by jbarette          #+#    #+#             */
/*   Updated: 2021/03/18 16:02:35 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_treat_string(const char *str, int width)
{
	int		i;
	int		char_count;

	i = 0;
	char_count = 0;
	if (!str)
		str = "(null)";
	while (str[i])
		char_count += ft_putchar(str[i++]);
	if (width < 0)
		width *= -1;
	if (width > 0)
		char_count += ft_add_space(width - ft_strlen(str));
	return (char_count);
}

int		ft_treat_u_prec(unsigned int nbr, int width)
{
	int		char_count;
	int		i;
	char	*nbrc;

	char_count = 0;
	nbr = (unsigned int)(4294967295 + 1 + nbr);
	i = 0;
	nbrc = ft_u_itoa(nbr);
	if (nbr != 0)
	{
		while (nbrc[i])
			char_count += ft_putchar(nbrc[i++]);
	}
	if (nbr != 0)
		char_count += ft_add_space(width - ft_strlen(nbrc));
	else if (width > 0)
		char_count += ft_add_space(width);
	free(nbrc);
	return (char_count);
}

int		ft_treat_character(char c, int width)
{
	int		char_count;

	char_count = 0;
	char_count += ft_putchar(c);
	if (width < 0)
		width *= -1;
	if (width > 0)
		char_count += ft_add_space(width - char_count);
	return (char_count);
}

int		ft_treat_uint(unsigned int nbr, int width)
{
	int		char_count;
	char	*nbrc;
	int		i;

	i = 0;
	char_count = 0;
	nbr = (unsigned int)(4294967295 + 1 + nbr);
	nbrc = ft_u_itoa(nbr);
	while (nbrc[i])
		char_count += ft_putchar(nbrc[i++]);
	if (width > 0)
		char_count += ft_add_space(width - ft_strlen(nbrc));
	free(nbrc);
	return (char_count);
}

int		ft_treat_pointer(unsigned long long pointer, int width)
{
	int		char_count;
	int		i;
	char	*str;
	int		total_convert;

	char_count = 0;
	i = 0;
	str = convert_base(pointer, 16);
	total_convert = ft_strlen(str);
	char_count += ft_putchar('0');
	char_count += ft_putchar('x');
	while (str[i])
		char_count += ft_putchar(ft_tolower(str[i++]));
	if (width > 0)
		char_count += ft_add_space(width - char_count);
	if (width < 0)
	{
		width *= -1;
		char_count += ft_add_space(width - char_count);
	}
	free(str);
	return (char_count);
}
