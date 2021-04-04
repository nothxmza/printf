/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 16:24:08 by hterras           #+#    #+#             */
/*   Updated: 2021/01/19 16:28:10 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t i;

	if (!dst || !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*(char*)(dst + i) = *(char*)(src + i);
		if (*(char*)(src + i) == (char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
