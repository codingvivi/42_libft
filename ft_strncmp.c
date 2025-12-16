/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrain <lrain@students.42berlin.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 21:39:07 by lrain             #+#    #+#             */
/*   Updated: 2025/12/15 15:42:45 by lrain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

int	ft_strncmp(const char *ss1, const char *ss2, size_t n)
{
	const unsigned char	*s1 = (void *)ss1;
	const unsigned char	*s2 = (void *)ss2;

	if (!n--)
		return (0);
	while (n && *s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
		n--;
	}
	return (*s1 - *s2);
}
