/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_fdf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:22:58 by meskelin          #+#    #+#             */
/*   Updated: 2023/04/24 18:43:27 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../../libft/libft.h"
#include <stdio.h>

void	put_pixels(t_img_data *img)
{
	int			x1;
	int			y1;
	int			x2;
	int			y2;
	int			x3;
	int			y3;
	int			x4;
	int			y4;

	x1 = 0;
	y1 = 0;
	x2 = WIN_WIDTH;
	y2 = 0;
	x3 = 0;
	y3 = WIN_HEIGHT / 2;
	x4 = WIN_WIDTH / 2;
	y4 = 0;
	while (x1 <= WIN_WIDTH && y1 <= WIN_HEIGHT)
	{
		put_pixel(&img, x2, y2, 0x00FF0000);
		put_pixel(&img, x1, y1, 0x00FF0000);
		put_pixel(&img, x3, y3, 0x00FF0000);
		put_pixel(&img, x4, y4, 0x00FF0000);
		x1++;
		y1++;
		x2--;
		y2++;
		x3++;
		y4++;
	}
}

int	key_hook(int keycode, t_mlx **mlx)
{
	if (keycode == 53)
		exit_success(mlx);
	return (0);
}

int	on_destroy(t_mlx **mlx)
{
	exit_success(mlx);
	return (0);
}

void	run_fdf(char *filename)
{
	int			fd;
	t_mlx		*mlx;
	t_map_data	*map;

	mlx = NULL;
	fd = get_fd(filename);
	map = parse_map(fd);
	if (close(fd) == -1)
		exit_failure();
	mlx = init_mlx_win();
	if (!mlx)
		exit_failure();
	mlx->map = map;
	mlx->img = init_img_data(&mlx);
	if (!mlx->img)
		exit_failure();
	put_pixels(mlx->img);
	mlx_hook(mlx->window, 2, 1, key_hook, &mlx);
	mlx_hook(mlx->window, 17, 1, on_destroy, &mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->img, 0, 0);
	mlx_loop(mlx->mlx);
}
