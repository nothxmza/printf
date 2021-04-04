/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_isdigit_minus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <hterras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:42:31 by hterras           #+#    #+#             */
/*   Updated: 2021/03/18 17:22:52 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isdigit_and_minus(const char *str, va_list args, int width)
{
	int		char_count;
	int		width_prec;

	char_count = 0;
	g_i += 1;
	width_prec = ft_take_width(str, g_i);
	char_count += ft_parse_type_minus_space_prec(
					str[g_i], args, width, width_prec);
	return (char_count);
}

int		ft_isdigit_star(const char *str, va_list args, int width)
{
	int		char_count;
	int		width_prec;

	char_count = 0;
	g_i += 2;
	width_prec = va_arg(args, int);
	char_count += ft_parse_type_minus_space_prec(str[g_i], args,
				width, width_prec);
	return (char_count);
}

int		ft_isdigit_flag_minus(const char *str, va_list args)
{
	int		char_count;

	char_count = 0;
	char_count += ft_parse_flag(str, args);
	g_i -= 1;
	return (char_count);
}

int		ft_isdigit_minus_space_prec(const char *str, va_list args,
									int width)
{
	int		char_count;

	char_count = 0;
	g_i += 1;
	char_count += ft_parse_type_minus_space_prec(str[g_i], args, width, 0);
	return (char_count);
}
