/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:16:14 by meskelin          #+#    #+#             */
/*   Updated: 2023/05/26 13:30:11 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
#include "../../libft/libft.h"

static t_bres	*init_bres(t_coord *from, t_coord *to)
{
	t_bres	*bres;

	bres = (t_bres *)ft_calloc(1, sizeof(*bres));
	if (!bres)
		return (NULL);
	bres->slope_x = -1;
	if (from->x < to->x)
		bres->slope_x = 1;
	bres->slope_y = -1;
	if (from->y < to->y)
		bres->slope_y = 1;
	bres->dir_x = ft_abs((int)to->x - (int)from->x);
	bres->dir_y = -ft_abs((int)to->y - (int)from->y);
	bres->error = bres->dir_x + bres->dir_y;
	bres->x = (int)from->x;
	bres->y = (int)from->y;
	return (bres);
}

static int	recalc_x(t_bres **bres, t_coord *to)
{
	if ((*bres)->x == (int)to->x)
		return (0);
	(*bres)->error = (*bres)->error + (*bres)->dir_y;
	(*bres)->x += (*bres)->slope_x;
	return (1);
}

static int	recalc_y(t_bres **bres, t_coord *to)
{
	if ((*bres)->y == (int)to->y)
		return (0);
	(*bres)->error = (*bres)->error + (*bres)->dir_x;
	(*bres)->y += (*bres)->slope_y;
	return (1);
}

void	draw_bresenham(t_mlx **mlx, t_coord *from, t_coord *to)
{
	t_bres	*bres;

	bres = init_bres(from, to);
	if (!bres)
		exit_failure();
	while (1)
	{
		if (0 > bres->x || bres->x > WIN_WIDTH
			|| 0 > bres->y || bres->y > WIN_HEIGHT)
			break ;
		put_pixel(&(*mlx)->img, bres->x, bres->y, COLOR);
		if (bres->x == (int)to->x && bres->y == (int)to->y)
			break ;
		bres->errort2 = 2 * bres->error;
		if (bres->errort2 >= bres->dir_y)
			if (!recalc_x(&bres, to))
				break ;
		if (bres->errort2 <= bres->dir_x)
			if (!recalc_y(&bres, to))
				break ;
	}
	free(bres);
}
