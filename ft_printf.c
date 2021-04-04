/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <hterras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 22:59:53 by jbarette          #+#    #+#             */
/*   Updated: 2021/03/18 17:26:40 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	This global is used to simplify the workflow and reduce the number
**	of step needed to backup the count from putchar
*/
int		g_i;

int		ft_treatment(const char *str, va_list args)
{
	int		char_count;

	g_i = 0;
	char_count = 0;
	while (str[g_i])
	{
		if (str[g_i] == '%')
			char_count += ft_treatment_percent(str, args);
		else
		{
			char_count += ft_putchar(str[g_i]);
			g_i++;
		}
	}
	return (char_count);
}

int		ft_printf(const char *str, ...)
{
	int		char_count;
	va_list	args;

	char_count = 0;
	va_start(args, str);
	char_count += ft_treatment(str, args);
	va_end(args);
	return (char_count);
}
