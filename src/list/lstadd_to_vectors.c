/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd_to_vectors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:49:04 by meskelin          #+#    #+#             */
/*   Updated: 2023/04/24 17:05:13 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
#include <stdio.h>

t_vector	*lstadd_to_vectors(t_vector **vectors, int x, int y, int z)
{
	t_vector	*new;

	new = lstnew(x, y, z);
	if (!*vectors)
		vectors = &new;
	else
		lstadd(vectors, new);
	return (*vectors);
}
