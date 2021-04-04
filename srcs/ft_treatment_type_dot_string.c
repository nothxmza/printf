/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treatment_type_dot_string.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <hterras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 13:56:26 by jbarette          #+#    #+#             */
/*   Updated: 2021/03/19 12:54:13 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_treat_string_dot(const char *str, int width)
{
	int		i;
	int		char_count;

	i = 0;
	char_count = 0;
	str = (!str) ? "(null)" : str;
	if (width > 0)
	{
		while (str[i] && width > 0)
		{
			char_count += ft_putchar(str[i]);
			i++;
			width--;
		}
	}
	else
	{
		if (width != 0)
		{
			while (str[i])
				char_count += ft_putchar(str[i++]);
		}
	}
	return (char_count);
}

int		ft_treat_string_dot_no_prec(va_list args)
{
	int		char_count;

	va_arg(args, int);
	char_count = 0;
	return (char_count);
}

int		ft_treat_string_dot_space(const char *str, int width)
{
	int		i;
	int		char_count;

	i = 0;
	char_count = 0;
	char_count += ft_add_space(width);
	while (str[i])
		i++;
	return (char_count);
}

int		ft_treat_string_dot_space_prec(const char *str,
										int width, int width_prec)
{
	int		i;
	int		char_count;

	i = 0;
	char_count = 0;
	str = !(str) ? "(null)" : str;
	if (width_prec >= 0 && width_prec > ft_strlen(str))
		width_prec = ft_strlen(str);
	if (width_prec >= 0)
		char_count += ft_add_space(width - width_prec);
	else
		char_count += ft_add_space(width - ft_strlen(str));
	while (str[i] && width_prec != 0)
	{
		char_count += ft_putchar(str[i++]);
		width_prec--;
	}
	if (width < 0)
	{
		width *= -1;
		char_count += ft_add_space(width - i);
	}
	return (char_count);
}
