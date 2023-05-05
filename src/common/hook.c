/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:07:40 by meskelin          #+#    #+#             */
/*   Updated: 2023/04/28 13:08:28 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

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
