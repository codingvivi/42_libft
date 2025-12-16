/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test/test_ft_memmove.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrain <lrain@students.42berlin.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:48:03 by lrain             #+#    #+#             */
/*   Updated: 2025/12/16 15:48:03 by lrain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"
#include <memory.h>

#define ASCIISLEN 128

void	setUp(void)
{
}

void	tearDown(void)
{
	// clean stuff up here
}

void	test_all_asciis(void)
{
	char	source[ASCIISLEN] = {0};
	char	target[ASCIISLEN] = {0};
	char	actual[ASCIISLEN] = {0};

	get_all_asciis(source);
	memcpy(source, target, ASCIISLEN);
	ft_memcpy(source, actual, ASCIISLEN);
	check_against_stdlib(target, actual);
}

void	test_n_limit(void)
{
	char	source[ASCIISLEN] = {0};
	char	target[ASCIISLEN] = {0};
	char	actual[ASCIISLEN] = {0};

	get_all_asciis(source);
	memcpy(source, target, ASCIISLEN - 1);
	ft_memcpy(source, actual, ASCIISLEN - 1);
	check_against_stdlib(target, actual);
}
