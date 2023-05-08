/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:20:07 by meskelin          #+#    #+#             */
/*   Updated: 2023/05/08 12:32:11 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	put_pixel(t_img_data **img, int x, int y, int color)
{
	char	*dst;

	dst = (*img)->addr + (y * (*img)->line_length + x
			* ((*img)->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_vector(t_mlx **mlx, t_pixel *vector)
{
	int	x_coord;
	int	y_coord;

	x_coord = vector->x;
	while (vector->x <= vector->next->x)
	{
		put_pixel(&(*mlx)->img, vector->x, vector->y, 0x00FF0000);
		vector->x++;
	}
	vector->x = x_coord;
	y_coord = get_next_row(vector);
	while (vector->y <= y_coord)
	{
		put_pixel(&(*mlx)->img, vector->x, vector->y, 0x00FF0000);
		vector->y++;
	}
}
