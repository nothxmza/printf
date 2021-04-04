/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treatment_flag_star.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <hterras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 13:09:29 by jbarette          #+#    #+#             */
/*   Updated: 2021/03/18 17:22:16 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_treatment_star(const char *str, va_list args, int width)
{
	int		char_count;

	char_count = 0;
	if (str[g_i - 1] == '%')
	{
		g_i += 1;
		char_count += ft_parse_type_number(str[g_i], args, width);
	}
	else
	{
		g_i += 1;
		char_count += ft_parse_type_zero(str[g_i], args, width);
	}
	g_i++;
	return (char_count);
}
