/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_minus2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <hterras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:07:59 by hterras           #+#    #+#             */
/*   Updated: 2021/03/18 17:21:12 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parse_minus2(const char *str, va_list args)
{
	int		char_count;
	int		width;
	int		width_prec;

	char_count = 0;
	width = va_arg(args, int);
	g_i += 2;
	if (str[g_i] == '.')
	{
		if (ft_isdigit(str[g_i + 1]))
			width_prec = ft_parse_isdigit_minus2(str);
		else
		{
			width_prec = va_arg(args, int);
			g_i += 2;
		}
		char_count += ft_parse_type_minus_space_prec(
			str[g_i], args, width, width_prec);
	}
	else
		char_count += ft_parse_type(str[g_i], args, width);
	g_i++;
	return (char_count);
}

int		ft_parse_isdigit_minus2(const char *str)
{
	int		width_prec;

	g_i += 1;
	width_prec = ft_take_width(str, g_i);
	return (width_prec);
}

int		ft_parse_minus_dot_star(const char *str, va_list args)
{
	int		width;
	int		char_count;

	char_count = 0;
	g_i += 2;
	width = va_arg(args, int);
	g_i += 1;
	char_count += ft_parse_type_dot(str[g_i], args, width);
	g_i++;
	return (char_count);
}

int		ft_parse_minus_dot(const char *str, va_list args)
{
	int		width;
	int		char_count;

	char_count = 0;
	g_i += 2;
	width = ft_take_width(str, g_i);
	char_count += ft_parse_type_dot(str[g_i], args, width);
	g_i++;
	return (char_count);
}
