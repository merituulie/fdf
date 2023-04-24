/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:14:59 by meskelin          #+#    #+#             */
/*   Updated: 2023/04/24 18:40:35 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
#include "../../libft/libft.h"
#include <stdio.h>

// static void	print_parsed(t_vector **vectors, t_dimensions *dim)
// {
// 	t_vector	*temp;
// 	int			counter;

// 	printf("Map width %i\n", dim->width);
// 	printf("Map length %i\n", dim->lenght);
// 	printf("Map read:\n");
// 	temp = *vectors;
// 	counter = dim->width;
// 	while (dim->lenght >= 1)
// 	{
// 		while (dim->width >= 1)
// 		{
// 			if (temp->z == 0)
// 				printf("0");
// 			printf("%i", temp->z);
// 			temp = temp->next;
// 			dim->width--;
// 		}
// 		printf("\n");
// 		dim->width = counter;
// 		dim->lenght--;
// 	}
// }

t_map_data	*new_map_data(t_vector **vectors, t_dimensions **dimensions)
{
	t_map_data	*new;

	new = (t_map_data *)ft_calloc(1, sizeof(*new));
	if (!new)
		return (NULL);
	new->vectors = *vectors;
	new->dimensions = *dimensions;
	return (new);
}
