/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:14:29 by erpascua          #+#    #+#             */
/*   Updated: 2025/09/01 13:44:56 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printf_str(char *s, int fd)
{
	size_t	len;
	int		tmp;

	if (!s)
	{
		if (write(fd, "(null)", 6) < 0)
			return (-1);
		return (6);
	}
	len = pf_strlen(s);
	while (*s)
	{
		tmp = printf_char(*s++, fd);
		if (tmp < 0)
			return (-1);
	}
	return ((int)len);
}
