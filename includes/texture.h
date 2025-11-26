/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:05:36 by gpollast          #+#    #+#             */
/*   Updated: 2025/11/26 11:06:22 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
#define TEXTURE_H

typedef struct s_texture
{
    void	*img;
    char	*addr;
    int		bits_per_pixel;
    int		size_line;
    int		endian;
    int		width;
    int		height;
}	t_texture;

typedef struct s_textures
{
    t_texture	north;
    t_texture	south;
    t_texture	east;
    t_texture	west;
}	t_textures;

#endif
