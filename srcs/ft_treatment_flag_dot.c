/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treatment_flag_dot.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <hterras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 13:19:47 by jbarette          #+#    #+#             */
/*   Updated: 2021/03/18 17:22:12 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_treatment_dot(const char *str, va_list args, int width)
{
	int		char_count;

	char_count = 0;
	char_count += ft_parse_type_dot(str[g_i], args, width);
	g_i += 1;
	return (char_count);
}

int		ft_treatment_dot_no_prec(const char *str, va_list args)
{
	int		char_count;

	char_count = 0;
	char_count += ft_parse_type_dot_no_prec(str[g_i], args);
	g_i += 1;
	return (char_count);
}

int		ft_treatment_dot_space(const char *str, va_list args, int width)
{
	int		char_count;

	char_count = 0;
	g_i = g_i + 1;
	char_count += ft_parse_type_dot_space(str[g_i], args, width);
	g_i++;
	return (char_count);
}

int		ft_treatment_dot_space_prec(const char *str, va_list args,
									int width_prec)
{
	int		width;
	int		char_count;

	char_count = 0;
	width = va_arg(args, int);
	if (width >= 0)
		char_count += ft_parse_type_dot_space_prec(str[g_i],
							args, width, width_prec);
	else
	{
		width *= -1;
		char_count += ft_parse_type_prec(str[g_i], args, width);
	}
	g_i++;
	return (char_count);
}
