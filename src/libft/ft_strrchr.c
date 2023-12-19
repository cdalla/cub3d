/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/16 13:57:08 by cdalla-s      #+#    #+#                 */
/*   Updated: 2022/12/16 13:57:09 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int		index;
	char	*ptr;

	index = 0;
	ptr = 0;
	while (s[index])
	{
		if (s[index] == (char)c)
			ptr = (char *)s + index;
		index++;
	}
	if (s[index] == (char)c)
		return ((char *)s + index);
	return (ptr);
}
