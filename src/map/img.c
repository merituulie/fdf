/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:04:49 by meskelin          #+#    #+#             */
/*   Updated: 2023/05/05 11:57:30 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

t_img_data	*init_img_data(t_mlx **mlx)
{
	t_img_data	*new;

	new = (t_img_data *)ft_calloc(1, sizeof(*new));
	if (!new)
		return (NULL);
	new->img = mlx_new_image((*mlx)->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!new->img)
		return (NULL);
	new->addr = mlx_get_data_addr(new->img, &new->bits_per_pixel,
			&new->line_length, &new->endian);
	if (!new->addr)
		return (NULL);
	return (new);
}
