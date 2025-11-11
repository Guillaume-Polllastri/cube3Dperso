/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:47:47 by erpascua          #+#    #+#             */
/*   Updated: 2025/09/01 13:45:58 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	put_ptr(uintptr_t n, int fd)
{
	int	written;
	int	tmp;

	if (n >= 16)
	{
		written = put_ptr(n / 16, fd);
		if (written < 0)
			return (-1);
		tmp = put_ptr(n % 16, fd);
		if (tmp < 0)
			return (-1);
		return (written + tmp);
	}
	if (n <= 9)
		return (printf_char('0' + (int)n, fd));
	return (printf_char('a' + (int)(n - 10), fd));
}

int	printf_address(void *ptr, int fd)
{
	int	tmp;

	if (ptr == NULL)
		return (printf_str("(nil)", fd));
	if (printf_str("0x", fd) < 0)
		return (-1);
	tmp = put_ptr((uintptr_t)ptr, fd);
	if (tmp < 0)
		return (-1);
	return (2 + tmp);
}
