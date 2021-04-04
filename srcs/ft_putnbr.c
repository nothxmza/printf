/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <hterras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 15:49:02 by jbarette          #+#    #+#             */
/*   Updated: 2021/03/18 17:21:32 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnbr(int n)
{
	unsigned int	nb;
	char			*count_n;
	int				count_nbr;

	count_n = ft_itoa(n);
	count_nbr = ft_strlen(count_n);
	if (n < 0)
		n *= -1;
	nb = (unsigned int)n;
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + 48);
	free(count_n);
	return (count_nbr);
}
