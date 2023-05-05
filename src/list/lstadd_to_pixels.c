/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd_to_pixels.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:49:04 by meskelin          #+#    #+#             */
/*   Updated: 2023/04/28 12:49:24 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
#include <stdio.h>

t_pixel	*lstadd_to_pixels(t_pixel **pixels, int x, int y, int z)
{
	t_pixel	*new;

	new = lstnew(x, y, z);
	if (!*pixels)
		pixels = &new;
	else
		lstadd(pixels, new);
	return (*pixels);
}
