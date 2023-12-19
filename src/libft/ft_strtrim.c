/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdalla-s <cdalla-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:57:11 by cdalla-s          #+#    #+#             */
/*   Updated: 2023/12/15 12:58:38 by cdalla-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_checkset(const char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (0);
		set++;
	}
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		start;
	int		end;

	if (!s1 || !set)
		return (0);
	start = 0;
	end = ft_strlen((char *)s1);
	while (ft_checkset(s1[start], set) == 0 && s1[start])
		start++;
	while (ft_checkset(s1[end - 1], set) == 0 && s1[start])
		end--;
	trim = ft_substr(s1, start, end - start);
	if (trim == 0)
		return (0);
	return (trim);
}
