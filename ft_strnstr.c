/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrain <lrain@students.42berlin.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 21:37:34 by lrain             #+#    #+#             */
/*   Updated: 2025/12/18 21:53:15 by lrain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>

bool	is_match(const char *s1, const char *s2);

char	*ft_strstr(const char *haystack, const char *needle, size_t count)
{
	if (*needle == '\0')
		return ((char *)haystack);
	else
	{
		while (*haystack != '\0' && count)
		{
			if (is_match(haystack, needle) == true)
				return ((char *)haystack);
			haystack++;
			count--;
		}
		return (NULL);
	}
}

bool	is_match(const char *str, const char *to_find)
{
	while (*str != '\0' && *to_find != '\0' && *str == *to_find)
	{
		str++;
		to_find++;
	}
	if (*to_find == '\0')
		return (true);
	else
		return (false);
}
