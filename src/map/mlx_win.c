/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_win.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:45:28 by meskelin          #+#    #+#             */
/*   Updated: 2023/05/19 17:23:31 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

t_mlx	*init_mlx_win(void)
{
	t_mlx	*new;

	new = (t_mlx *)ft_calloc(1, sizeof(*new));
	if (!new)
		return (NULL);
	new->mlx = mlx_init();
	if (!new->mlx)
		return (NULL);
	new->window = mlx_new_window(new->mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");
	if (!new->window)
		return (NULL);
	return (new);
}
