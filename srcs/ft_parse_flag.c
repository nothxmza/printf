/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <hterras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 13:32:00 by jbarette          #+#    #+#             */
/*   Updated: 2021/03/18 17:21:05 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parse_flag(const char *str, va_list args)
{
	int		char_count;

	char_count = 0;
	if (str[g_i] == '-' && str[g_i + 1] == '0')
	{
		g_i += 1;
		char_count += ft_parse_minus(str, args);
	}
	else if (str[g_i] == '-')
		char_count += ft_parse_minus(str, args);
	else if (str[g_i] == '*')
		char_count += ft_parse_star(str, args);
	else if (str[g_i] == '.')
		char_count += ft_parse_dot(str, args);
	else if (str[g_i] == '0' && ft_isdigit(str[g_i + 1]))
	{
		g_i += 1;
		char_count += ft_treatment_digit(str, args);
	}
	else
		char_count += ft_parse_flag2(str, args);
	return (char_count);
}
