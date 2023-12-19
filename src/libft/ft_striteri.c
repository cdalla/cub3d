/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striteri.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/16 13:56:45 by cdalla-s      #+#    #+#                 */
/*   Updated: 2022/12/16 13:56:46 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	iter;

	iter = 0;
	if (s)
	{
		while (s[iter])
		{
			f(iter, &(s[iter]));
			iter++;
		}
	}
}
