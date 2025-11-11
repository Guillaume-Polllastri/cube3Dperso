/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:50:42 by erpascua          #+#    #+#             */
/*   Updated: 2025/09/01 13:20:50 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printf_char(int c, int fd)
{
	char	char_c;
	int		r;

	char_c = (char)c;
	r = write(fd, &char_c, 1);
	if (r < 0)
		return (-1);
	return (1);
}
