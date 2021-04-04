/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_dot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <hterras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 02:18:52 by jbarette          #+#    #+#             */
/*   Updated: 2021/03/19 12:49:12 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parse_dot(const char *str, va_list args)
{
	int		char_count;
	int		width;

	char_count = 0;
	if (ft_isdigit(str[g_i + 1]))
	{
		g_i += 1;
		width = ft_take_width(str, g_i);
		char_count += ft_treatment_dot(str, args, width);
	}
	else if (str[g_i += 1] == '*')
	{
		g_i += 1;
		width = va_arg(args, int);
		char_count += ft_treatment_dot(str, args, width);
	}
	else if (str[g_i - 1] == '0')
	{
		char_count += ft_treatment_dot(str, args, 0);
		g_i++;
	}
	else
		char_count += ft_treatment_dot_no_prec(str, args);
	return (char_count);
}

int		ft_parse_type_dot(char type, va_list args, int width)
{
	int		char_count;

	char_count = 0;
	if (type == 's')
		char_count += ft_treat_string_dot(va_arg(args, char *), width);
	if (type == 'i' || type == 'd')
		char_count += ft_treat_int_dot(va_arg(args, int), width);
	if (type == 'u')
		char_count += ft_treat_u_dot(va_arg(args, unsigned int), width);
	if (type == 'x')
		char_count += ft_treat_hexa_dot(va_arg(args, unsigned int), 1, width);
	if (type == 'X')
		char_count += ft_treat_hexa_dot(va_arg(args, unsigned int), 0, width);
	return (char_count);
}

int		ft_parse_type_dot_no_prec(char type, va_list args)
{
	int		char_count;

	char_count = 0;
	if (type == 's')
		char_count += ft_treat_string_dot_no_prec(args);
	if (type == 'i' || type == 'd')
		char_count += ft_treat_int_dot_no_prec(va_arg(args, int));
	if (type == 'u')
		char_count += ft_treat_u_dot_no_prec(va_arg(args, unsigned int));
	if (type == 'p')
		char_count += ft_treat_pointer_dot_no_prec(
			va_arg(args, unsigned long long));
	if (type == 'c')
		char_count += ft_treat_character_dot_prec(
			(unsigned char)va_arg(args, int));
	if (type == 'x')
		char_count += ft_treat_hexa_dot_no_prec(va_arg(args, unsigned int), 1);
	if (type == 'X')
		char_count += ft_treat_hexa_dot_no_prec(va_arg(args, unsigned int), 0);
	return (char_count);
}

int		ft_parse_type_dot_space(char type, va_list args, int width)
{
	int		char_count;

	char_count = 0;
	if (type == 's')
		char_count += ft_treat_string_dot_space(va_arg(args, char *), width);
	if (type == 'i' || type == 'd')
		char_count += ft_treat_int_dot_space(va_arg(args, int), width);
	if (type == 'u')
		char_count += ft_treat_u_dot_space(
			va_arg(args, unsigned int), width);
	if (type == 'p')
		char_count += ft_treat_pointer_dot_space(
			va_arg(args, unsigned long long), width);
	if (type == 'c')
		char_count += ft_treat_character_dot_space(
			(unsigned char)va_arg(args, int), width);
	if (type == 'x')
		char_count += ft_treat_x_dot_space(
			va_arg(args, unsigned int), 1, width);
	if (type == 'X')
		char_count += ft_treat_x_dot_space(
			va_arg(args, unsigned int), 0, width);
	if (type == '%')
		char_count += ft_treat_percent_dot_space(width);
	return (char_count);
}

int		ft_parse_type_dot_space_prec(char type, va_list args,
									int width, int width_prec)
{
	int		char_count;

	char_count = 0;
	if (type == 's')
		char_count += ft_treat_string_dot_space_prec(va_arg(args, char *),
													width, width_prec);
	else if (type == 'i' || type == 'd')
		char_count += ft_parse_type_int(args, width, width_prec);
	else if (type == 'u')
		char_count += ft_parse_type_u(args, width, width_prec);
	else if (type == 'x')
		char_count += ft_parse_type_x(args, width, width_prec);
	else if (type == 'X')
		char_count += ft_parse_type_xcase(args, width, width_prec);
	else if (type == '%')
		char_count += ft_treat_number_space_prec(width);
	return (char_count);
}
