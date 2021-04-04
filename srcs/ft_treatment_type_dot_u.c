/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treatment_type_dot_u.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <hterras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:01:57 by jbarette          #+#    #+#             */
/*   Updated: 2021/03/18 17:22:35 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_treat_u_dot_no_prec(int nbr)
{
	int		i;
	int		char_count;
	char	*nbrc;
	int		diff;

	diff = 0;
	i = 0;
	char_count = 0;
	nbr = (unsigned int)(4294967295 + 1 + nbr);
	nbrc = ft_u_itoa(nbr);
	if (nbr != 0)
	{
		if (nbr < 0)
			i -= 1;
		char_count += ft_putnbr(nbr);
	}
	free(nbrc);
	return (char_count);
}

int		ft_treat_uint_dot(int width)
{
	int		char_count;

	char_count = 0;
	char_count += ft_add_space(width);
	return (char_count);
}

int		ft_treat_umax_dot(int width)
{
	int		char_count;

	char_count = 0;
	char_count += ft_add_space(width);
	return (char_count);
}

int		ft_treat_u_dot(unsigned int nbr, int width)
{
	int		i;
	int		char_count;
	char	*nbrc;

	i = 0;
	char_count = 0;
	nbr = (unsigned int)(4294967295 + 1 + nbr);
	nbrc = ft_u_itoa(nbr);
	if (width > ft_strlen(nbrc))
	{
		i = width - ft_strlen(nbrc);
		while (i > 0)
		{
			char_count += ft_putnbr(0);
			i--;
		}
	}
	i = 0;
	if (width != 0 || nbr != 0)
	{
		while (nbrc[i])
			char_count += ft_putchar(nbrc[i++]);
	}
	free(nbrc);
	return (char_count);
}

int		ft_treat_u_zero(unsigned int nbr, int width)
{
	int		i;
	int		char_count;
	char	*nbrc;

	i = 0;
	char_count = 0;
	nbr = (unsigned int)(4294967295 + 1 + nbr);
	nbrc = ft_u_itoa(nbr);
	if (width > ft_strlen(nbrc))
	{
		i = width - ft_strlen(nbrc);
		while (i > 0)
		{
			char_count += ft_putnbr(0);
			i--;
		}
	}
	i = 0;
	while (nbrc[i])
		char_count += ft_putchar(nbrc[i++]);
	free(nbrc);
	return (char_count);
}
