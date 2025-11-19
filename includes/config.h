/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:45:08 by gpollast          #+#    #+#             */
/*   Updated: 2025/11/19 14:19:45 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

#define _USE_MATH_DEFINES
#define _GNU_SOURCE
#include <math.h>

#define WIN_WIDTH 1280
#define WIN_HEIGHT 720

#define MAP_WIDTH 8
#define MAP_HEIGHT 5

#define FOV_ANGLE M_PI_4
#define LIGHT 108
#define PLAYER_SPEED 0.1
#define ROTATE_SPEED 0.017 * 3

#define ESC 65307
#define LEFT_ARROW 65361
#define RIGHT_ARROW 65363
#define W 119
#define A 97
#define S 115
#define D 100

#define RED 0x00FF0000
#define GREEN 0x0000FF00
#define BLUE 0x000000FF

#endif