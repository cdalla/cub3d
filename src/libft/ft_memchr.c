/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/16 13:56:04 by cdalla-s      #+#    #+#                 */
/*   Updated: 2022/12/16 13:56:04 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	index;

	index = 0;
	while (index < n)
	{
		if (((unsigned char *)s)[index] == (unsigned char)c)
			return ((unsigned char *)s + index);
		index++;
	}
	return (0);
}
