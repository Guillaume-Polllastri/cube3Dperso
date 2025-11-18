/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:07:42 by gpollast          #+#    #+#             */
/*   Updated: 2025/11/18 11:21:55 by gpollast         ###   ########.fr       */
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
	double  fov_distance;
}	t_player;

typedef struct	s_framebuffer
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_framebuffer;

typedef enum	e_keys
{
	KEY_W = 0,
	KEY_A = 1,
	KEY_S = 2,
	KEY_D = 3,
	KEY_LEFT_ARROW = 4,
	KEY_RIGHT_ARROW = 5,
	KEY_COUNT = 6
}	t_keys;

typedef struct s_game
{
	void			*mlx;
	void			*win_ptr;
	t_framebuffer	*buffer;
	t_map			*map;
	t_player		*player;
	int				keys[6];
	bool			is_pressed[6];
}	t_game;

int		parse(t_game *game, char *s);
double	ft_abs(double value);
int		game_loop(t_game *game);
void	draw_fov(t_game *game, double player_angle, int fov_range);

#endif