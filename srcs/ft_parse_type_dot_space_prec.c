/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_type_dot_space_prec.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <hterras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:21:21 by hterras           #+#    #+#             */
/*   Updated: 2021/03/18 17:21:23 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parse_type_int(va_list args,
					int width, int width_prec)
{
	int		nbr;
	int		char_count;

	char_count = 0;
	nbr = va_arg(args, int);
	if (nbr == 0 && width_prec == 0)
		char_count += ft_treat_uint_dot(width);
	else
		char_count += ft_treat_int_dot_space_prec(nbr, width, width_prec);
	return (char_count);
}

int		ft_parse_type_u(va_list args, int width, int width_prec)
{
	int		nbr;
	int		char_count;

	char_count = 0;
	nbr = va_arg(args, unsigned int);
	if (nbr == 0 && width_prec == 0)
		char_count += ft_treat_umax_dot(width);
	else
		char_count += ft_treat_u_dot_space_prec(nbr, width, width_prec);
	return (char_count);
}

int		ft_parse_type_x(va_list args,
				int width, int width_prec)
{
	int		nbr;
	int		char_count;

	char_count = 0;
	nbr = va_arg(args, unsigned int);
	if (nbr == 0 && width_prec == 0)
		char_count += ft_treat_umax_dot(width);
	else
		char_count += ft_treat_hexa_dot_space_prec(nbr, 1, width, width_prec);
	return (char_count);
}

int		ft_parse_type_xcase(va_list args, int width, int width_prec)
{
	int		nbr;
	int		char_count;

	char_count = 0;
	nbr = va_arg(args, unsigned int);
	if (nbr == 0 && width_prec == 0)
		char_count += ft_treat_umax_dot(width);
	else
		char_count += ft_treat_hexa_dot_space_prec(nbr, 0, width, width_prec);
	return (char_count);
}
