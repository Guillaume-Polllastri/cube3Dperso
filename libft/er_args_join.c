/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   er_args_join.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ep <ep@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:32:36 by erpascua          #+#    #+#             */
/*   Updated: 2025/07/15 00:38:56 by ep               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	buf_len(char **av)
{
	size_t	len;
	size_t	i;
	size_t	j;

	len = 0;
	i = 0;
	j = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			len++;
			j++;
		}
		len++;
		i++;
	}
	return (len);
}

static size_t	append_arg(const char *src, char *dst, size_t a)
{
	size_t	j;

	j = 0;
	while (src[j])
	{
		if (is_space(src[j]))
			j++;
		else if (src[j] == '-' || src[j] == '+')
		{
			if (src[j] == '-')
				dst[a++] = src[j];
			j++;
		}
		else if (ft_isdigit(src[j]))
		{
			dst[a++] = src[j];
			if (!ft_isdigit(src[j + 1]) && src[j + 1] != '\0')
				dst[a++] = ' ';
			j++;
		}
		else
			j++;
	}
	dst[a++] = ' ';
	return (a);
}

char	*args_join(char **av)
{
	char	*r;
	size_t	i;
	size_t	a;

	r = malloc(buf_len(av) + 1);
	if (!r)
		return (NULL);
	i = 0;
	a = 0;
	while (av[i])
	{
		a = append_arg(av[i], r, a);
		i++;
	}
	r[a] = '\0';
	return (r);
}
