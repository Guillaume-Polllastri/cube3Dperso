/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:06:57 by gpollast          #+#    #+#             */
/*   Updated: 2025/11/12 17:26:21 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include <stdio.h>
#include <math.h>
#include "../minilibx-linux/mlx.h"
#include "../libft/libft.h"

static int  handle_key_hook(int keycode, t_game *game)
{
    if (keycode == ESC)
      mlx_loop_end(game->mlx);
    else if (keycode == LEFT_ARROW)
		  printf("Tourne a gauche\n");
    else if (keycode == RIGHT_ARROW)
      printf("Tourne a droite\n");
    else if (keycode == W)
    {
      printf("HAUT\n");
      game->player->y -= 1;
    }
    else if (keycode == A)
    {
      printf("GAUCHE\n");
      game->player->x -= 1;
    }
    else if (keycode == S)
    {
        printf("BAS\n");
        game->player->y += 1;
    }
    else if (keycode == D)
    {
        printf("DROITE\n");
        game->player->x += 1;
    }
    mlx_pixel_put(game->mlx, game->win_ptr, game->player->x, game->player->y, 0xFF0000);
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
  game.player = calloc(1, sizeof(t_player));
  game.player->x = 100;
  game.player->y = 100;
  game.mlx = mlx_init();
  game.win_ptr = mlx_new_window(game.mlx, WIN_WIDTH, WIN_HEIGHT, "cube3D");
  mlx_key_hook(game.win_ptr, handle_key_hook, &game);
  mlx_loop(game.mlx);
  return (0);
}
