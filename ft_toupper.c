/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrain <lrain@students.42berlin.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 22:18:27 by lrain             #+#    #+#             */
/*   Updated: 2025/12/18 22:18:35 by lrain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_islower(int c)
{
	return ((unsigned)c - 'a' < 26);
}

int	ft_toupper(int c)
{
	if (ft_islower(c))
		return (c | 32);
	return (c);
}
