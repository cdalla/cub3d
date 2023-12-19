/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/16 13:56:39 by cdalla-s      #+#    #+#                 */
/*   Updated: 2023/01/03 15:57:28 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int		index;

	index = 0;
	while (*(s + index))
	{
		if (s[index] == (char)c)
			return ((char *)s + index);
		index++;
	}
	if (s[index] == (char)c && (char)c == '\0')
		return ((char *)s + index);
	return (0);
}
