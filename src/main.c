/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:06:57 by gpollast          #+#    #+#             */
/*   Updated: 2025/11/13 20:11:11 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _USE_MATH_DEFINES
#define _GNU_SOURCE

#include "cube3d.h"
#include <stdio.h>
#include <math.h>
#include "../minilibx-linux/mlx.h"
#include "../libft/libft.h"

#define FOV_ANGLE M_PI_2

static int  handle_key_hook(int keycode, t_game *game)
{
    if (keycode == ESC)
    	mlx_loop_end(game->mlx);
    else if (keycode == LEFT_ARROW)
	{
		game->player->teta = (int)(game->player->teta - 1) % (int)(2.0 * M_PI);
		printf("Tourne a gauche\n");		
	}
    else if (keycode == RIGHT_ARROW)
	{
		game->player->teta = (int)(game->player->teta + 1) % (int)(2.0 * M_PI);
      	printf("Tourne a droite\n");
	}
    else if (keycode == W)
	{
		game->player->y -= 5;
      	printf("HAUT\n");
	}
    else if (keycode == A)
	{
		game->player->x -= 5;
      	printf("GAUCHE\n");
	}
    else if (keycode == S)
	{
		game->player->y += 5;
        printf("BAS\n");
	}
    else if (keycode == D)
	{
		game->player->x += 5;
        printf("DROITE\n");
	}
    return (0);
}

static void	draw_line(t_game *game, int distance, double teta)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	while (i < distance)
	{
		x = game->player->x + i * cos(teta);
		y = game->player->y + i * sin(teta);
		mlx_pixel_put(game->mlx, game->win_ptr, x, y, 0x00FF00);
		i++;
	}
}

static void	draw_fov(t_game *game, double player_angle, int fov_range)
{
    int	distance;
	double	left_teta;
	double	right_teta;

	distance = fov_range;
	left_teta = player_angle + (FOV_ANGLE / 2);
	right_teta = player_angle - (FOV_ANGLE / 2);
    draw_line(game, distance, left_teta);
    draw_line(game, distance, right_teta);
}

static int	render(t_game *game)
{
	mlx_clear_window(game->mlx, game->win_ptr);
    draw_fov(game, game->player->teta, 150);
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
	game.player->x = 100;
  	game.player->y = 100;
	game.player->teta = 0;
  	game.mlx = mlx_init();
  	game.win_ptr = mlx_new_window(game.mlx, WIN_WIDTH, WIN_HEIGHT, "cube3D");
	mlx_loop_hook(game.mlx, render, &game);
  	mlx_hook(game.win_ptr, 2, 1L<<0, handle_key_hook, &game);
  	mlx_loop(game.mlx);
  	return (0);
}
