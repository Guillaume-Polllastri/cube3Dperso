/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:14:59 by erpascua          #+#    #+#             */
/*   Updated: 2025/06/17 11:22:36 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// size_t	ft_strlen(const char *s)
// {
// 	size_t	l;

// 	l = 0;
// 	if (!s)
// 		return (0);
// 	while (s[l])
// 		l++;
// 	return (l);
// }

// char	*ft_strchr(const char *s, int c)
// {
// 	if (!s)
// 		return (NULL);
// 	while (*s && *s != (char) c)
// 		s++;
// 	if (*s == (char) c)
// 		return ((char *)s);
// 	return (NULL);
// }

// char	*ft_strdup(const char *s)
// {
// 	char	*dup;
// 	size_t	i;
// 	size_t	len_s;

// 	if (!s)
// 		return (NULL);
// 	len_s = ft_strlen(s);
// 	dup = (char *) malloc ((len_s + 1));
// 	if (!dup)
// 		return (NULL);
// 	i = 0;
// 	while (i < len_s)
// 	{
// 		dup[i] = s[i];
// 		i++;
// 	}
// 	dup[i] = '\0';
// 	return (dup);
// }

static void	*gnl_memcpy(char *dst, char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (n > 0)
	{
		dst[i] = src[i];
		i++;
		n--;
	}
	return (dst);
}

char	*gnl_join(char *stash, char *buf, size_t n)
{
	char	*r;
	size_t	len_stash;

	if (!stash)
		len_stash = 0;
	else
		len_stash = ft_strlen(stash);
	r = (char *) malloc ((len_stash + n + 1));
	if (!r)
	{
		free(stash);
		return (NULL);
	}
	if (stash)
	{
		gnl_memcpy(r, stash, len_stash);
		free(stash);
	}
	gnl_memcpy(r + len_stash, buf, n);
	r[len_stash + n] = '\0';
	return (r);
}
