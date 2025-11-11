/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:52:23 by erpascua          #+#    #+#             */
/*   Updated: 2025/07/04 16:02:45 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nbrlen(int n)
{
	long		tmp_n;
	size_t		count;

	tmp_n = n;
	count = 0;
	if (tmp_n < 0)
	{
		count++;
		tmp_n = -tmp_n;
	}
	while (tmp_n >= 10)
	{
		count++;
		tmp_n /= 10;
	}
	count++;
	return (count);
}

char	*ft_itoa(int n)
{
	char	*nb;
	size_t	n_len;
	size_t	j;
	long	nlong;

	n_len = nbrlen(n);
	nb = (char *) malloc ((n_len + 1) * sizeof (char));
	if (!nb)
		return (NULL);
	nlong = n;
	if (nlong < 0)
	{
		nb[0] = '-';
		nlong = -nlong;
	}
	j = n_len - 1;
	while (nlong >= 10)
	{
		nb[j] = nlong % 10 + 48;
		nlong = nlong / 10;
		j--;
	}
	nb[j] = nlong % 10 + 48;
	nb[n_len] = '\0';
	return (nb);
}
