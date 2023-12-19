/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/18 14:56:25 by cdalla-s      #+#    #+#                 */
/*   Updated: 2023/01/03 15:57:14 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - s2[i]);
}
