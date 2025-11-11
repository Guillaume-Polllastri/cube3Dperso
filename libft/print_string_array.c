/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 11:33:16 by gpollast          #+#    #+#             */
/*   Updated: 2025/09/19 11:33:57 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	print_string_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		ft_fprintf(1, "%s ", array[i]);
		i++;
	}
	ft_fprintf(1, "\n");
}
