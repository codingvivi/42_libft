/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test/helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrain <lrain@students.42berlin.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 20:09:56 by lrain             #+#    #+#             */
/*   Updated: 2025/12/04 18:16:12 by lrain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"
#include <stddef.h>
#include <string.h>

char	*get_all_asciis(char *str_ptr)
{
	char	buffer[128];

	for (unsigned int i = 0; i < 128; i++)
		buffer[i] = i;
	str_ptr = buffer;
	return (str_ptr);
}
