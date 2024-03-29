/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   copy_file.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/19 13:45:00 by cdalla-s      #+#    #+#                 */
/*   Updated: 2024/02/12 11:43:33 by kaltevog      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	file_size(char *filename)
{
	int		fd;
	int		count;
	char	*s;

	count = 0;
	s = "";
	fd = open(filename, O_RDONLY);
	if (fd < 1)
		return (print_err_msg("parser", strerror(errno)), 1);
	while (s)
	{
		s = get_next_line(fd);
		if (s)
			count++;
		free(s);
	}
	close(fd);
	return (count);
}

int	copy_lines(int fd, int count, char ***file_copy)
{
	int		i;
	char	*s;

	i = 0;
	s = "";
	while (s && i < count)
	{
		s = get_next_line(fd);
		if (s)
		{
			(*file_copy)[i] = malloc ((ft_strlen(s) + 1) * sizeof(char));
			if (!(*file_copy)[i])
				return (print_err_msg("parser", "malloc error"), 1);
			ft_strlcpy((*file_copy)[i], s, ft_strlen(s) + 1);
			free(s);
			i++;
		}
	}
	(*file_copy)[i] = 0;
	return (0);
}

int	copy_file(char *filename, int count, char ***file_copy)
{
	int		fd;

	*file_copy = (char **)malloc ((count + 1) * sizeof(char *));
	if (!*file_copy)
		return (print_err_msg("parser", "malloc error"), 1);
	fd = open(filename, O_RDONLY);
	if (fd < 1)
		return (print_err_msg("parser", strerror(errno)), 1);
	if (copy_lines(fd, count, file_copy))
		return (1);
	close(fd);
	return (0);
}
