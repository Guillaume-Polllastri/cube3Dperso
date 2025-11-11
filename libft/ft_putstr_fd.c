/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:53:36 by erpascua          #+#    #+#             */
/*   Updated: 2025/05/02 14:53:37 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		ft_putchar_fd(*s++, fd);
}
/*
int	main(int ac, char **av)
{
	int	i;
	
	i = 0;
	while (i < ac)
	{
		ft_putstr_fd(av[i], 1);
		i++;
	}
	return (0);
}
*/