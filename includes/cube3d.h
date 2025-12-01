/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:07:42 by gpollast          #+#    #+#             */
/*   Updated: 2025/12/01 11:41:12 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

#include <stdbool.h>
#include "config.h"
#include "texture.h"

typedef	struct	s_map
{
	char	**content;
	int		width;
	int		height;
}	t_map;

typedef enum e_direction
{
	NORTH = 0,
	SOUTH = 1,
	WEST = 2,
	EAST = 3,
	DIRECTION_COUNT = 4
}	t_direction;

typedef struct s_hit
{
    double		distance;
    t_direction	face;
	double		wallX;
}   t_hit;

typedef struct	s_player
{
	double		x;
	double		y;
	double		teta;
	double  	fov_distance;
	t_direction	direction;
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
	t_texture_pack	*textures;
}	t_game;

int				parse(t_game *game, char *s);
double			ft_abs(double value);
int				game_loop(t_game *game);
void			draw_fov(t_game *game, double player_angle);
double			min_double(double a, double b);
bool			is_wall(t_game *game, int x, int y);
unsigned int	get_pixel_color(int r, int g, int b);

// input.c
void			setup_keys(t_game *game);
int  			handle_key_press(int keycode, t_game *game);
int				handle_key_release(int keycode, t_game *game);

#endif