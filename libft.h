/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrain <lrain@students.42berlin.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:27:30 by lrain             #+#    #+#             */
/*   Updated: 2025/12/16 15:50:47 by lrain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <stddef.h>

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isprint(int c);
int		ft_isascii(int c);

size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *ss1, const char *ss2, size_t n);

int		ft_memcmp(const void *lhs, const void *rhs, size_t count);
void	*ft_memcpy(void *dest, const void *src, size_t count);
void	*ft_memset(void *dest, int c, size_t count);
void	*ft_memchr(const void *src, int c, size_t count);
void	*ft_memmove(void *dest, const void *src, size_t count);
#endif
