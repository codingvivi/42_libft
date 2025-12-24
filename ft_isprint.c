/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrain <lrain@students.42berlin.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:31:10 by lrain             #+#    #+#             */
/*   Updated: 2025/12/24 18:33:08 by lrain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* will cause underflow during normalization */
int	ft_isprint(int c)
{
	const unsigned int	range = '~' - ' ';
	unsigned int		temp;

	temp = (unsigned)c;
	temp -= ' ';
	return (temp <= range);
}
