/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treatment_flag_digit.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <hterras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 13:48:53 by jbarette          #+#    #+#             */
/*   Updated: 2021/03/18 17:22:09 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_treatment_digit(const char *str, va_list args)
{
	int		char_count;
	int		width;
	char	*widthc;

	char_count = 0;
	width = ft_take_width(str, g_i);
	widthc = ft_itoa(width);
	char_count += ft_treatment_digit_flag(str, args, width, widthc);
	g_i++;
	free(widthc);
	return (char_count);
}

int		ft_treatment_digit_flag(const char *str, va_list args,
								int width, char *widthc)
{
	int		char_count;
	int		width_prec;

	char_count = 0;
	width_prec = 0;
	if (str[g_i] == '.' && ft_isdigit(str[g_i + 1]))
		char_count += ft_treatment_digit_dot_flag(str, args, width);
	else if (str[g_i] == '.' && str[g_i + 1] == '*')
		char_count += ft_treatment_digit_dot_star_flag(str, args, width);
	else if (str[g_i] == '.')
	{
		g_i += 1;
		char_count += ft_parse_type_dot_space(str[g_i], args, width);
	}
	else if (str[g_i] == '*')
		char_count += ft_treatment_digit_star_flag(str, args);
	else if (str[g_i - ft_strlen(widthc) - 1] == '0' && str[g_i] == '%')
		char_count += ft_parse_type_dot_space(str[g_i], args, width);
	else if (str[g_i - ft_strlen(widthc) - 1] == '0')
		char_count += ft_parse_type_number_zero(str[g_i], args, width);
	else
		char_count += ft_parse_type_number(str[g_i], args, width);
	return (char_count);
}

int		ft_treatment_digit_star_flag(const char *str, va_list args)
{
	int		char_count;
	int		width;
	int		width_prec;

	char_count = 0;
	g_i += 1;
	width = va_arg(args, int);
	g_i += 1;
	width_prec = ft_take_width(str, g_i);
	char_count += ft_treat_percent_minus_space(width);
	return (char_count);
}

int		ft_treatment_digit_dot_flag(const char *str, va_list args, int width)
{
	int		char_count;
	int		width_prec;

	char_count = 0;
	g_i += 1;
	width_prec = ft_take_width(str, g_i);
	char_count += ft_parse_type_dot_space_prec(str[g_i], args,
												width, width_prec);
	return (char_count);
}

int		ft_treatment_digit_dot_star_flag(const char *str, va_list args,
										int width)
{
	int		char_count;
	int		width_prec;

	char_count = 0;
	width_prec = 0;
	g_i += 2;
	width_prec = va_arg(args, int);
	char_count += ft_parse_type_dot_space_prec(str[g_i], args,
												width, width_prec);
	return (char_count);
}
