/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:55:12 by erpascua          #+#    #+#             */
/*   Updated: 2025/06/18 18:50:56 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*r;
	size_t	len_s;
	size_t	i;
	size_t	malloc_len;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start > len_s)
		return (ft_strdup(""));
	malloc_len = len_s - start;
	if (malloc_len > len)
		malloc_len = len;
	r = (char *) malloc ((malloc_len + 1) * sizeof (char));
	if (!r)
		return (NULL);
	i = 0;
	while (i < malloc_len)
	{
		r[i] = s[start + i];
		i++;
	}
	r[i] = '\0';
	return (r);
}
