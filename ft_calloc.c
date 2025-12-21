/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrain <lrain@students.42berlin.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 18:12:06 by lrain             #+#    #+#             */
/*   Updated: 2025/12/20 15:05:09 by lrain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/*
if count * size > SIZE_MAX
SIZE_MAX = max size_t, so -1 underflows to it
divide by size to prevent multiplication from overflowing
*/
void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;

	if (size && count > (size_t)-1 / size)
	{
		errno = ENOMEM;
		return (NULL);
	}
	size *= count;
	ret = malloc(count * size);
	if (!ret)
		return (NULL);
	return (memset(ret, 0, size));
}
