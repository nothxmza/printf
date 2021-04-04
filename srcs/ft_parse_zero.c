/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_zero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <hterras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 15:56:06 by hterras           #+#    #+#             */
/*   Updated: 2021/03/18 17:21:30 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parse_zero(const char *str, va_list args)
{
	int		char_count;
	int		width;

	char_count = 0;
	width = 0;
	if (str[g_i + 1] == '.')
	{
		g_i += 1;
		if (ft_isdigit(str[g_i + 1]))
			char_count += ft_parse_zero_isdigit(str, args);
		else if (str[g_i + 1] == '*')
			char_count += ft_parse_zero2(str, args);
		else
		{
			width = va_arg(args, int);
			char_count += ft_treatment_dot_space(str, args, width);
		}
	}
	else
	{
		width = va_arg(args, int);
		char_count += ft_treatment_star(str, args, width);
	}
	return (char_count);
}

int		ft_parse_zero2(const char *str, va_list args)
{
	int		width_prec;
	int		char_count;
	int		width;

	char_count = 0;
	width = va_arg(args, int);
	width_prec = va_arg(args, int);
	g_i += 2;
	if (str[g_i] == 's')
		char_count += ft_treat_string_dot_space_prec(
			va_arg(args, char *), width, width_prec);
	else if (str[g_i] == 'i' || str[g_i] == 'd')
		char_count += ft_treat_int_zero_space_prec(
			va_arg(args, int), width, width_prec);
	else if (str[g_i] == 'u')
		char_count += ft_treat_u_zero_space_prec(
			va_arg(args, int), width, width_prec);
	else if (str[g_i] == 'x')
		char_count += ft_treat_hexa_zero_space_prec(
			va_arg(args, unsigned int), 1, width, width_prec);
	else if (str[g_i] == 'X')
		char_count += ft_treat_hexa_zero_space_prec(
			va_arg(args, unsigned int), 0, width, width_prec);
	g_i++;
	return (char_count);
}

int		ft_parse_zero_isdigit(const char *str, va_list args)
{
	int		char_count;
	int		width_prec;

	char_count = 0;
	g_i += 1;
	width_prec = ft_take_width(str, g_i);
	char_count += ft_treatment_dot_space_prec(str, args, width_prec);
	return (char_count);
}
