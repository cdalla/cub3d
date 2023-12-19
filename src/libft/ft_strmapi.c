/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/16 13:57:00 by cdalla-s      #+#    #+#                 */
/*   Updated: 2022/12/16 13:57:00 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int					len;
	unsigned int		index;
	char				*str;

	if (!s)
		return (0);
	index = 0;
	len = ft_strlen((char *)s);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == 0)
		return (0);
	while (s[index])
	{
		str[index] = f(index, s[index]);
		index++;
	}
	str[index] = '\0';
	return (str);
}
