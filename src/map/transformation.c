/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:55:46 by meskelin          #+#    #+#             */
/*   Updated: 2023/05/18 17:53:21 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
#include <math.h>

// todo: remove scale and offset based on the map
static void	transform_iso(t_pixel *pixel, t_coord **coords)
{
	double	x;
	double	y;
	int		altitude;

	altitude = pixel->z / ALTITUDE;
	x = SCALE * ((cos(M_PI / 3) * pixel->x) - (sin(M_PI / 6)
				* pixel->y)) + OFFSET_X;
	y = SCALE / 2 * ((sin(M_PI / 3) * pixel->x) + (cos(M_PI / 6)
				* pixel->y) / 2 - altitude) + OFFSET_Y;
	coords[pixel->y][pixel->x] = (t_coord){x, y};
}

// todo: add scaling and offset based on the map, remove it from transform_iso
void	calculate_transformation(t_map_data **map)
{
	t_pixel	*temp;

	temp = (*map)->pixels;
	while (temp)
	{
		transform_iso(temp, (*map)->transform_map);
		temp = temp->next;
	}
}
