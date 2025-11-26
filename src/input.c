/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:18:30 by gpollast          #+#    #+#             */
/*   Updated: 2025/11/26 11:24:44 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "cube3d.h"

void	setup_keys(t_game *game)
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

int	handle_key_press(int keycode, t_game *game)
{
	int	index_keys;

	index_keys = get_index_keys(game, keycode);
	if (keycode == ESC)
		mlx_loop_end(game->mlx);
	else if (index_keys >= 0)
		game->is_pressed[index_keys] = true;
	return (0);
}

int	handle_key_release(int keycode, t_game *game)
{
	int	index_keys;

	index_keys = get_index_keys(game, keycode);
	if (index_keys >= 0)
		game->is_pressed[index_keys] = false;
	return (0);
}
