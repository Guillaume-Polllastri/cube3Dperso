/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:06:57 by gpollast          #+#    #+#             */
/*   Updated: 2025/11/14 19:13:16 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _USE_MATH_DEFINES
#define _GNU_SOURCE

#include "cube3d.h"
#include <stdio.h>
#include <math.h>
#include "../minilibx-linux/mlx.h"
#include "../libft/libft.h"

#define FOV_ANGLE M_PI_4
#define LIGHT 108

static int  handle_key_hook(int keycode, t_game *game)
{
    if (keycode == ESC)
    	mlx_loop_end(game->mlx);
    else if (keycode == LEFT_ARROW)
	{
		game->player->teta = (int)(game->player->teta - 1) % (int)(2.0 * M_PI);
		// printf("Tourne a gauche\n");		
	}
    else if (keycode == RIGHT_ARROW)
	{
		game->player->teta = (int)(game->player->teta + 1) % (int)(2.0 * M_PI);
      	// printf("Tourne a droite\n");
	}
    else if (keycode == W)
	{
		game->player->y -= 10;
      	// printf("HAUT\n");
	}
    else if (keycode == A)
	{
		game->player->x -= 10;
      	// printf("GAUCHE\n");
	}
    else if (keycode == S)
	{
		game->player->y += 10;
        // printf("BAS\n");
	}
    else if (keycode == D)
	{
		game->player->x += 10;
        // printf("DROITE\n");
	}
	else if (keycode == LIGHT)
	{
		if (game->player->fov_distance == 100)
			game->player->fov_distance = WIN_WIDTH;
		else
			game->player->fov_distance = 100;
	}
    return (0);
}

static	bool	is_wall(t_game *game, int x, int y)
{
	int	x_grid;
	int	y_grid;

	x_grid = x / (WIN_WIDTH / MAP_WIDTH);
	y_grid = y / (WIN_HEIGHT / MAP_HEIGHT);
	if (game->map->content[x_grid][y_grid] == '1')
		return (true);
	return (false);
}

static void	draw_line(t_game *game, int distance, double teta)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	while (i < distance)
	{
		if (is_wall(game, (int)x, (int)y))
			return ;
		mlx_pixel_put(game->mlx, game->win_ptr, x, y, 0x00FF00);
		x = game->player->x + i * cos(teta);
		y = game->player->y + i * sin(teta);
		i++;
	}
}

static void	draw_fov(t_game *game, double player_angle, int fov_range)
{
    int		distance;
    double	left_teta;
    double	right_teta;
    double	current_teta;
    double	ray_step;
    int		num_rays;

    distance = fov_range;
    left_teta = player_angle + (FOV_ANGLE / 2);
    right_teta = player_angle - (FOV_ANGLE / 2);
    num_rays = 20;
    ray_step = FOV_ANGLE / num_rays;
    current_teta = left_teta;
    while (current_teta >= right_teta)
    { 
        draw_line(game, distance, current_teta);
        current_teta -= ray_step;
    }
}

static int	render(t_game *game)
{
	mlx_clear_window(game->mlx, game->win_ptr);
    draw_fov(game, game->player->teta, game->player->fov_distance);
    mlx_pixel_put(game->mlx, game->win_ptr, game->player->x, game->player->y, 0xFF0000);
    return (1);
}

int main(int ac, char **av)
{
	t_game	game;
 
	if (ac != 2)
		return (printf("Usage: ./cube3D <map.cub>\n"), 1);
	ft_bzero(&game, sizeof(game));
	if (!parse(&game, av[1]))
		return (1);
	game.player = calloc(1, sizeof(t_player));
	game.player->x = 300;
  	game.player->y = 300;
	game.player->teta = 0;
	game.player->fov_distance = 100;
  	game.mlx = mlx_init();
  	game.win_ptr = mlx_new_window(game.mlx, WIN_WIDTH, WIN_HEIGHT, "cube3D");
	mlx_loop_hook(game.mlx, render, &game);
  	mlx_hook(game.win_ptr, 2, 1L<<0, handle_key_hook, &game);
  	mlx_loop(game.mlx);
  	return (0);
}
