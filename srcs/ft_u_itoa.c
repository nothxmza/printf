/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <hterras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 15:40:58 by jbarette          #+#    #+#             */
/*   Updated: 2021/03/18 17:22:47 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long int	ft_neg(long int nbr)
{
	if (nbr < 0)
	{
		return (-nbr);
	}
	return (nbr);
}

static int		ft_len(long int nbr)
{
	int		len;

	if (nbr <= 0)
		len = 1;
	else
		len = 0;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char			*ft_u_itoa(unsigned int n)
{
	int		len;
	int		sign;
	char	*c;

	if (n < 0)
		sign = -1;
	else
		sign = 1;
	len = ft_len(n);
	c = (char *)malloc(sizeof(char) * len + 1);
	if (c == NULL)
		return (0);
	c[len] = '\0';
	len--;
	while (len >= 0)
	{
		c[len] = '0' + ft_neg(n % 10);
		n = ft_neg(n / 10);
		len--;
	}
	if (sign == -1)
		c[0] = '-';
	return (c);
}
