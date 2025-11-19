/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 18:29:09 by gpollast          #+#    #+#             */
/*   Updated: 2025/11/19 11:32:11 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

double	ft_abs(double value)
{
	if (value < 0)
		value *= -1;
	return (value);
}

double	min_double(double a, double b)
{
	if (a <= b)
		return (a);
	return (b);
}