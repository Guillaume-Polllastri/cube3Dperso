/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 18:29:09 by gpollast          #+#    #+#             */
/*   Updated: 2025/11/26 11:11:37 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

double	ft_abs(double value)
{
	if (value < 0)
		value *= -1;
	return (value);
}

double	min_double(double a, double b)
{
	if (a <= b)
		return (a);
	return (b);
}

unsigned int	get_pixel_color(int r, int g, int b)
{
	int	color;

	color = (int)(r) << 16;
	color |= (int)(g) << 8;
	color |= (int)(b);
	return (color);
}

bool	is_wall(t_game *game, int x, int y)
{
	if (game->map->content[y][x] == '1')
		return (true);
	return (false);
}
