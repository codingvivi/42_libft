/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrain <lrain@students.42berlin.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:09:11 by lrain             #+#    #+#             */
/*   Updated: 2025/12/17 16:11:12 by lrain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	const unsigned char	*s = src;
	const uintptr_t		overlap_range = -2 * count;
	uintptr_t			distance;
	unsigned char		*d;

	/* underflow forbidden range to max number */
	d = dest;
	/* subtract pointer adresses as numbers  */
	distance = (uintptr_t)s - (uintptr_t)d;
	/* if same */
	if (d == s)
		return (d);
	/* if non overlap use (theoretically) faster memcpy */
	if (distance - count <= overlap_range)
		return (ft_memcpy(d, s, count));
	/* if dest to the left, copy from right to left and vice versa*/
	if (d < s)
		while (count--)
			*d++ = *s++;
	else
		while (count--)
			d[count] = s[count];
	return (dest);
}
