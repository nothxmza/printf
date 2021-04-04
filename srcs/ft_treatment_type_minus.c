/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treatment_type_minus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <hterras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 12:40:36 by hterras           #+#    #+#             */
/*   Updated: 2021/03/18 17:22:40 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_treat_percent_minus_space(int width)
{
	int		i;
	int		char_count;

	i = 0;
	char_count = 0;
	char_count += ft_putchar('%');
	if (width > 0)
		char_count += ft_add_space(width - 1);
	else
	{
		width *= -1;
		char_count += ft_add_space(width - 1);
	}
	return (char_count);
}

int		ft_treat_pointer_minus_space_prec(unsigned long long nbr,
											int width, int width_prec)
{
	int		char_count;
	int		i;
	int		diff;
	char	*pointer;

	char_count = 0;
	i = 0;
	diff = 0;
	pointer = convert_base(nbr, 16);
	char_count += ft_putchar('0');
	char_count += ft_putchar('x');
	if (width_prec != 0 || nbr != 0)
	{
		while (pointer[i])
			char_count += ft_putchar(pointer[i++]);
	}
	if (width < 0)
		width *= -1;
	if (width > 0)
		char_count += ft_add_space(width - char_count);
	free(pointer);
	return (char_count);
}
