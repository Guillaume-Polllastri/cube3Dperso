/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:53:02 by erpascua          #+#    #+#             */
/*   Updated: 2025/05/02 14:53:04 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
int	main(int ac, char **av)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (i < ac)
	{
		while (av[i][j])
		{
			ft_putchar_fd(av[i][j], 1);
			j++;
		}
		j = 0;
		i++;
	}
}
*/