/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:55:46 by meskelin          #+#    #+#             */
/*   Updated: 2023/05/26 14:34:30 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
#include <math.h>

static void	transform_iso(t_pixel *pixel, t_mlx **mlx)
{
	double	x;
	double	y;

	x = (*mlx)->map->dimensions->scale * ((cos(M_PI / 3) * pixel->x)
			- (sin(M_PI / 6) * pixel->y)) + (*mlx)->map->dimensions->offset_x;
	y = (*mlx)->map->dimensions->scale / 2 * ((sin(M_PI / 3) * pixel->x)
			+ (cos(M_PI / 6) * pixel->y) / 2 - (pixel->z * ALTITUDE))
		+ (*mlx)->map->dimensions->offset_y;
	(*mlx)->map->coords[pixel->y][pixel->x] = (t_coord){x, y};
}

void	transform_relative(t_mlx **mlx)
{
	int	row;
	int	column;
	int	move_right;
	int	move_down;

	row = 0;
	column = 0;
	move_right = (WIN_WIDTH / 2) - ft_lerp((*mlx)->map->dimensions->leftest_x,
			(*mlx)->map->dimensions->rightest_x);
	move_down = (WIN_HEIGHT / 2) - ft_lerp((*mlx)->map->dimensions->lowest_y,
			(*mlx)->map->dimensions->highest_y);
	while (row < (*mlx)->map->dimensions->height)
	{
		while (column < (*mlx)->map->dimensions->width)
		{
			if (move_right != 0)
				(*mlx)->map->coords[row][column].x += move_right / 2;
			if (move_down != 0)
				(*mlx)->map->coords[row][column].y += move_down / 2;
			column++;
		}
		column = 0;
		row++;
	}
}

void	calculate_transformation(t_mlx **mlx)
{
	t_pixel	*temp;

	temp = (*mlx)->map->pixels;
	while (temp)
	{
		transform_iso(temp, mlx);
		temp = temp->next;
	}
}
