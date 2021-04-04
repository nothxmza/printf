/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treatment_type_dot_pointer.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <hterras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:01:35 by jbarette          #+#    #+#             */
/*   Updated: 2021/03/18 17:22:29 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_treat_pointer_dot_space(unsigned long long nbr, int width)
{
	int		char_count;
	char	*nbrc;
	int		diff;

	diff = 0;
	char_count = 0;
	nbr = (unsigned int)(4294967295 + 1 + nbr);
	nbrc = convert_base(nbr, 16);
	if (!nbr)
		diff = width - 2;
	else
		diff = width - ft_strlen(nbrc);
	char_count += ft_add_space(diff);
	char_count += ft_treat_pointer_dot_space_utils(nbr, nbrc);
	free(nbrc);
	return (char_count);
}

int		ft_treat_pointer_dot_space_utils(unsigned long long nbr, char *nbrc)
{
	int		char_count;
	int		i;

	char_count = 0;
	i = 0;
	if (!nbr)
	{
		char_count += ft_putchar('0');
		char_count += ft_putchar('x');
	}
	else
	{
		if (nbr < 0)
			i -= 1;
		while (nbrc[i])
			char_count += ft_putchar(nbrc[i++]);
	}
	return (char_count);
}

int		ft_treat_pointer_dot_no_prec(unsigned long long nbr)
{
	int		char_count;
	int		i;
	char	*str;
	int		total_convert;

	char_count = 0;
	i = 0;
	if (!nbr)
	{
		char_count += ft_putchar('0');
		char_count += ft_putchar('x');
	}
	else
	{
		str = convert_base(nbr, 16);
		total_convert = ft_strlen(str);
		char_count += ft_putchar('0');
		char_count += ft_putchar('x');
		while (str[i])
			char_count += ft_putchar(ft_tolower(str[i++]));
		free(str);
	}
	return (char_count);
}
