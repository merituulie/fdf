/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:20:07 by meskelin          #+#    #+#             */
/*   Updated: 2023/05/26 13:21:22 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	put_pixel(t_img_data **img, double x, double y, int color)
{
	char	*dst;

	if (x <= 0 || x >= WIN_WIDTH || y <= 0 || y >= WIN_HEIGHT)
		return ;
	dst = (*img)->addr + ((int)y * (*img)->line_length + (int)x
			* ((*img)->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void	draw(t_mlx **mlx, t_coord **coords, int row, int column)
{
	put_pixel(&(*mlx)->img, coords[row][column].x,
		coords[row][column].y, COLOR);
	if (column < (*mlx)->map->dimensions->width - 1)
		draw_bresenham(mlx, &coords[row][column + 1], &coords[row][column]);
	if (row < (*mlx)->map->dimensions->height - 1)
		draw_bresenham(mlx, &coords[row + 1][column], &coords[row][column]);
}

void	draw_fdf(t_mlx **mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < (*mlx)->map->dimensions->height)
	{
		while (j < (*mlx)->map->dimensions->width)
		{
			draw(mlx, (*mlx)->map->coords, i, j);
			j++;
		}
		j = 0;
		i++;
	}
}
