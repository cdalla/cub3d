/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdalla-s <cdalla-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 11:05:38 by cdalla-s          #+#    #+#             */
/*   Updated: 2023/12/22 13:56:15 by cdalla-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <limits.h>

char	*free_all(char **buff, int fd, char *new_line);
int		ft_readjoin(char **buff, int fd);
void	ft_newline(char **buff, int fd, char **new_line);
int		ft_resizebuff(char **buff, int fd, size_t nl_len);

char	*get_next_line(int fd)
{
	static char		*files[OPEN_MAX];
	char			read_buff[50 + 1];
	char			*new_line;
	int				n_bytes;

	new_line = 0;
	if (fd < 0 || fd >= OPEN_MAX)
		return (NULL);
	if (!files[fd])
	{
		n_bytes = read(fd, read_buff, 50);
		if (n_bytes == 0)
			return (free_all(files, fd, NULL));
		if (n_bytes == -1)
			return (free_all(files, fd, NULL));
		read_buff[n_bytes] = '\0';
		files[fd] = ft_strdup(read_buff);
		if (!files[fd])
			return (NULL);
	}
	ft_newline(files, fd, &new_line);
	if (!new_line)
		return (NULL);
	return (new_line);
}

int	ft_readjoin(char **buff, int fd)
{
	char	read_buff[50 + 1];
	char	*tmp;
	int		n_bytes;
	size_t	len;

	n_bytes = read(fd, read_buff, 50);
	if (n_bytes == 0)
		return (0);
	else if (n_bytes == -1)
		return (-1);
	read_buff[n_bytes] = '\0';
	len = ft_strlen(read_buff) + ft_strlen(buff[fd]) + 1;
	tmp = ft_strdup(buff[fd]);
	if (!tmp)
		return (-1);
	free(buff[fd]);
	buff[fd] = malloc(len * sizeof(char));
	if (!buff[fd])
		return (-1);
	ft_strlcpy(buff[fd], tmp, len);
	ft_strlcpy(&buff[fd][ft_strlen(tmp)], read_buff, len);
	free(tmp);
	return (1);
}

void	ft_newline(char **b, int fd, char **new_line)
{
	int	check;

	while (!*new_line)
	{
		if (ft_strchr_index(b[fd], '\n') != -1)
		{
			*new_line = ft_substr(b[fd], 0, ft_strchr_index(b[fd], '\n'));
			if (!*new_line)
				*new_line = free_all(b, fd, *new_line);
			if (ft_resizebuff(b, fd, ft_strlen(*new_line) + 1) == 0)
				*new_line = free_all(b, fd, *new_line);
		}
		else
		{
			check = ft_readjoin(b, fd);
			if (check == 0)
			{
				*new_line = ft_strdup(b[fd]);
				free(b[fd]);
				b[fd] = 0;
			}
			else if (check == -1)
				*new_line = free_all(b, fd, *new_line);
		}
	}
}

int	ft_resizebuff(char **buff, int fd, size_t nl_len)
{
	char	*tmp;

	tmp = ft_substr(buff[fd], nl_len, ft_strlen(buff[fd]) - nl_len);
	if (!tmp)
		return (0);
	free(buff[fd]);
	buff[fd] = ft_strdup(tmp);
	free(tmp);
	if (!buff[fd])
		return (0);
	if (ft_strlen(buff[fd]) == 0)
	{
		free (buff[fd]);
		buff[fd] = 0;
	}
	return (1);
}

char	*free_all(char **buff, int fd, char *new_line)
{
	if (buff[fd])
		free(buff[fd]);
	if (new_line)
		free(new_line);
	return (NULL);
}
