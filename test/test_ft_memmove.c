/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test/test_ft_memmove.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrain <lrain@students.42berlin.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:48:03 by lrain             #+#    #+#             */
/*   Updated: 2025/12/17 16:15:00 by lrain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"
#include <assert.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASCIISLEN 128

static char *source;
static char *target;
static char *actual;

void setUp(void)
{
}

void tearDown(void)
{
	if (source)
		free(source);
	if (target)
		free(target);
	if (actual)
		free(actual);
	source = target = actual = NULL;
	// printf("freed memory...\n");
}

void test_all_asciis(void)
{
	// printf("Beginning...\n");
	source = calloc(ASCIISLEN + 1, sizeof(char));
	assert(source);
	target = calloc(ASCIISLEN + 1, sizeof(char));
	assert(target);
	actual = calloc(ASCIISLEN + 1, sizeof(char));
	assert(actual);

	// printf("Alloced memory...\n");
	get_all_asciis(source);
	// printf("Inited source...\n");
	memmove(source, target, ASCIISLEN);
	// printf("Ran control...\n");
	ft_memmove(source, actual, ASCIISLEN);
	// printf("Ran actual...\n");

	check_against_stdlib(target, actual);
	// printf("Ran test...\n");
}

void test_n_limit(void)
{
	source = calloc(sizeof(char), ASCIISLEN + 1);
	assert(source);
	target = calloc(sizeof(char), ASCIISLEN + 1);
	assert(target);
	actual = calloc(sizeof(char), ASCIISLEN + 1);
	assert(actual);

	get_all_asciis(source);
	memmove(source, target, ASCIISLEN - 1);
	ft_memmove(source, actual, ASCIISLEN - 1);

	check_against_stdlib(target, actual);
}

void test_same_dest_src(void)
{
	source = malloc(sizeof(char) * ASCIISLEN);
	assert(source);
	get_all_asciis(source);

	char *source_dup = strdup(source);
	assert(source_dup);

	target = source;
	actual = source_dup;

	memmove(target, source, ASCIISLEN - 1);
	ft_memmove(actual, source_dup, ASCIISLEN - 1);

	check_against_stdlib(target, actual);

	if (source_dup)
		free(source_dup);
	source_dup = NULL;

	target = NULL;
	actual = NULL;
}

void test_smaller_src(void)
{
	source = malloc(sizeof(char) * ASCIISLEN);
	assert(source);
	get_all_asciis(source);

	char *source_dup = strdup(source);
	assert(source_dup);

	target = source + 1;
	actual = source_dup + 1;

	memmove(target, source, ASCIISLEN - 1);
	ft_memmove(actual, source_dup, ASCIISLEN - 1);

	check_against_stdlib(target, actual);

	if (source_dup)
		free(source_dup);
	source_dup = NULL;

	target = NULL;
	actual = NULL;
}

void test_larger_src(void)
{
	char container_target[ASCIISLEN + 1] = {0};
	source = container_target + 1;
	get_all_asciis(source);

	char  container_actual[ASCIISLEN + 1] = {0};
	char *source_actual = container_actual + 1;
	get_all_asciis(source_actual);

	target = container_target;
	actual = container_actual;

	memmove(target, source, ASCIISLEN);
	ft_memmove(actual, source_actual, ASCIISLEN);

	check_against_stdlib(target, actual);

	source = NULL;
	target = NULL;
	actual = NULL;
}
