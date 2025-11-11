/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:06:57 by gpollast          #+#    #+#             */
/*   Updated: 2025/11/11 12:10:28 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include <stdio.h>
#include <math.h>
#include "../minilibx-linux/mlx.h"

static int  handle_key_hook(int keycode, void *mlx)
{
    if (keycode == ESC)
        mlx_loop_end(mlx);
    else if (keycode == LEFT_ARROW)
        printf("GAUCHE\n");
    else if (keycode == RIGHT_ARROW)
        printf("DROITE\n");
    else if (keycode == UP_ARROW)
        printf("HAUT\n");
    else if (keycode == DOWN_ARROW)
        printf("BAS\n");
    else
        printf("%d\n", keycode);
    return (0);
}

int main(int ac, char **av)
{
    void    *mlx;
    void    *win_ptr;
 
	if (ac != 2)
		return (printf("Usage: ./cube3D <map.cub>\n"), 1);
	if (!parse(av[1]))
		return (1);
    mlx = mlx_init();
    win_ptr = mlx_new_window(mlx, 600, 600, "cube3D");
    mlx_key_hook(win_ptr, handle_key_hook, mlx);
    mlx_loop(mlx);
    return (0);
}
