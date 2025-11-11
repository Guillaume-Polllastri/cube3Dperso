/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:43:49 by erpascua          #+#    #+#             */
/*   Updated: 2025/07/04 16:02:57 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*p_dest;
	const unsigned char	*p_src;

	if (!dest && !src)
		return (NULL);
	if (dest == src || n == 0)
		return (dest);
	p_dest = (unsigned char *) dest;
	p_src = (const unsigned char *) src;
	if (p_dest > p_src)
		while (n--)
			p_dest[n] = p_src[n];
	else
	{
		i = 0;
		while (i < n)
		{
			p_dest[i] = p_src[i];
			i++;
		}
	}
	return (dest);
}
