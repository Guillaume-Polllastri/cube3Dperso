/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:45:00 by gpollast          #+#    #+#             */
/*   Updated: 2025/11/11 12:21:31 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "../../libft/libft.h"

static bool	is_valid_name(char *s)
{
	char	*first_occurence;

	first_occurence = ft_strnstr(s, ".cub", ft_strlen(s));
	if (!first_occurence)
		return (false);
	if (!ft_strcmp(first_occurence, ".cub") && ft_strlen(first_occurence) == ft_strlen(".cub"))
		return (true);
	return (false);
}

int	parse(char *s)
{
	if (!is_valid_name(s))
	{
		ft_fprintf(2, "Error extension file must be .cub\n");
		return (0);		
	}
	return (1);
}
