/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:07:42 by gpollast          #+#    #+#             */
/*   Updated: 2025/11/13 18:46:36 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

#include <stdbool.h>
#include "config.h"

typedef	struct	s_map
{
	char	**content;
	int		width;
	int		height;
}	t_map;

typedef struct	s_player
{
	double	x;
	double	y;
	double	teta;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win_ptr;
	t_map		*map;
	t_player	*player;
}	t_game;

int		parse(t_game *game, char *s);
double	ft_abs(double value);

#endif