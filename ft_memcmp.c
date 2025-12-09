/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrain <lrain@students.42berlin.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:00:40 by lrain             #+#    #+#             */
/*   Updated: 2025/12/05 14:12:17 by lrain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	memcmp(const void *lhs, const void *rhs, size_t count)
{
	const unsigned char	*c_lhs;
	const unsigned char	*c_rhs;

	c_lhs = lhs;
	c_rhs = rhs;
	while (count-- && *c_lhs-- == *c_rhs--)
		;
	return (*c_lhs - *c_rhs);
}
