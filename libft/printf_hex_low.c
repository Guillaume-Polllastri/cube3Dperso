/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hex_low.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:54:39 by erpascua          #+#    #+#             */
/*   Updated: 2025/09/01 13:33:09 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printf_hex_low(unsigned int n, int fd)
{
	int	div;
	int	mod;

	if (n == 0)
		return (printf_char('0', fd));
	if (n >= 16)
	{
		div = printf_hex_low(n / 16, fd);
		if (div < 0)
			return (-1);
		mod = printf_hex_low(n % 16, fd);
		if (mod < 0)
			return (-1);
		return (div + mod);
	}
	if (n <= 9)
		return (printf_char('0' + n, fd));
	return (printf_char('a' + (n - 10), fd));
}
