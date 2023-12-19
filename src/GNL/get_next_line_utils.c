/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdalla-s <cdalla-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 11:06:52 by cdalla-s          #+#    #+#             */
/*   Updated: 2023/12/15 16:06:06 by cdalla-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;

	if (!s)
		return (0);
	s_len = ft_strlen((char *)s);
	if (start >= s_len)
	{
		sub = ft_strdup("");
		return (sub);
	}
	if (len > s_len - start)
		sub = (char *)malloc((s_len - start + 1) * sizeof(char));
	else
		sub = (char *)malloc((len + 1) * sizeof(char));
	if (sub == 0)
		return (0);
	ft_strlcpy(sub, &(s[start]), len + 1);
	return (sub);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	index;

	index = 0;
	while (index < dstsize - 1 && src[index] && dstsize > 0)
	{
		dst[index] = src[index];
		index++;
	}
	if (dstsize > 0)
		dst[index] = '\0';
	return ((size_t)ft_strlen((char *)src));
}

// size_t	ft_strlen(const char *s)
// {
// 	size_t	index;

// 	index = 0;
// 	while (s[index])
// 		index++;
// 	return (index);
// }

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	index;

	index = 0;
	dup = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (dup == 0)
		return (0);
	while (s1[index])
	{
		dup[index] = s1[index];
		index++;
	}
	dup[index] = '\0';
	return (dup);
}

int	ft_strchr_index(const char *s, int c)
{
	int		index;

	index = 0;
	while (*(s + index))
	{
		if (s[index] == (char)c)
			return (index);
		index++;
	}
	if (s[index] == (char)c && (char)c == '\0')
		return (index);
	return (-1);
}
