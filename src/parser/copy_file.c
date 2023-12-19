/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdalla-s <cdalla-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:45:00 by cdalla-s          #+#    #+#             */
/*   Updated: 2023/12/19 13:50:42 by cdalla-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	print_file(char **file)//to remove testing purpose
{
	int i= 0;
	
	while(file[i])
	{
		printf("%s\n", file[i]);
		i++;
	}
}

int file_size(char *filename)
{
	int		fd;
	int		count = 0;
	char	*s = "";
	
	fd = open(filename, O_RDONLY);
	if (fd < 1)
		return (1); //error open
	while (s)
	{
		s = get_next_line(fd); //check error in gnl
		if (s)
			count++;
		free(s);
	}
	close(fd);
	return (count);
}

int copy_file(char *filename, int count, char 	***file_copy)
{
	int		fd;
	char	*s = "";
	int		i = 0;
	
	*file_copy = (char**)malloc ((count + 1) * sizeof(char*));
	if (!*file_copy)
		return (1); //malloc error
	fd = open(filename, O_RDONLY);
	if (fd < 1)
		return (1);//errror open
	while (s && i < count)
	{
		s = get_next_line(fd);
		if (s)
		{
			(*file_copy)[i] = (char*)malloc ((ft_strlen(s) + 1) * sizeof(char));
			if (!(*file_copy)[i])
				return (1); //malloc error
			ft_strlcpy((*file_copy)[i], s, ft_strlen(s) + 1);
			free(s);
			i++;
		}
	}
	(*file_copy)[i] = 0;
	close(fd);
	return (0);
}