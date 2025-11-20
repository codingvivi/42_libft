/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrain <lrain@students.42berlin.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:44:21 by lrain             #+#    #+#             */
/*   Updated: 2025/11/20 03:48:04 by lrain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>

int	ft_isascii(int c)
{
	c &= ~127;     /* makes c be anything iff its larger */
	return (!(c)); /* if non masked, outside range bits let thru anything */
}
/*
...0000 0111 1111 all 1s for bits in range
|1's complement
v
...1111 1000 0000 all bits outside range

1010 0111 0101
1111 1000 0000
--------------
1010 0000 0000 lets tru larger than range

0000 0110 1100 outside of range shouldnt exit
1111 1000 0000 range already 0
 --------------
0000 0000 0000 everything will be 0
*/
