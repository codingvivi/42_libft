/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrain <lrain@students.42berlin.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 13:17:38 by lrain             #+#    #+#             */
/*   Updated: 2025/12/05 13:52:21 by lrain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*memcpy(void *dest, const void *src, size_t count)
{
	unsigned char		*c_dest;
	const unsigned char	*c_src = src;

	c_dest = dest;
	while (--count)
		*c_dest++ = *c_src++;
	return (dest);
}
