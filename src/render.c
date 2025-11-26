/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:08:47 by gpollast          #+#    #+#             */
/*   Updated: 2025/11/26 11:12:28 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "../minilibx-linux/mlx.h"
#include "../libft/libft.h"

static	t_hit	raycast_dda(t_game *game, double rayDirX, double rayDirY)
{
	t_hit	hit;
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
	deltaDistX = (rayDirX == 0.0) ? 1e30 : fabs(1.0 / rayDirX);
	deltaDistY = (rayDirY == 0.0) ? 1e30 : fabs(1.0 / rayDirY);
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
    double	projection_plane_distance;

    projection_plane_distance = (WIN_WIDTH / 2.0) / tan(FOV_ANGLE / 2.0);
    if (distance <= 0)
        wall_height = WIN_HEIGHT;
    else
        wall_height = (int)(projection_plane_distance / distance);
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
    double	dirX;
    double	dirY;
    double	planeX;
    double	planeY;
    double	rayDirX;
    double	rayDirY;
    double	cameraX;
    int		x;
    t_hit	hit;

    dirX = cos(player_angle);
    dirY = sin(player_angle);
    planeX = -sin(player_angle) * tan(FOV_ANGLE / 2.0);
    planeY = cos(player_angle) * tan(FOV_ANGLE / 2.0);
    x = 0;
    while (x < WIN_WIDTH)
    {
        cameraX = 2.0 * x / WIN_WIDTH - 1.0;
        rayDirX = dirX + planeX * cameraX;
        rayDirY = dirY + planeY * cameraX;
        hit = raycast_dda(game, rayDirX, rayDirY);
        draw_col(game, hit, x, hit.distance);
        x++;
    }
}
