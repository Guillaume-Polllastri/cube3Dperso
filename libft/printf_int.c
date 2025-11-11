/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:47:43 by erpascua          #+#    #+#             */
/*   Updated: 2025/09/01 13:47:48 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printf_int(int n, int fd)
{
	long	nb;
	int		written;
	int		tmp;

	nb = (long)n;
	written = 0;
	if (nb < 0)
	{
		if (printf_char('-', fd) < 0)
			return (-1);
		nb = -nb;
		written = 1;
	}
	if (nb >= 10)
	{
		tmp = printf_int((int)(nb / 10), fd);
		if (tmp < 0)
			return (-1);
		written += tmp;
	}
	if (printf_char((int)(nb % 10) + '0', fd) < 0)
		return (-1);
	return (written + 1);
}
