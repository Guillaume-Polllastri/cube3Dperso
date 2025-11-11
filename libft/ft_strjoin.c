/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:54:16 by erpascua          #+#    #+#             */
/*   Updated: 2025/07/04 16:04:17 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	joiner(char *r, const char *to_cpy, size_t i)
{
	size_t	j;

	j = 0;
	while (to_cpy[j])
		r[i++] = to_cpy[j++];
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*r;
	size_t	len_s1;
	size_t	len_s2;
	size_t	malloc_len;
	size_t	i;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	malloc_len = len_s1 + len_s2;
	r = (char *) malloc ((malloc_len + 1) * sizeof (char));
	if (!r)
		return (NULL);
	i = 0;
	i = joiner(r, s1, i);
	i = joiner(r, s2, i);
	r[i] = '\0';
	return (r);
}
