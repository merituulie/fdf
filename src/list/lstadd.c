/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:17:11 by meskelin          #+#    #+#             */
/*   Updated: 2023/04/28 12:51:31 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
#include <stdio.h>

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
