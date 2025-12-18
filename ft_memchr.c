/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrain <lrain@students.42berlin.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:34:13 by lrain             #+#    #+#             */
/*   Updated: 2025/12/17 17:50:54 by lrain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t count)
{
	const unsigned char	*s = src;

	c = (unsigned char)c;
	while (count && (*s != c))
	{
		s++;
		count--;
	}
	if (count)
		return ((void *)s);
	else
		return (0);
}
