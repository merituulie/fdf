/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dimension.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:27:41 by meskelin          #+#    #+#             */
/*   Updated: 2023/05/26 13:21:26 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
#include "../../libft/libft.h"

static void	check_for_farest_coords(t_dimensions **dim, t_coord coord)
{
	if (coord.x < (*dim)->leftest_x)
		(*dim)->leftest_x = coord.x;
	if (coord.x > (*dim)->rightest_x)
		(*dim)->rightest_x = coord.x;
	if (coord.y < (*dim)->lowest_y)
		(*dim)->lowest_y = coord.y;
	if (coord.y > (*dim)->highest_y)
		(*dim)->highest_y = coord.y;
}

void	find_relative_dimensions(t_mlx **mlx)
{
	int	row;
	int	column;

	row = 0;
	column = 0;
	while (row < (*mlx)->map->dimensions->height - 1)
	{
		while (column < (*mlx)->map->dimensions->width - 1)
		{
			check_for_farest_coords(&(*mlx)->map->dimensions,
				(*mlx)->map->coords[row][column]);
			column++;
		}
		row++;
	}
}

t_dimensions	*new_dimensions(int width, int height)
{
	t_dimensions	*new;

	new = (t_dimensions *)ft_calloc(1, sizeof(*new));
	if (!new)
		return (NULL);
	new->width = width;
	new->height = height;
	new->highest_y = INT_MIN;
	new->lowest_y = INT_MAX;
	new->leftest_x = INT_MAX;
	new->rightest_x = INT_MIN;
	new->offset_x = WIN_WIDTH / 2;
	new->offset_y = WIN_HEIGHT / 4;
	return (new);
}
