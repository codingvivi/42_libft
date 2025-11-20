/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrain <lrain@students.42berlin.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 01:23:38 by lrain             #+#    #+#             */
/*   Updated: 2025/11/19 22:18:02 by lrain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
01000001 A
00100000 32 --> power of 2, 1 followed by 0s
-------
01100001 a

adds 32 if number has 0 in
adds 32 if 0-31 or 65-97
*/

int	isalpha(int c)
{
	unsigned int	temp;

	temp = (unsigned)c; /* for sane bit representation/the pattern to work */
	temp |= 32;         /* unifies blocks of 64 */
	temp -= 'a';        /* normalizes, sets the scale to 'a' */
	return (temp < 26); /* only check for one range and only one side. wow... */
}
