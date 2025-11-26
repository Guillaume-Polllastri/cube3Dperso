/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:06:57 by gpollast          #+#    #+#             */
/*   Updated: 2025/11/26 15:57:12 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "../minilibx-linux/mlx.h"
#include "../libft/libft.h"
#include <stdio.h>

// static void	load_texture(t_game *game, t_texture *texture, char *path)
// {
// 	texture = ft_calloc(1, sizeof(t_texture));
// 	texture->img = mlx_xpm_file_to_image(game->mlx, path, &texture->width, &texture->height);
// 	texture->addr = mlx_get_data_addr(texture->img, &texture->bits_per_pixel, &texture->size_line, &texture->endian);
// }

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
	game.textures = ft_calloc(1, sizeof(t_textures));
	// load_texture(&game, &game.textures->north, "textures/wall_north.xpm");
	// load_texture(&game, &game.textures->south, "textures/wall_south.xpm");
	// load_texture(&game, &game.textures->east, "textures/wall_east.xpm");
	// load_texture(&game, &game.textures->west, "textures/wall_west.xpm");
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
