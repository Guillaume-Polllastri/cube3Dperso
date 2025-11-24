/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:06:57 by gpollast          #+#    #+#             */
/*   Updated: 2025/11/24 18:24:20 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include <stdio.h>
#include "../minilibx-linux/mlx.h"
#include "../libft/libft.h"

bool	is_wall(t_game *game, int x, int y)
{
	if (game->map->content[y][x] == '1')
		return (true);
	return (false);
}

// static double	dda_step_(double a, double va)
// {
// 	double	next_a;
// 	double	ta;
	
// 	if (va > 0)
// 		next_a = ceil(a);
// 	else if (va < 0)
// 		next_a = floor(a);
// 	else
// 		next_a = NAN;
// 	if (!va)
// 		ta = (next_a - a) / va;
// 	else
// 		ta = NAN;
// 	return (ta);
// }

// static	void	get_wall_face(t_game *game, double x, double y)
// {
// 	double	dx;
// 	double	dy;

// 	dx = x - game->player->x;
// 	dy = y - game->player->y;
// 	if (ft_abs(dy) > ft_abs(dx))
// 	{
// 		if (dy < 0)
// 			game->player->direction = NORTH;
// 		else
// 			game->player->direction = SOUTH;
// 	}
// 	else
// 	{
// 		if (dx < 0)
// 			game->player->direction = WEST;
// 		else
// 			game->player->direction = EAST;
// 	}PLAYER_SPEED * cos(game->player->teta)
// }

// static void	dda_algo(t_game *game)
// {
// 	double	mapX;
// 	double	mapY;
// 	double	deltaDistX;
// 	double	deltaDistY;

// 	mapX = floor(game->player->x);
// 	mapY = floor(game->player->y);
// 	deltaDistX = ft_abs(1 / 1);
// 	deltaDistY = ft_abs(1 / 0.66);
// }

// static double	compute_distance(t_game *game, int distance, double teta)
// {
//     double	i;
//     double	x;
//     double	y;

//     i = 0;
//     while (i < distance)
//     {
//         x = game->player->x + i * cos(teta);
//         y = game->player->y + i * sin(teta);
//         if (x < 0 || x >= game->map->width || y < 0 || y >= game->map->height)
//             return (i);
//         if (is_wall(game, (int)x, (int)y))
//         {
//             game->player->direction = NORTH;
//             return (i);
//         }
//         i += 0.001;
//     }
//     game->player->direction = NORTH;
//     return (i);
// }

static	t_hit	raycast_dda(t_game *game , double teta)
{
	t_hit	hit;
	double	rayDirX;
	double	rayDirY;
	double	deltaDistX;
	double	deltaDistY;
	int		mapX;
	int		mapY;
	int		stepX;
	int		stepY;
	double	sideDistX;
	double	sideDistY;
	int		side;
	
	hit.distance = 0;
	rayDirX = cos(teta);
	rayDirY = sin(teta);
    deltaDistX = (rayDirX == 0.0) ? 1e30 : ft_abs(1.0 / rayDirX);
    deltaDistY = (rayDirY == 0.0) ? 1e30 : ft_abs(1.0 / rayDirY);
	mapX = (int)game->player->x;
	mapY = (int)game->player->y;
	if (rayDirX < 0)
	{
		stepX = -1;
		sideDistX = (game->player->x - (double)mapX) * deltaDistX;
	}
	else
	{ 
		stepX = 1;
		sideDistX = ((double)mapX + 1.0 - game->player->x) * deltaDistX;
	}
	if (rayDirY < 0)
	{
		stepY = -1;
		sideDistY = (game->player->y - (double)mapY) * deltaDistY;
	}
	else
	{
		stepY = 1;
		sideDistY = ((double)mapY + 1.0 - game->player->y) * deltaDistY;
	}
	while (true)
	{
		if (sideDistX < sideDistY)
		{
			sideDistX += deltaDistX;
			mapX += stepX;
			side = 0;
		}
		else
		{
			sideDistY += deltaDistY;
			mapY += stepY;
			side = 1;
		}
		if (is_wall(game, mapX, mapY))
			break ;
	}
	if (side == 0)
	{
		hit.distance = sideDistX - deltaDistX;
		if (stepX > 0)
			hit.face = EAST;
		else
			hit.face = WEST;
	}
	else
	{
		hit.distance = sideDistY - deltaDistY;
		if (stepY > 0)
			hit.face = SOUTH;
		else
			hit.face = NORTH;
	}
	return (hit);
}

static unsigned int	get_pixel_color(int r, int g, int b)
{
	int	color;

	color = (int)(r) << 16;
	color |= (int)(g) << 8;
	color |= (int)(b);
	return (color);
}

static void	draw_wall(t_game *game, t_hit hit, int offset)
{
	if (hit.face == NORTH)
		*(int *)(game->buffer->addr + offset) = get_pixel_color(0x13, 0x5e, 0x96);
	else if (hit.face == SOUTH)
		*(int *)(game->buffer->addr + offset) = get_pixel_color(0x13, 0x5e, 0x96);
	else if (hit.face == WEST)
		*(int *)(game->buffer->addr + offset) = get_pixel_color(0x13, 0x5e, 0x96) * 0.9;
	else if (hit.face == EAST)
		*(int *)(game->buffer->addr + offset) = get_pixel_color(0x13, 0x5e, 0x96) * 0.9;
}

static void	draw_col(t_game *game, t_hit hit, int x, double distance)
{
	int	y;
	int	wall_height;
	int	start;
	int	end;
	int	offset;

	if (distance == 0)
		wall_height = WIN_HEIGHT;
	else
		wall_height = WIN_HEIGHT / distance;
	start = (WIN_HEIGHT / 2.0) - (wall_height / 2.0);
	end = start + wall_height;
	y = 0;
	while (y < WIN_HEIGHT)
	{
		offset = y * game->buffer->size_line + x * (game->buffer->bits_per_pixel / 8);
		if (y < start)
			*(int *)(game->buffer->addr + offset) = get_pixel_color(0xDF, 0xEB, 0xEB);
		else if (y > end)
			*(int *)(game->buffer->addr + offset) = get_pixel_color(0xFF, 0xCB, 0xCB);
		else
			draw_wall(game, hit, offset);
		y++;
	}
}

void	draw_fov(t_game *game, double player_angle)
{
    double	left_teta;
    double	right_teta;
    double	current_teta;
    double	ray_step;
	int		x;
	t_hit	hit;

    left_teta = player_angle + (FOV_ANGLE / 2);
    right_teta = player_angle - (FOV_ANGLE / 2);
    ray_step = FOV_ANGLE / WIN_WIDTH;
    current_teta = left_teta;
	x = 0;
    while (current_teta >= right_teta)
    {
		hit = raycast_dda(game, current_teta);
        // distance = compute_distance(game, fov_range, current_teta);
		draw_col(game, hit, x, hit.distance);
        current_teta -= ray_step;
		x++;
    }
}

static void	setup_keys(t_game *game)
{
	game->keys[KEY_W] = W;
	game->keys[KEY_A] = A;
	game->keys[KEY_S] = S;
	game->keys[KEY_D] = D;
	game->keys[KEY_LEFT_ARROW] = LEFT_ARROW;
	game->keys[KEY_RIGHT_ARROW] = RIGHT_ARROW;
}

static int	get_index_keys(t_game *game, int keycode)
{
	int	i;

	i = 0;
	while (i < KEY_COUNT)
	{
		if (game->keys[i] == keycode)
			return (i);
		i++;
	}
	return (-1);
}

static int  handle_key_press(int keycode, t_game *game)
{
	int	index_keys;
	
	index_keys = get_index_keys(game, keycode);
    if (keycode == ESC)
        mlx_loop_end(game->mlx);
    else if (index_keys >= 0)
        game->is_pressed[index_keys] = true;
    return (0);
}

static int  handle_key_release(int keycode, t_game *game)
{
	int	index_keys;

	index_keys = get_index_keys(game, keycode);
	if (index_keys >= 0)
    	game->is_pressed[index_keys] = false;
    return (0);
}

int main(int ac, char **av)
{
	t_game	game;
 
	if (ac != 2)
		return (printf("Usage: ./cube3D <map.cub>\n"), 1);
	ft_bzero(&game, sizeof(game));
	if (!parse(&game, av[1]))
		return (1);
	game.player = ft_calloc(1, sizeof(t_player));
	game.player->x = 1.5;
  	game.player->y = 1.5;
	game.player->teta = 0;
	game.player->fov_distance = WIN_WIDTH;
	setup_keys(&game);
	ft_memset(&game.is_pressed, 0, sizeof(game.is_pressed));
	game.buffer = ft_calloc(1, sizeof(t_framebuffer));
  	game.mlx = mlx_init();
  	game.win_ptr = mlx_new_window(game.mlx, WIN_WIDTH, WIN_HEIGHT, "cube3D");
	game.buffer->img = mlx_new_image(game.mlx, WIN_WIDTH, WIN_HEIGHT);
	game.buffer->addr = mlx_get_data_addr(game.buffer->img, &game.buffer->bits_per_pixel, &game.buffer->size_line, &game.buffer->endian);
	mlx_loop_hook(game.mlx, game_loop, &game);
  	mlx_hook(game.win_ptr, 2, 1L<<0, handle_key_press, &game);
  	mlx_hook(game.win_ptr, 3, 1L<<1, handle_key_release, &game);
  	mlx_loop(game.mlx);
  	return (0);
}
