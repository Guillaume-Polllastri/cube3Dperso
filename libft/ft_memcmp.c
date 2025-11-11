/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:52:47 by erpascua          #+#    #+#             */
/*   Updated: 2025/07/04 16:02:51 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p_s1;
	unsigned char	*p_s2;

	if (n == 0)
		return (0);
	p_s1 = (unsigned char *)s1;
	p_s2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*p_s1 != *p_s2)
			return ((unsigned int)*p_s1 - *p_s2);
		p_s1++;
		p_s2++;
		n--;
	}
	return (0);
}
