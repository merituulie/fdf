/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstclear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:53:34 by meskelin          #+#    #+#             */
/*   Updated: 2023/04/28 12:51:31 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	ft_clr_rec(t_pixel *pixel)
{
	if (!pixel)
		return ;
	ft_clr_rec(pixel->next);
	pixel->next = NULL;
	pixel->x = 0;
	pixel->y = 0;
	pixel->z = 0;
	free(pixel);
}

void	lstclear(t_pixel **pixels)
{
	if (!pixels)
		return ;
	ft_clr_rec(*pixels);
	*pixels = NULL;
}
