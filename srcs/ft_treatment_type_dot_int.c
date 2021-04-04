/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treatment_type_dot_int.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <hterras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 13:53:06 by jbarette          #+#    #+#             */
/*   Updated: 2021/03/18 17:22:27 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_treat_int_zero(int nbr, int width)
{
	int		char_count;
	int		i;
	int		x;
	char	*d_i;

	char_count = 0;
	i = 0;
	x = nbr;
	if (x < 0)
		nbr *= -1;
	d_i = ft_itoa(nbr);
	if (x < 0 && x > -2147483648)
		char_count += ft_putchar('-');
	char_count += ft_treat_int_zero1(width, x, d_i);
	while (d_i[i])
		char_count += ft_putchar(d_i[i++]);
	if (width < 0)
	{
		width *= -1;
		char_count += ft_add_space(width - char_count);
	}
	free(d_i);
	return (char_count);
}

int		ft_treat_int_zero1(int width, int x, char *d_i)
{
	int		char_count;
	int		diff;

	char_count = 0;
	diff = 0;
	if (width > 0)
	{
		diff = (x < 0) ? width - ft_strlen(d_i) - 1 : width - ft_strlen(d_i);
		while (diff > 0)
		{
			char_count += ft_putchar('0');
			diff--;
		}
	}
	return (char_count);
}

int		ft_treat_int_dot_no_prec(int nbr)
{
	int		char_count;
	int		i;
	int		x;
	char	*d_i;

	char_count = 0;
	i = 0;
	x = nbr;
	d_i = ft_itoa(nbr);
	if (nbr != 0)
	{
		while (d_i[i])
			char_count += ft_putchar(d_i[i++]);
	}
	free(d_i);
	return (char_count);
}

int		ft_treat_int_dot_space(int nbr, int width)
{
	int		char_count;
	int		i;
	char	*d_i;

	char_count = 0;
	i = 0;
	d_i = ft_itoa(nbr);
	if (width > 0)
		char_count += ft_add_space(width - ft_strlen(d_i));
	if (nbr != 0)
	{
		while (d_i[i])
			char_count += ft_putchar(d_i[i++]);
	}
	else
		char_count += ft_add_space(1);
	free(d_i);
	return (char_count);
}
