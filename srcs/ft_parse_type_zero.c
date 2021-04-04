/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_type_zero.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <hterras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:14:50 by hterras           #+#    #+#             */
/*   Updated: 2021/03/18 17:21:25 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parse_type_zero(char type, va_list args, int width)
{
	int		char_count;

	char_count = 0;
	if (type == 's')
		char_count += ft_treat_string_dot(va_arg(args, char *), width);
	if (type == 'i' || type == 'd')
		char_count += ft_treat_int_zero(va_arg(args, int), width);
	if (type == 'u')
		char_count += ft_treat_u_zero(va_arg(args, unsigned int), width);
	if (type == 'x')
		char_count += ft_treat_hexa_zero(va_arg(args, unsigned int), 1, width);
	if (type == 'X')
		char_count += ft_treat_hexa_zero(va_arg(args, unsigned int), 0, width);
	return (char_count);
}
