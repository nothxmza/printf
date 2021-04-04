/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 16:21:07 by hterras           #+#    #+#             */
/*   Updated: 2021/01/23 10:36:23 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dest2;
	char	*src2;
	size_t	i;

	dest2 = dst;
	src2 = (char *)src;
	i = 0;
	if (dest2 == src2)
		return (dest2);
	while (i < n)
	{
		dest2[i] = src2[i];
		i++;
	}
	return (dst);
}
