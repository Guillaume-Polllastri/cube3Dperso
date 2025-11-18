/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 10:05:52 by gpollast          #+#    #+#             */
/*   Updated: 2025/11/18 18:50:40 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include <stdio.h>
#include "../minilibx-linux/mlx.h"
#include "../libft/libft.h"

static void	update_player_movement(t_game *game)
{
    if (game->is_pressed[KEY_W])
    {
        game->player->y += PLAYER_SPEED * sin(game->player->teta);
        game->player->x += PLAYER_SPEED * cos(game->player->teta);
    }
    if (game->is_pressed[KEY_A])
    {
        game->player->y += PLAYER_SPEED * sin(game->player->teta + M_PI_2);
        game->player->x += PLAYER_SPEED * cos(game->player->teta + M_PI_2);
    }
    if (game->is_pressed[KEY_S])
    {
        game->player->y += PLAYER_SPEED * sin(game->player->teta + M_PI);
        game->player->x += PLAYER_SPEED * cos(game->player->teta + M_PI);
    }
    if (game->is_pressed[KEY_D])
    {
        game->player->y += PLAYER_SPEED * sin(game->player->teta - M_PI_2);
        game->player->x += PLAYER_SPEED * cos(game->player->teta - M_PI_2);
    }
    if (game->is_pressed[KEY_LEFT_ARROW])
        game->player->teta += ROTATE_SPEED;
    if (game->is_pressed[KEY_RIGHT_ARROW])
        game->player->teta -= ROTATE_SPEED;
}

static int	render(t_game *game)
{
    ft_memset(game->buffer->addr, 0, WIN_WIDTH * WIN_HEIGHT * (game->buffer->bits_per_pixel / 8));
    draw_fov(game, game->player->teta, game->player->fov_distance);
    mlx_put_image_to_window(game->mlx, game->win_ptr, game->buffer->img, 0, 0);
    return (1);
}

int	game_loop(t_game *game)
{
	update_player_movement(game);
	render(game);
	return (1);
}
