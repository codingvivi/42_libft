/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test/test_ft_strncmp.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrain <lrain@students.42berlin.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:57:49 by lrain             #+#    #+#             */
/*   Updated: 2025/12/15 09:47:01 by lrain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"
#include <string.h>

void	setUp(void)
{
}

void	tearDown(void)
{
}

void	test_greater(void)
{
	const char	*lhs = "the quick brown fox jumps over the lazy dog!";
	const char	*rhs = "The quick brown fox jumps over the lazy dog!";
	const int	target_ret = strncmp(lhs, rhs, 45);
	const int	actual_ret = ft_strncmp(lhs, rhs, 45);

	compare_as_bools(target_ret, actual_ret);
}

void	test_lesser(void)
{
	TEST_ASSERT_EQUAL_INT_MESSAGE(strncmp("the quick brown fox jumps over the lazy dog!",
			"The quick brown fox jumps over the lazy dog!", 44),
		ft_strncmp("the quick brown fox jumps over the lazy dog!",
			"The quick brown fox jumps over the lazy dog!", 44),
		"Divergent behavior from string.h!");
	TEST_ASSERT_EQUAL_INT_MESSAGE('T' - 't',
		ft_strncmp("The quick brown fox jumps over the lazy dog!",
			"the quick brown fox jumps over the lazy dog!", 44),
		"Not the same as hand control!");
}

void	test_equal_strings_and_input(void)
{
	char	printables[203] = WHITESPACE ALL_PRINTABLE_ASCII WHITESPACE ALL_PRINTABLE_ASCII;

	TEST_ASSERT_EQUAL_INT(0, ft_strncmp(LOWERCASE_LETTERS, LOWERCASE_LETTERS,
			26));
	TEST_ASSERT_EQUAL_INT(0, ft_strncmp(UPPERCASE_LETTERS, UPPERCASE_LETTERS,
			26));
	TEST_ASSERT_EQUAL_INT(0, ft_strncmp(DIGITS, DIGITS, 10));
	TEST_ASSERT_EQUAL_INT(0, ft_strncmp(SPECIALS, SPECIALS, 35));
	TEST_ASSERT_EQUAL_INT(0, ft_strncmp(printables, printables, 202));
}
void	test_empty_string(void)
{
	TEST_ASSERT_EQUAL_INT(0, ft_strncmp("", "", 1));
}

void	test_n_0(void)
{
	TEST_ASSERT_EQUAL_INT(0, ft_strncmp("", "", 0));
}
void	test_n_exit(void)
{
	TEST_ASSERT_EQUAL_INT(strncmp("123", "1234", 3), ft_strncmp("123", "1234",
			3));
	TEST_ASSERT_EQUAL_INT(0, ft_strncmp("123", "1234", 3));
	TEST_ASSERT_NOT_EQUAL_INT(0, ft_strncmp("123", "1234", 4));
}
