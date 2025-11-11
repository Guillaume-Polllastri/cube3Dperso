/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:50:04 by erpascua          #+#    #+#             */
/*   Updated: 2025/07/04 16:05:28 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*gnl_calloc(size_t count, size_t size)
{
	void	*p;
	char	*str;
	size_t	total_size;

	total_size = count * size;
	if (size && count > 18446744073709551615UL / size)
		return (NULL);
	p = malloc(total_size);
	if (!p)
		return (NULL);
	str = (char *)p;
	while (total_size > 0)
	{
		*str = 0;
		str++;
		total_size--;
	}
	return (p);
}

static char	*read_to_stash(int fd, char *stash)
{
	char		*buf;
	ssize_t		bytes;
	int			found;

	buf = (char *)gnl_calloc(BUFFER_SIZE + 1, 1);
	if (!buf)
		return (free(stash), NULL);
	bytes = 1;
	found = 0;
	while (bytes > 0 && !found)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes > 0)
		{
			found = (ft_strchr(buf, '\n') != NULL);
			stash = gnl_join(stash, buf, bytes);
			if (!stash)
				return (free(buf), NULL);
		}
	}
	free(buf);
	if (bytes < 0 || !stash || !*stash)
		return (free(stash), NULL);
	return (stash);
}

static char	*extract_line(char *stash)
{
	size_t	i;
	size_t	len;
	char	*line;

	if (!stash || stash[0] == '\0')
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		len = i + 1;
	else
		len = i;
	line = (char *)malloc(len + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = stash[i];
		i++;
	}
	line[len] = '\0';
	return (line);
}

static char	*clean_stash(char *stash)
{
	char	*new;
	size_t	i;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\0')
		return (free(stash), NULL);
	if (stash[i + 1] == '\0')
		return (free(stash), NULL);
	new = ft_strdup(stash + i + 1);
	if (!new)
		return (free(stash), NULL);
	return (free(stash), new);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;

	if (fd < 0 || read(0, 0, 0) < 0 || BUFFER_SIZE <= 0)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = read_to_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = clean_stash(stash);
	return (line);
}
