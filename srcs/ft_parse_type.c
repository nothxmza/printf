/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <hterras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 23:19:10 by jbarette          #+#    #+#             */
/*   Updated: 2021/03/18 17:21:28 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parse_type(char type, va_list args, int width)
{
	int		char_count;

	char_count = 0;
	if (type == 's')
		char_count += ft_treat_string(va_arg(args, char *), width);
	if (type == 'i' || type == 'd')
		char_count += ft_treat_int(va_arg(args, int), width);
	if (type == 'c')
		char_count += ft_treat_character(
						(unsigned char)va_arg(args, int), width);
	if (type == 'u')
		char_count += ft_treat_uint(va_arg(args, unsigned int), width);
	if (type == 'p')
		char_count += ft_treat_pointer(va_arg(args, unsigned long long), width);
	if (type == 'x')
		char_count += ft_treat_hexa(va_arg(args, unsigned int), 1, width);
	if (type == 'X')
		char_count += ft_treat_hexa(va_arg(args, unsigned int), 0, width);
	return (char_count);
}

int		ft_parse_type_prec(char type, va_list args, int width)
{
	int		char_count;

	char_count = 0;
	if (type == 's')
		char_count += ft_treat_string(va_arg(args, char *), width);
	if (type == 'i' || type == 'd')
		char_count += ft_treat_int_prec(va_arg(args, int), width);
	if (type == 'c')
		char_count += ft_treat_character(
						(unsigned char)va_arg(args, int), width);
	if (type == 'u')
		char_count += ft_treat_u_prec(va_arg(args, unsigned int),
										width);
	if (type == 'x')
		char_count += ft_treat_hexa_prec(va_arg(args, unsigned int),
											1, width);
	if (type == 'X')
		char_count += ft_treat_hexa_prec(va_arg(args, unsigned int),
											0, width);
	if (type == '%')
		char_count += ft_treat_percent_minus_space(width);
	return (char_count);
}

int		ft_parse_type_number(char type, va_list args, int width)
{
	int		char_count;

	char_count = 0;
	if (type == 's')
		char_count += ft_treat_string_number(va_arg(args, char *), width);
	if (type == 'i' || type == 'd')
		char_count += ft_treat_int_number(va_arg(args, int), width);
	if (type == 'c')
		char_count += ft_treat_character_number(
						(unsigned char)va_arg(args, int), width);
	if (type == 'u')
		char_count += ft_treat_u_number(va_arg(args, unsigned int), width);
	if (type == 'p')
		char_count += ft_treat_pointer_number(va_arg(args, unsigned long long),
												width);
	if (type == '%')
		char_count += ft_treat_percent_number(width);
	if (type == 'x')
		char_count += ft_treat_hexa_number(va_arg(args, unsigned int),
											1, width);
	if (type == 'X')
		char_count += ft_treat_hexa_number(va_arg(args, unsigned int),
											0, width);
	return (char_count);
}

int		ft_parse_type_number_zero(char type, va_list args, int width)
{
	int		char_count;

	char_count = 0;
	if (type == 'i' || type == 'd')
		char_count += ft_treat_int_number_zero(va_arg(args, int), width);
	if (type == 'u')
		char_count += ft_treat_u_number_zero(va_arg(args, unsigned int), width);
	if (type == 'x')
		char_count += ft_treat_hexa_number_zero(va_arg(args, unsigned int),
													1, width);
	if (type == 'X')
		char_count += ft_treat_hexa_number_zero(va_arg(args, unsigned int),
													0, width);
	return (char_count);
}
