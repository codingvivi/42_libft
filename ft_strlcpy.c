/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrain <lrain@students.42berlin.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 17:46:40 by lrain             #+#    #+#             */
/*   Updated: 2025/12/18 22:07:18 by lrain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t count)
{
	char	*dst_start;

	dst_start = dst;
	if (count > 0)
	{
		count--;
		while (count && *dst && *src)
		{
			*dst = *src;
			count--;
			src++;
			dst++;
		}
		*dst = '\0';
	}
	/* distance copied + remaining length of src */
	/* doesn't have to traverse src twice,or have it be at original position */
	return ((dst - dst_start) + ft_strlen(src));
}
