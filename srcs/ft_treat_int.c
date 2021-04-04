/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <hterras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:04:58 by jbarette          #+#    #+#             */
/*   Updated: 2021/03/18 15:58:57 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_treat_int(int nbr, int width)
{
	int		char_count;
	int		i;
	char	*d_i;

	char_count = 0;
	i = 0;
	d_i = ft_itoa(nbr);
	if (nbr < 0)
		nbr *= -1;
	while (d_i[i])
		char_count += ft_putchar(d_i[i++]);
	if (width < 0)
		width *= -1;
	if (width > 0)
		char_count += ft_add_space(width - ft_strlen(d_i));
	free(d_i);
	return (char_count);
}

int		ft_treat_int_prec(long int nbr, int width)
{
	int		char_count;
	char	*nbrc;

	char_count = 0;
	nbrc = ft_itoa(nbr);
	if (nbr < 0)
		ft_putchar_fd('-', 1);
	if (nbr != 0)
		char_count += ft_putnbr(nbr);
	if (nbr != 0)
		char_count += ft_add_space(width - ft_strlen(nbrc));
	else if (width > 0)
		char_count += ft_add_space(width);
	free(nbrc);
	return (char_count);
}

int		ft_treat_int_number(int nbr, int width)
{
	int		char_count;
	int		i;
	char	*d_i;

	char_count = 0;
	i = 0;
	d_i = ft_itoa(nbr);
	if (nbr < 0)
		nbr *= -1;
	if (width > 0)
		char_count += ft_add_space(width - ft_strlen(d_i));
	while (d_i[i])
		char_count += ft_putchar(d_i[i++]);
	if (width < 0)
	{
		width *= -1;
		char_count += ft_add_space(width - ft_strlen(d_i));
	}
	return (char_count);
}

int		ft_treat_int_number_zero(int nbr, int width)
{
	int		char_count;
	int		i;
	int		x;
	int		diff;
	char	*d_i;

	char_count = 0;
	i = 0;
	x = 0;
	diff = 0;
	if (nbr < 0)
		nbr *= 1;
	d_i = ft_itoa(nbr);
	char_count += (x < 0) ? ft_putchar('-') : 0;
	if (width >= 0)
	{
		diff = width - ft_strlen(d_i);
		while (diff-- > 0)
			char_count += ft_putchar('0');
		while (d_i[i])
			char_count += ft_putchar(d_i[i++]);
	}
	free(d_i);
	return (char_count);
}
