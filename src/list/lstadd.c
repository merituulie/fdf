/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:17:11 by meskelin          #+#    #+#             */
/*   Updated: 2023/05/18 17:19:36 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	lstadd(t_pixel **pixels, t_pixel *new)
{
	t_pixel	*last;

	last = NULL;
	if (!*pixels)
		pixels = &new;
	else
	{
		last = lstlast(pixels);
		last->next = new;
	}
}
