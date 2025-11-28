/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 10:05:52 by gpollast          #+#    #+#             */
/*   Updated: 2025/11/27 11:05:02 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"
#include <stdio.h>

static void	player_movement(t_game *game, t_keys key, double teta)
{
	double	calculx;
	double	calculy;

	if (game->is_pressed[key])
	{
		calculy = PLAYER_SPEED * sin(teta);
		calculx = PLAYER_SPEED * cos(teta);
		if (!is_wall(game, game->player->x + calculx, game->player->y
				+ calculy))
		{
			game->player->y += calculy;
			game->player->x += calculx;
		}
	}
}

static void	update_player_movement(t_game *game)
{
	player_movement(game, KEY_W, game->player->teta);
	player_movement(game, KEY_A, game->player->teta - M_PI_2);
	player_movement(game, KEY_S, game->player->teta + M_PI);
	player_movement(game, KEY_D, game->player->teta + M_PI_2);
	if (game->is_pressed[KEY_LEFT_ARROW])
		game->player->teta -= ROTATE_SPEED;
	if (game->is_pressed[KEY_RIGHT_ARROW])
		game->player->teta += ROTATE_SPEED;
}

static int	render(t_game *game)
{
	ft_memset(game->buffer->addr, 0, WIN_WIDTH * WIN_HEIGHT
		* (game->buffer->bits_per_pixel / 8));
	draw_fov(game, game->player->teta);
	mlx_put_image_to_window(game->mlx, game->win_ptr, game->buffer->img, 0, 0);
	return (1);
}

int	game_loop(t_game *game)
{
	update_player_movement(game);
	render(game);
	return (1);
}
