/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treatment_percent.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <hterras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 13:22:08 by jbarette          #+#    #+#             */
/*   Updated: 2021/03/18 17:22:19 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_treatment_percent(const char *str, va_list args)
{
	int		char_count;

	char_count = 0;
	if (ft_is_in_type_list(str[g_i + 1]))
	{
		g_i += 1;
		char_count += ft_parse_type(str[g_i], args, 0);
		g_i += 1;
	}
	else if (ft_is_in_flag_list(str[g_i + 1]))
	{
		g_i += 1;
		char_count += ft_parse_flag(str, args);
	}
	else if (ft_isdigit(str[g_i + 1]))
	{
		g_i += 1;
		char_count += ft_treatment_digit(str, args);
	}
	else
	{
		char_count += ft_putchar(str[g_i]);
		g_i++;
	}
	return (char_count);
}

int		ft_treat_percent_number(int width)
{
	int		i;
	int		char_count;

	i = 0;
	char_count = 0;
	if (width > 0)
		char_count += ft_add_space(width - 1);
	char_count += ft_putchar('%');
	return (char_count);
}
