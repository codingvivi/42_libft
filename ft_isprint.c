/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ~/Development/Projects/2025/2025-11-17-42_lib      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrain <lrain@students.42berlin.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:31:10 by lrain             #+#    #+#             */
/*   Updated: 2025/11/20 17:44:16 by lrain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	isprint(int c)
{
	const unsigned int	range = '~' - ' ';
	unsigned int		temp;

	temp = (unsigned)c; /* will cause underflow during normalization */
	temp -= ' ';
	return (temp <= range);
}
