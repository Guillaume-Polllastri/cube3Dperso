/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:47:43 by erpascua          #+#    #+#             */
/*   Updated: 2025/09/01 13:37:59 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printf_unsigned(unsigned int n, int fd)
{
	int	written;

	written = 0;
	if (n >= 10)
		written += printf_unsigned(n / 10, fd);
	if (written < 0)
		return (-1);
	if (printf_char((n % 10) + '0', fd) < 0)
		return (-1);
	return (written + 1);
}
