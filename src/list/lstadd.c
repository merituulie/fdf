/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:17:11 by meskelin          #+#    #+#             */
/*   Updated: 2023/04/24 17:09:17 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
#include <stdio.h>

void	lstadd(t_vector **vectors, t_vector *new)
{
	t_vector	*last;

	last = NULL;
	if (!*vectors)
		vectors = &new;
	else
	{
		last = lstlast(vectors);
		last->next = new;
	}
}
