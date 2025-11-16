/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:45:08 by gpollast          #+#    #+#             */
/*   Updated: 2025/11/16 13:23:31 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

#define _USE_MATH_DEFINES
#define _GNU_SOURCE
#include <math.h>

#define WIN_WIDTH 1000
#define WIN_HEIGHT 600

#define MAP_WIDTH 8
#define MAP_HEIGHT 5

#define FOV_ANGLE M_PI_4
#define LIGHT 108
#define PLAYER_SPEED 10

#define ESC 65307
#define LEFT_ARROW 65361
#define RIGHT_ARROW 65363
#define W 119
#define A 97
#define S 115
#define D 100

#endif