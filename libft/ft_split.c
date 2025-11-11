/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:53:47 by erpascua          #+#    #+#             */
/*   Updated: 2025/09/16 16:27:56 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *s, char *charset)
{
	int	i;
	int	in_word;
	int	count;

	i = 0;
	in_word = 0;
	count = 0;
	while (s[i])
	{
		if (!ft_strchr(charset, s[i]) && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (ft_strchr(charset, s[i]))
			in_word = 0;
		i++;
	}
	return (count);
}

static int	get_start(char const *s, char *charset, int sep)
{
	while (s[sep])
	{
		if (!ft_strchr(charset, s[sep]))
			return (sep);
		sep++;
	}
	return (sep);
}

static int	get_sep(char const *s, char *charset, int start)
{
	while (s[start])
	{
		if (ft_strchr(charset, s[start]))
			return (start);
		start++;
	}
	return (start);
}

static char	**free_words(char **res)
{
	int	i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

char	**ft_split(char const *s, char *charset)
{
	char	**res;
	int		words;
	int		i;
	int		start;
	int		sep;

	if (!s)
		return (NULL);
	words = count_word(s, charset);
	res = (char **) ft_calloc(words + 1, sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	start = 0;
	sep = 0;
	while (i < words)
	{
		start = get_start(s, charset, sep);
		sep = get_sep(s, charset, start);
		res[i] = ft_substr(s, start, sep - start);
		if (!res[i])
			return (free_words(res));
		i++;
	}
	return (res);
}
