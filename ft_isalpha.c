/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrain <lrain@students.42berlin.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 01:23:38 by lrain             #+#    #+#             */
/*   Updated: 2025/11/24 20:39:43 by lrain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
01000001 A
00100000 32 --> power of 2, 1 followed by 0s
-------
01100001 a

adds 32 if number has 0 in
adds 32 if 0-31 or 65-97
*/

int	ft_isalpha(int c)
{
	unsigned int	temp;

	temp = (unsigned)c; /* for sane bit representation/the pattern to work */
	temp |= 32;         /* unifies blocks of 64 */
	temp -= 'a';        /* normalizes, sets the scale to 'a' */
	return (temp < 26); /* only check for one range and only one side. wow... */
}
