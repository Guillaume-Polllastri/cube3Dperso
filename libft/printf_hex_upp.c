/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hex_upp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 02:09:49 by ep                #+#    #+#             */
/*   Updated: 2025/09/01 13:51:47 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printf_hex_upp(unsigned int n, int fd)
{
	int	div;
	int	mod;

	if (n == 0)
		return (printf_char('0', fd));
	if (n >= 16)
	{
		div = printf_hex_upp(n / 16, fd);
		if (div < 0)
			return (-1);
		mod = printf_hex_upp(n % 16, fd);
		if (mod < 0)
			return (-1);
		return (div + mod);
	}
	if (n <= 9)
		return (printf_char('0' + n, fd));
	return (printf_char('A' + (n - 10), fd));
}
