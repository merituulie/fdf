/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:01:42 by meskelin          #+#    #+#             */
/*   Updated: 2023/04/21 11:56:43 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
#include "../../libft/libft.h"

t_vector	*new_vector(int x, int y, int z)
{
	t_vector	*new;

	new = (t_vector*)ft_calloc(1, sizeof(*new));
	if (!new)
		return (NULL);
	new->x = x;
	new->y = y;
	new->z = z;
	return (new);
}

t_vector	*subtract_vector(t_vector *v1, t_vector *v2)
{
	t_vector	*subtracted;

	subtracted = new_vector((v1->x - v2->x), (v1->y - v2->y), (v1->z - v2->z));
	return (subtracted);
}

t_vector	*addition_vector(t_vector *v1, t_vector *v2)
{
	t_vector	*additioned;

	additioned = new_vector((v1->x + v2->x), (v1->y + v2->y), (v1->z + v2->z));
	return (additioned);
}
