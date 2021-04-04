/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 12:44:20 by hterras           #+#    #+#             */
/*   Updated: 2021/01/23 11:08:23 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t i;

	i = -1;
	while (++i < n && src[i])
		dest[i] = src[i];
	while (i < n)
		dest[i++] = '\0';
	return (dest);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	len = ft_strlen(s1 + i);
	if (len)
		while (s1[len + i - 1] != '\0' &&
				ft_strchr(set, s1[len + i - 1]) != '\0')
			len--;
	if (!(str = malloc(sizeof(char) * len + 1)))
		return (NULL);
	ft_strncpy(str, s1 + i, len);
	str[len] = '\0';
	return (str);
}
