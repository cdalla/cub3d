/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/16 13:56:48 by cdalla-s      #+#    #+#                 */
/*   Updated: 2022/12/16 13:56:49 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	len;

	if (!s1 || !s2)
		return (0);
	len = (ft_strlen((char *)s1)) + (ft_strlen((char *)s2)) + 1;
	join = (char *)malloc(len * sizeof(char));
	if (join == 0)
		return (0);
	ft_strlcpy(&(join[ft_strlcpy(join, s1, len)]), s2, len);
	return (join);
}
