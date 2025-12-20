/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrain <lrain@students.42berlin.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 11:51:59 by lrain             #+#    #+#             */
/*   Updated: 2025/12/20 12:48:29 by lrain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	const size_t	s_len = ft_strlen(s);
	char			*ret;

	if (s_len < len)
		len -= (len - s_len);
	ret = malloc(len * sizeof(char));
	if (!ret || start > (unsigned int)len)
		return (NULL);
	s += start;
	return ((char *)ft_memcpy(ret, s, len));
}
