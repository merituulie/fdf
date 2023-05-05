/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:22:58 by meskelin          #+#    #+#             */
/*   Updated: 2023/05/05 12:02:13 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../../libft/libft.h"
#include <stdio.h>

void	put_pixels(t_mlx **mlx)
{
	t_pixel		*vector;

	vector = (*mlx)->map->pixels;
	while (vector && vector->next)
	{
		draw_vector(mlx, vector);
		vector = vector->next;
	}
}

void	init_fdf(int fd, t_mlx **mlx)
{
	t_map_data	*map;

	map = parse_map(fd);
	if (close(fd) == -1)
		exit_failure();
	(*mlx) = init_mlx_win();
	if (!mlx)
		exit_failure();
	(*mlx)->map = map;
	(*mlx)->img = init_img_data(mlx);
	if (!(*mlx)->img)
		exit_failure();
}

void	run(char *filename)
{
	int			fd;
	t_mlx		*mlx;

	mlx = NULL;
	fd = get_fd(filename);
	init_fdf(fd, &mlx);
	put_pixels(&mlx);
	mlx_hook(mlx->window, 2, 1, key_hook, &mlx);
	mlx_hook(mlx->window, 17, 1, on_destroy, &mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->img, 0, 0);
	mlx_loop(mlx->mlx);
}
