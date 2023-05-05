/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:14:59 by meskelin          #+#    #+#             */
/*   Updated: 2023/05/05 12:47:36 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
#include "../../libft/libft.h"

// static void	print_parsed(t_pixel **pixels, t_dimensions *dim)
// {
// 	t_pixel	*temp;
// 	int			counter;

// 	printf("Map width %i\n", dim->width);
// 	printf("Map length %i\n", dim->lenght);
// 	printf("Map read:\n");
// 	temp = *pixels;
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

int	get_next_row(t_pixel *pixel)
{
	while (pixel && pixel->next && pixel->y == pixel->next->y)
		pixel = pixel->next;
	if (pixel->next)
		return (pixel->next->y);
	else
		return (INT_MIN);
}

t_map_data	*new_map_data(t_pixel **pixels, t_dimensions **dimensions)
{
	t_map_data	*new;

	new = (t_map_data *)ft_calloc(1, sizeof(*new));
	if (!new)
		return (NULL);
	new->pixels = *pixels;
	new->dimensions = *dimensions;
	return (new);
}
