/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musicvivireal <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:31:05 by musicvivireal     #+#    #+#             */
/*   Updated: 2025/11/18 22:43:48 by musicvivireal    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	atoi(const char *str)
{
	int	number;
	int	prefix;
	int	positional_val;
	int	curr_digit;

	prefix = 0;
	number = 0;
	positional_val = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			prefix = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		curr_digit = *str - '0';
		number += curr_digit * positional_val * prefix;
		str++;
		positional_val *= 10;
	}
	return (number);
}
