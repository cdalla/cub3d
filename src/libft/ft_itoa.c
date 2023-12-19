/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdalla-s <cdalla-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:55:29 by cdalla-s          #+#    #+#             */
/*   Updated: 2023/12/15 13:01:44 by cdalla-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_size(int n);

char	*ft_itoa(int n)
{
	char	*itoa;
	int		index;
	int		size;
	int		sign;

	sign = 1;
	index = 0;
	size = ft_size(n);
	itoa = (char *)malloc(size * sizeof(char) + 1);
	if (itoa == 0)
		return (0);
	if (n < 0)
	{
		itoa[index] = '-';
		index++;
		sign = -1;
	}
	itoa[size] = '\0';
	while (size > index)
	{
		size--;
		itoa[size] = n % 10 * sign + 48;
		n = n / 10;
	}
	return (itoa);
}

static	int	ft_size(int n)
{
	int	size;

	size = 0;
	if (n < 0)
		size++;
	if (n == 0)
		size++;
	while (n != 0)
	{
		size++;
		n = n / 10;
	}
	return (size);
}
