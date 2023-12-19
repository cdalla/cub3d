/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdalla-s <cdalla-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:56:31 by cdalla-s          #+#    #+#             */
/*   Updated: 2023/12/15 13:01:08 by cdalla-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_count(char const *s, char c);

static	char	**ft_split_words(char **split, char *str, char c);

static	void	free_split(char **split, int index);

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (!s)
		return (0);
	split = (char **)malloc((ft_count(s, c) + 1) * sizeof(char *));
	if (split == 0)
		return (0);
	ft_split_words(split, (char *) s, c);
	return (split);
}

static	char	**ft_split_words(char **split, char *str, char c)
{
	int	index;
	int	w_len;

	index = 0;
	while (*str)
	{
		w_len = 0;
		while (*str == c)
			str++;
		while (*(str + w_len) != c && *(str + w_len) != '\0')
			w_len++;
		if (w_len > 0)
		{
			split[index] = ft_substr(str, 0, w_len);
			if (split[index] == 0)
			{
				free_split(split, index);
				return (0);
			}
			index++;
		}
		str = str + w_len;
	}
	split[index] = 0;
	return (split);
}

static	int	ft_count(char const *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str != c && (*(str + 1) == c || *(str + 1) == '\0'))
			count++;
		str++;
	}
	return (count);
}

static	void	free_split(char **split, int index)
{
	while (index >= 0)
	{
		index--;
		free(split[index]);
	}
}
