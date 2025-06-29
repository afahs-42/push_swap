/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 17:17:53 by afahs             #+#    #+#             */
/*   Updated: 2025/06/29 06:30:13 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	sep(char c, char s)
{
	if (c == s || c == '\0')
		return (1);
	return (0);
}

static void	write_word(char *dest, char const *from, char c)
{
	int	i;

	i = 0;
	while (!sep(from[i], c))
	{
		dest[i] = from[i];
		i++;
	}
	dest[i] = '\0';
}

static void	*create_word(char **split, int word, int j)
{
	split[word] = (char *)malloc(sizeof(char) * (j + 1));
	if (!split[word])
	{
		while (word > 0)
			free(split[--word]);
		return (NULL);
	}
	return ((void *)1);
}

static void	*write_split(char **split, char const *str, char c)
{
	int		i;
	int		j;
	int		word;

	word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			j = 0;
			while (!sep(str[i + j], c))
				j++;
			if (!create_word(split, word, j))
				return (NULL);
			write_word(split[word], str + i, c);
			i += j;
			word++;
		}
	}
	return ((void *)1);
}

char	**ft_split(char **s, char c, int *nb)
{
	char	**res;
	int		words;
	int		i;

	if (!s[1])
		return (NULL);
	i = 0;
	words = 1;
	while (s[1][i])
	{
		if (!sep(s[1][i], c) && sep(s[1][i + 1], c))
			words++;
		i++;
	}
	res = (char **)malloc(sizeof(char *) * (words + 2));
	if (!res)
		return (NULL);
	res[0] = s[0];
	res[words] = 0;
	*nb = words;
	if (!write_split(res, s[1], c))
		return (NULL);
	return (res);
}
