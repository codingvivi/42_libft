/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrain <lrain@students.42berlin.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 13:05:20 by lrain             #+#    #+#             */
/*   Updated: 2025/12/21 17:27:50 by lrain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

static unsigned int	occurences(const char *s, char c);
static void			free_arr(char **arr);
static size_t		write_arr(const char *str, char delim, char **arr,
						size_t i);
static char			**str_to_arr(const char *str, char delim, size_t n_str);

char	**ft_split(char const *s, char c)
{
	char			**strings;
	unsigned int	n_str;

	n_str = occurences(s, c) + 1;
	strings = str_to_arr(s, c, n_str);
	return (strings);
}

static unsigned int	occurences(const char *s, char c)
{
	unsigned int	n;

	n = 0;
	while (*s++)
		if (*s == c)
			n++;
	return (n);
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

static size_t	write_arr(const char *str, char delim, char **arr, size_t i)
{
	size_t	len;

	len = ft_strchr(str, delim) - str;
	arr[i] = malloc((len + 1) * sizeof(char));
	if (!arr[i])
		free_arr(arr);
	ft_memcpy(arr[i], str, len);
	return (len);
}

static char	**str_to_arr(const char *str, char delim, size_t n_str)
{
	char	**arr;
	size_t	i;

	arr = malloc(sizeof(char *) * (n_str + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (i++ < n_str - 1)
		str += write_arr(str, delim, arr, n_str);
	write_arr(str, '\0', arr, i++);
	arr[i] = NULL;
	return (arr);
}

/*
{
	const char		*delim_pos = ft_strchr(s, c);
	const ptrdiff_t	len1 = delim_pos - s;
	const size_t	len2 = ft_strlen(delim_pos + 1);
	char			**ret;

	ret = malloc(sizeof(char *) * 3);
	if (len1 < 0)
		return (NULL);
	if (!ret[0] || !ret[1])
		return (NULL);
	ret[2] = NULL;
	ft_substr(ret[0], 0, len1);
	ft_substr(ret[1], len1 + 1, len2);
	return (ret);
}
*/
