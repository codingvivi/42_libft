/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrain <lrain@students.42berlin.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 13:05:20 by lrain             #+#    #+#             */
/*   Updated: 2025/12/22 12:09:06 by lrain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static unsigned int	occurences(const char *s, char c);
static void			free_arr(char **arr);
static char			**str_to_arr(const char *str, char delim, size_t n_words,
						char **arr);

char	**ft_split(char const *s, char c)
{
	char			**strings;
	unsigned int	n_words;

	if (!s)
		return (NULL);
	n_words = occurences(s, c);
	strings = malloc(sizeof(char *) * (n_words + 1));
	if (!strings)
		return (NULL);
	strings = str_to_arr(s, c, n_words, strings);
	return (strings);
}

static unsigned int	occurences(const char *s, char c)
{
	unsigned int	n;

	n = 0;
	while (*s)
	{
		if (*s == c)
			n++;
		s++;
	}
	return (n);
}

static char	**str_to_arr(const char *str, char delim, size_t n_words,
		char **arr)
{
	const char	*curr = str;
	const char	*next;
	size_t		i;
	size_t		idx;
	size_t		len;

	i = 0;
	idx = 0;
	while (i++ < n_words - 1)
	{
		next = ft_strchr(curr, delim);
		len = next - curr;
		arr[i] = ft_substr(str, idx, len);
		if (!arr[i])
		{
			free_arr(arr);
			return (NULL);
		}
		curr = next;
		idx += len + 1;
	}
	arr[i++] = ft_substr(str, idx, ft_strlen(curr));
	arr[i] = NULL;
	return (arr);
}

static void	free_arr(char **arr)
{
	unsigned int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
