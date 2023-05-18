/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:20:07 by meskelin          #+#    #+#             */
/*   Updated: 2023/05/18 17:56:40 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	put_pixel(t_img_data **img, double x, double y, int color)
{
	char	*dst;

	dst = (*img)->addr + ((int)y * (*img)->line_length + (int)x
			* ((*img)->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_coord(t_mlx **mlx, t_coord **coords, int row, int column)
{
	// draw the coord itself
	put_pixel(&(*mlx)->img, coords[row][column].x, coords[row][column].y, COLOR);
	if (column < (*mlx)->map->dimensions->width)
	{
		// draw to the next x coordinate

	}
	if (row < (*mlx)->map->dimensions->height)
	{
		// draw to the next y coordinate
	}
}
