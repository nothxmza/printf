/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_minus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <hterras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 12:46:33 by hterras           #+#    #+#             */
/*   Updated: 2021/03/18 17:21:10 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parse_minus(const char *str, va_list args)
{
	int		char_count;

	char_count = 0;
	if (ft_isdigit(str[g_i + 1]))
		char_count += ft_isdigit_minus(str, args);
	else if (str[g_i + 1] == '*')
		char_count += ft_parse_minus2(str, args);
	else if (str[g_i + 1] == '.' && str[g_i + 2] == '*')
		char_count += ft_parse_minus_dot_star(str, args);
	else if (str[g_i + 1] == '.')
		char_count += ft_parse_minus_dot(str, args);
	else if (ft_is_in_type_list(str[g_i + 1]))
	{
		g_i += 1;
		char_count += ft_parse_type(str[g_i], args, 0);
		g_i++;
	}
	else
	{
		g_i += 1;
		char_count += ft_parse_flag(str, args);
	}
	return (char_count);
}

int		ft_isdigit_minus(const char *str, va_list args)
{
	int		width;
	int		char_count;

	char_count = 0;
	g_i += 1;
	width = ft_take_width(str, g_i);
	if (ft_is_in_flag_list(str[g_i]))
	{
		if (ft_isdigit(str[g_i + 1]) && !(str[g_i] == '-'))
			char_count += ft_isdigit_and_minus(str, args, width);
		else if (str[g_i] == '%')
			char_count += ft_parse_type_minus_space_prec(
				str[g_i], args, width, 0);
		else if (str[g_i + 1] == '*')
			char_count += ft_isdigit_star(str, args, width);
		else if (str[g_i] == '-')
			char_count += ft_isdigit_flag_minus(str, args);
		else
			char_count += ft_isdigit_minus_space_prec(
				str, args, width);
	}
	else
		char_count += ft_parse_type(str[g_i], args, width);
	g_i++;
	return (char_count);
}

int		ft_parse_type_minus_space_prec(char type, va_list args,
									int width, int width_prec)
{
	int		char_count;

	char_count = 0;
	if (type == 's')
		char_count += ft_treat_string_minus_space_prec(va_arg(args, char *),
													width, width_prec);
	if (type == 'i' || type == 'd')
		char_count += ft_treat_int_minus_space_prec(va_arg(args, int),
													width, width_prec);
	if (type == 'p')
		char_count += ft_treat_pointer_minus_space_prec(
			va_arg(args, unsigned long long), width, width_prec);
	if (type == 'u')
		char_count += ft_treat_u_minus_space_prec(
			va_arg(args, unsigned int), width, width_prec);
	if (type == 'x')
		char_count += ft_treat_hexa_minus_space_prec(
			va_arg(args, unsigned int), 1, width, width_prec);
	if (type == 'X')
		char_count += ft_treat_hexa_minus_space_prec(
			va_arg(args, unsigned int), 0, width, width_prec);
	if (type == '%')
		char_count += ft_treat_percent_minus_space(width);
	return (char_count);
}
