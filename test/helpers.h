/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test/helpers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrain <lrain@students.42berlin.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:47:54 by lrain             #+#    #+#             */
/*   Updated: 2025/12/03 17:45:40 by lrain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERS_H

// # include "../unity/src/unity.h"
# include <assert.h>
# include <stdio.h>

# ifdef VERBOSE
#  define VERBOSE_PRINT(...) printf(__VA_ARGS__)
# else
#  define VERBOSE_PRINT(...)
# endif

# define HELPERS_H
#endif
