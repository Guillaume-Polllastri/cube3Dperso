/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 13:34:48 by erpascua          #+#    #+#             */
/*   Updated: 2025/07/10 13:37:26 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	result;

	result = 0;
	if (nb <= 0)
		return (0);
	else if (nb == 1)
		return (1);
	while (result <= nb / 2)
	{
		if ((nb == result * result) && (nb % result == 0))
			return (result);
		result++;
	}
	return (0);
}
