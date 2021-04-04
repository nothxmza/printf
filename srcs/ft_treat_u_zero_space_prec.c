/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_u_zero_space_prec.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <hterras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:48:18 by jbarette          #+#    #+#             */
/*   Updated: 2021/03/18 17:22:07 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_treat_u_zero_space_prec(unsigned int nbr, int width, int width_prec)
{
	int		char_count;
	int		i;
	char	*d_i;

	char_count = 0;
	i = 0;
	nbr = (unsigned int)(4294967295 + 1 + nbr);
	d_i = ft_u_itoa(nbr);
	char_count += ft_treat_u_zero_space_prec_utils1(width_prec, width, d_i);
	char_count += ft_treat_u_zero_space_prec_utils2(width, width_prec, d_i);
	char_count += ft_treat_u_zero_space_prec_utils3(width_prec, d_i);
	if (!(nbr == 0 && width_prec == 0))
	{
		while (d_i[i])
			char_count += ft_putchar(d_i[i++]);
	}
	else if (!(width == 0 && width_prec == 0 && nbr == 0))
		char_count += ft_add_space(1);
	if (width < 0 && width_prec <= ft_strlen(d_i))
	{
		width *= -1;
		char_count += ft_add_space(width - ft_strlen(d_i));
	}
	free(d_i);
	return (char_count);
}

int		ft_treat_u_zero_space_prec_utils1(int width_prec, int width, char *d_i)
{
	int		char_count;
	int		diff;

	char_count = 0;
	diff = 0;
	if (width_prec >= 0)
	{
		if (width_prec == 0)
			char_count += ft_add_space(width - ft_strlen(d_i));
		else
		{
			diff = ft_strlen(d_i);
			if (width_prec >= diff)
			{
				if (width > width_prec)
					char_count += ft_add_space(width - width_prec);
			}
			else
				char_count += ft_add_space(width - diff);
		}
	}
	return (char_count);
}

int		ft_treat_u_zero_space_prec_utils2(int width, int width_prec, char *d_i)
{
	int		char_count;
	int		diff;

	char_count = 0;
	diff = 0;
	if (width > 0)
	{
		if (width_prec < 0)
		{
			diff = width - ft_strlen(d_i);
			while (diff > 0)
			{
				char_count += ft_putchar('0');
				diff--;
			}
		}
	}
	return (char_count);
}

int		ft_treat_u_zero_space_prec_utils3(int width_prec, char *d_i)
{
	int		char_count;
	int		diff;

	char_count = 0;
	diff = 0;
	if (width_prec >= ft_strlen(d_i))
	{
		diff = width_prec - ft_strlen(d_i);
		while (diff > 0)
		{
			char_count += ft_putchar('0');
			diff--;
		}
	}
	return (char_count);
}
