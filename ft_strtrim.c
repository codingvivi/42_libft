/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrain <lrain@students.42berlin.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 20:28:15 by lrain             #+#    #+#             */
/*   Updated: 2025/12/21 12:46:02 by lrain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>
#include <stdlib.h>

static bool	is_in_set(const char c, const char *set)
{
	while (*set++)
		if (*set == c)
			return (true);
	return (false);
}
/* len_tail-- since it stops on last keep char*/
char	*ft_strtrim(char const *s1, char const *set)
{
	char			*str;
	char			*ret;
	unsigned int	end_head;
	size_t			len_tail;
	size_t			len_keep;

	end_head = 0;
	len_keep = 0;
	len_tail = 0;
	str = (void *)s1;
	while (is_in_set(*str++, set))
		end_head++;
	while (*str++)
		len_keep++;
	while (is_in_set(*str--, set))
		len_tail++;
	len_tail--;
	len_keep -= len_tail;
	ret = malloc((len_keep + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	ret = ft_substr(s1, end_head, len_keep);
	return (ret);
}
