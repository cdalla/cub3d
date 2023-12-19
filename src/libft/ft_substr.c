/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/16 13:57:17 by cdalla-s      #+#    #+#                 */
/*   Updated: 2022/12/16 13:57:18 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;

	if (!s)
		return (0);
	s_len = ft_strlen((char *)s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		sub = (char *)malloc((s_len - start + 1) * sizeof(char));
	else
		sub = (char *)malloc((len + 1) * sizeof(char));
	if (sub == 0)
		return (0);
	ft_strlcpy(sub, &(s[start]), len + 1);
	return (sub);
}
