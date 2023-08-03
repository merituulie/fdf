/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:14:59 by meskelin          #+#    #+#             */
/*   Updated: 2023/05/26 13:17:19 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
#include "../../libft/libft.h"

static t_coord	**new_coords(t_dimensions *dimensions)
{
	int		i;
	t_coord	**coords;

	coords = (t_coord **)ft_calloc(dimensions->height - 1, sizeof(**coords));
	if (!coords)
		return (NULL);
	i = 0;
	while (i < dimensions->height)
	{
		coords[i] = (t_coord *)ft_calloc(dimensions->width, sizeof(**coords));
		i++;
	}
	return (coords);
}

t_map_data	*new_map_data(t_pixel **pixels, t_dimensions **dimensions)
{
	t_map_data	*new;

	new = (t_map_data *)ft_calloc(1, sizeof(*new));
	if (!new)
		return (NULL);
	new->pixels = *pixels;
	new->dimensions = *dimensions;
	new->coords = new_coords(*dimensions);
	new->dimensions->scale = new->dimensions->height
		* new->dimensions->width * SCALE;
	return (new);
}
