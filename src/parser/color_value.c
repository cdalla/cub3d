/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdalla-s <cdalla-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:58:38 by cdalla-s          #+#    #+#             */
/*   Updated: 2023/12/22 16:15:23 by cdalla-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	color_value(char *s, int a[3])
{
	int		len;
	int		i;
	char	*value;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s && is_space(*s)) //skip initial spaces
			s++;
		while (s[len] && ft_isdigit(s[len])) //count number of digits
			len++;
		value = ft_substr(s, 0, len);
		if (!value)
			return (print_err_msg("parser", "malloc error"), 1); //malloc error
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
		if (ft_strlen(file[i])) //skip empty lines
		{
			while (is_space(file[i][j])) //skip spaces
				j++;
			if (file[i][j]) //if something in string
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
	return (i); //if arrives here it is the last line so file[i] == 0
}

int	ceili_id(char **file, int i, int j, t_data *game)
{
	while (file[i])
	{
		if (ft_strlen(file[i])) //skip empty lines
		{
			while (is_space(file[i][j])) //skip spaces
				j++;
			if (file[i][j]) //if something in string
			{
				if (string_check(&file[i][j])
					|| color_value(&file[i][j], game->c))
					return (0); //0 index is error
				return (++i);
			}
		}
		i++;
		j = 0;
	}
	return (i); //if arrives here it is the last line so file[i] == 0
}
