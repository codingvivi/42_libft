/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test/test_ft_isalpha.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrain <lrain@students.42berlin.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:29:15 by lrain             #+#    #+#             */
/*   Updated: 2025/11/26 17:37:31 by lrain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../unity/src/unity.h"
#include <assert.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

void	setUp(void)
{
	// set stuff up here
}

void	tearDown(void)
{
	// clean stuff up here
}

void	check_against_ctype(unsigned char c)
{
	const bool	libc_result = isalpha(c);
	const bool	ft_result = ft_isalpha(c);

	assert(libc_result == ft_result);
	printf("✓ check ok! taget: %d, actual: %d", libc_result, ft_result);
}

void	test_all_asciis(void)
{
	char	current_char;

	current_char = 0;
	while (current_char <= 127)
		check_against_ctype(current_char);
}
