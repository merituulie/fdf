/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:04:52 by meskelin          #+#    #+#             */
/*   Updated: 2023/04/21 15:00:07 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	exit_success(t_mlx **mlx)
{
	if (mlx)
		mlx_destroy_window((*mlx)->mlx, (*mlx)->window);
	exit(EXIT_SUCCESS);
}

void	exit_failure(void)
{
	exit(EXIT_FAILURE);
}
