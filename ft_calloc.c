/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrain <lrain@students.42berlin.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 18:12:06 by lrain             #+#    #+#             */
/*   Updated: 2025/12/25 13:55:06 by lrain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>
#include <stdlib.h>
#include <string.h>

/*
if count * size > SIZE_MAX
SIZE_MAX = max size_t, so -1 underflows to it
divide by size to prevent multiplication from overflowing
*/
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ret;

	if (!nmemb || !size)
		return (malloc(sizeof(char)));
	if (size && nmemb > (size_t)-1 / size)
	{
		errno = ENOMEM;
		return (NULL);
	}
	size *= nmemb;
	ret = malloc(nmemb * size);
	if (!ret)
		return (NULL);
	return (memset(ret, 0, size));
}
