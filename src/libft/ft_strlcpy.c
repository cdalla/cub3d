/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/16 13:56:54 by cdalla-s      #+#    #+#                 */
/*   Updated: 2022/12/16 13:56:55 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
