/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/16 13:54:56 by cdalla-s      #+#    #+#                 */
/*   Updated: 2022/12/23 11:41:09 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	index;
	int	num;
	int	sign;

	index = 0;
	num = 0;
	sign = 1;
	while (str[index] == '\t' || str[index] == '\v' || str[index] == '\f'
		|| str[index] == '\r' || str[index] == '\n' || str[index] == ' ')
		index++;
	if (str[index] == '-')
	{
		sign = -sign;
		index++;
	}
	else if (str[index] == '+')
		index++;
	while (str[index] >= '0' && str[index] <= '9')
	{
		num = num * 10 + (str[index] - 48);
		index++;
	}
	return (num * sign);
}
