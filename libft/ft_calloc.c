/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:51:59 by erpascua          #+#    #+#             */
/*   Updated: 2025/07/04 16:08:38 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if (size && count > 18446744073709551615UL / size)
		return (NULL);
	p = malloc (count * size);
	if (!p)
		return (NULL);
	ft_bzero(p, (count * size));
	return (p);
}
