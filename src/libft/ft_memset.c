/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/16 13:56:17 by cdalla-s      #+#    #+#                 */
/*   Updated: 2022/12/16 13:56:17 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	index;

	index = 0;
	while (index < len)
	{
		((unsigned char *) b)[index] = c;
		index++;
	}
	return (b);
}
