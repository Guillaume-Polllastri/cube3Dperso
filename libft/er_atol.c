/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   er_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 19:37:00 by ep                #+#    #+#             */
/*   Updated: 2025/07/17 11:11:39 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// clang-format off
long	is_in_int_range(const char *str)
{
	int		sign;
	long	nb;
	int		i;

	sign = 1;
	nb = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((sign == 1 && nb > (INT_MAX - (str[i] - '0')) / 10)
			|| (sign == -1 && - nb < (INT_MIN + (str[i] - '0')) / 10))
			return (ft_putendl_fd("Error", 2), exit(EXIT_FAILURE), 0);
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb * sign);
}
// clang-format on
