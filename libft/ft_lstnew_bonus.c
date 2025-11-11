/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:40:47 by erpascua          #+#    #+#             */
/*   Updated: 2025/05/06 15:52:54 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_t;

	new_t = (t_list *) malloc (sizeof(t_list));
	if (!new_t)
		return (NULL);
	new_t -> content = content;
	new_t -> next = NULL;
	return (new_t);
}
