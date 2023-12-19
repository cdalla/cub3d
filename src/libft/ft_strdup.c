/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/16 13:56:42 by cdalla-s      #+#    #+#                 */
/*   Updated: 2022/12/16 13:56:43 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	len;
	size_t	index;

	len = 0;
	index = 0;
	while (s1[len])
		len++;
	dup = (char *)malloc((len + 1) * sizeof(char));
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
