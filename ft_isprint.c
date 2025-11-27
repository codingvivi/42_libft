/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrain <lrain@students.42berlin.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:31:10 by lrain             #+#    #+#             */
/*   Updated: 2025/11/23 21:05:28 by lrain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	isprint(int c)
{
	const unsigned int	range = '~' - ' ';
	unsigned int		temp;

	temp = (unsigned)c; /* will cause underflow during normalization */
	temp -= ' ';
	return (temp <= range);
}
