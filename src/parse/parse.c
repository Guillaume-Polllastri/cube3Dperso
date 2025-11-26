/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:45:00 by gpollast          #+#    #+#             */
/*   Updated: 2025/11/26 11:26:03 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "cube3d.h"
#include <fcntl.h>

static bool	is_valid_name(char *s)
{
	char	*first_occurence;

	first_occurence = ft_strnstr(s, ".cub", ft_strlen(s));
	if (!first_occurence)
		return (false);
	if (!ft_strcmp(first_occurence, ".cub")
		&& ft_strlen(first_occurence) == ft_strlen(".cub"))
		return (true);
	return (false);
}

static int	fill_map(t_map *map, char *s)
{
	int	fd;
	int	i;

	fd = open(s, O_RDONLY, 0);
	if (fd == -1)
	{
		ft_fprintf(2, "Error: Cannot open file\n");
		return (0);
	}
	map->content = malloc(sizeof(char *) * (map->height + 1));
	if (!map->content)
		return (close(fd), 0);
	i = 0;
	map->content[i] = get_next_line(fd); // TODO securise malloc gnl
	while (map->content[i])
	{
		i++;
		map->content[i] = get_next_line(fd);
	}
	return (1);
}

int	parse(t_game *game, char *s)
{
	if (!is_valid_name(s))
	{
		ft_fprintf(2, "Error extension file must be .cub\n");
		return (0);
	}
	game->map = calloc(1, sizeof(game->map));
	if (!game->map)
		return (0);
	game->map->height = 5;
	game->map->width = 8;
	if (!fill_map(game->map, s))
		return (0);
	return (1);
}
