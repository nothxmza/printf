/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <hterras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 15:42:48 by jbarette          #+#    #+#             */
/*   Updated: 2021/03/18 17:21:00 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convert_base(unsigned long long nbr, int base)
{
	int					i;
	unsigned long long	n;
	char				*str;

	i = 0;
	n = nbr;
	if (nbr == 0)
		return (ft_strdup("0"));
	i = convert_base1(nbr, base);
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (0);
	str[i] = '\0';
	while (n != 0)
	{
		if ((n % base) < 10)
			str[i - 1] = (n % base) + 48;
		else
			str[i - 1] = (n % base) + 55;
		n /= base;
		i--;
	}
	return (str);
}

int		convert_base1(unsigned long long nbr, int base)
{
	int		i;

	i = 0;
	while (nbr != 0)
	{
		nbr /= base;
		i++;
	}
	return (i);
}
