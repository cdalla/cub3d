/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/16 13:56:25 by cdalla-s      #+#    #+#                 */
/*   Updated: 2022/12/16 13:56:26 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	i;

	i = n;
	if (i < 0)
	{
		write(fd, "-", 1);
		i = i * -1;
	}
	if (i > 9)
	{
		ft_putnbr_fd(i / 10, fd);
		i = i % 10 + 48;
		write(fd, &i, 1);
	}
	else
	{
		i = i + 48;
		write(fd, &i, 1);
	}
}
