/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrain <lrain@students.42berlin.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:27:30 by lrain             #+#    #+#             */
/*   Updated: 2025/12/18 22:21:41 by lrain            ###   ########.fr       */
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

int		ft_toupper(int c);
int		ft_tolower(int c);

size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *ss1, const char *ss2, size_t n);
char	*ft_strchr(const char *str, int c);
char	*ft_strstr(const char *haystack, const char *needle, size_t count);
size_t	ft_strlcpy(char *dst, const char *src, size_t count);
size_t	ft_strlcat(char *dest, const char *src, size_t count);

int		ft_memcmp(const void *lhs, const void *rhs, size_t count);
void	*ft_memcpy(void *dest, const void *src, size_t count);
void	*ft_memset(void *dest, int c, size_t count);
void	*ft_memchr(const void *src, int c, size_t count);
void	*ft_memmove(void *dest, const void *src, size_t count);
void	ft_bzero(void *s, size_t n);
int		ft_atoi(const char *str);

#endif
