/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color_value.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/19 15:58:38 by cdalla-s      #+#    #+#                 */
/*   Updated: 2024/02/08 20:27:46 by kaltevog      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	color_value(char *s, int a[3])
{
	int		len;
	int		i;
	char	*value;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s && is_space(*s))
			s++;
		while (s[len] && ft_isdigit(s[len]))
			len++;
		value = ft_substr(s, 0, len);
		if (!value)
			return (print_err_msg("parser", "malloc error"), 1);
		a[i] = ft_atoi(value);
		s = s + len;
		while (*s && *s != ',')
			s++;
		i++;
		if (*s && *s == ',')
			s++;
		free(value);
	}
	return (0);
}

int	string_check(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
			count++;
		if (!ft_isdigit(str[i]) && str[i] != ',' && !is_space(str[i]))
			return (print_err_msg("parser", "color value not valid"), 1);
		i++;
	}
	if (count != 2)
		return (print_err_msg("parser", "color value not valid"), 1);
	return (0);
}

int	floor_id(char **file, int i, int j, t_data *game)
{
	while (file[i])
	{
		if (ft_strlen(file[i]))
		{
			while (is_space(file[i][j]))
				j++;
			if (file[i][j])
			{
				if (string_check(&file[i][j])
					|| color_value(&file[i][j], game->f))
					return (0);
				return (++i);
			}
		}
		i++;
		j = 0;
	}
	return (i);
}

int	ceili_id(char **file, int i, int j, t_data *game)
{
	while (file[i])
	{
		if (ft_strlen(file[i]))
		{
			while (is_space(file[i][j]))
				j++;
			if (file[i][j])
			{
				if (string_check(&file[i][j])
					|| color_value(&file[i][j], game->c))
					return (0);
				return (++i);
			}
		}
		i++;
		j = 0;
	}
	return (i);
}
