/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_string_minus_space_prec.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <hterras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:07:53 by jbarette          #+#    #+#             */
/*   Updated: 2021/03/18 17:21:57 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_treat_string_minus_space_prec(const char *str,
										int width, int width_prec)
{
	int		diff;
	int		char_count;

	char_count = 0;
	diff = 0;
	str = (!str) ? "(null)" : str;
	if (str && width_prec > 0)
	{
		diff = width_prec - ft_strlen(str);
		char_count += ft_treat_string_minus_space_prec1(str, width_prec);
	}
	else if (str && width_prec < 0)
	{
		width_prec *= -1;
		diff = ft_treat_string_minus_space_prec4(diff, width_prec, str);
		char_count += ft_treat_string_minus_space_prec2(str, width_prec);
	}
	if (width >= width_prec)
		char_count += ft_treat_string_minus_space_prec3(diff, width,
															str, width_prec);
	else
		char_count += ft_treat_string_minus_space_prec5(width, char_count);
	return (char_count);
}

int		ft_treat_string_minus_space_prec1(const char *str, int x)
{
	int		char_count;
	int		i;

	char_count = 0;
	i = 0;
	while (str[i] && x > 0)
	{
		char_count += ft_putchar(str[i++]);
		x--;
	}
	return (char_count);
}

int		ft_treat_string_minus_space_prec2(const char *str, int x)
{
	int		char_count;
	int		i;

	char_count = 0;
	i = 0;
	while (str[i])
	{
		char_count += ft_putchar(str[i++]);
		x--;
	}
	return (char_count);
}

int		ft_treat_string_minus_space_prec3(int diff, int width,
											const char *str, int width_prec)
{
	int		char_count;

	char_count = 0;
	if (diff > 0)
		char_count += ft_add_space(width - ft_strlen(str));
	else
		char_count += ft_add_space(width - width_prec);
	return (char_count);
}

int		ft_treat_string_minus_space_prec4(int diff, int x, const char *str)
{
	diff = ft_strlen(str) - x;
	if (diff < 0)
		diff *= -1;
	return (diff);
}
