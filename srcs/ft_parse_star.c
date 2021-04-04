/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_star.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <hterras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 13:00:58 by hterras           #+#    #+#             */
/*   Updated: 2021/03/18 17:21:21 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parse_star(const char *str, va_list args)
{
	int		char_count;
	int		width;

	char_count = 0;
	width = 0;
	if (str[g_i + 1] == '.')
	{
		g_i += 1;
		if (ft_isdigit(str[g_i + 1]))
			char_count += ft_parse_isdigit_star2(str, args);
		else if (str[g_i + 1] == '*')
			char_count += ft_parse_star2(str, args);
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

int		ft_parse_star2(const char *str, va_list args)
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
		char_count += ft_treat_int_dot_space_prec(
			va_arg(args, int), width, width_prec);
	else if (str[g_i] == 'u')
		char_count += ft_treat_u_dot_space_prec(
			va_arg(args, int), width, width_prec);
	else if (str[g_i] == 'x')
		char_count += ft_treat_hexa_dot_space_prec(
			va_arg(args, unsigned int), 1, width, width_prec);
	else if (str[g_i] == 'X')
		char_count += ft_treat_hexa_dot_space_prec(
			va_arg(args, unsigned int), 0, width, width_prec);
	g_i++;
	return (char_count);
}

int		ft_parse_isdigit_star2(const char *str, va_list args)
{
	int		char_count;
	int		width_prec;

	char_count = 0;
	g_i += 1;
	width_prec = ft_take_width(str, g_i);
	char_count += ft_treatment_dot_space_prec(str, args, width_prec);
	return (char_count);
}
