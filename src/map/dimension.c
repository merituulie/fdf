/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dimension.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:27:41 by meskelin          #+#    #+#             */
/*   Updated: 2023/04/21 11:56:31 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

t_dimensions	*new_dimensions(int width, int length)
{
	t_dimensions *new;

	new = (t_dimensions *)ft_calloc(1, sizeof(*new));
	if (!new)
		return (NULL);
	new->width = width;
	new->lenght = length;
	return (new);
}
