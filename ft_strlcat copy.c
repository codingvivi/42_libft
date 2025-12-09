/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat copy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrain <lrain@students.42berlin.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 18:26:46 by lrain             #+#    #+#             */
/*   Updated: 2025/12/09 17:21:34 by lrain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	length_dest_str;
	unsigned int	length_src_str;
	unsigned int	i;

	length_src_str = ft_strlen(src);
	i = 0;
	while (i < size && dest[i] != '\0')
		i++;
	length_dest_str = i;
	if (i < size)
	{
		while (i < size - 1 && *src != '\0')
		{
			dest[i] = *src;
			i++;
			src++;
		}
		dest[i] = '\0';
	}
	return (length_dest_str + length_src_str);
}
