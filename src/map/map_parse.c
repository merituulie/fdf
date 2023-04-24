/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:30:24 by meskelin          #+#    #+#             */
/*   Updated: 2023/04/24 18:42:46 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
#include "../../libft/libft.h"
#include <stdio.h>

static int	count_width(char **line)
{
	int count;

	count = 0;
	while(line[count])
		count++;
	return (count);
}

static void	handle_line(char **line_data, t_vector **vectors, int y)
{
	int		z;
	int		x;
	char	**first;

	x = 0;
	first = line_data;
	while (*line_data)
	{
		z = ft_atoi(*line_data);
		*vectors = lstadd_to_vectors(vectors, x, y, z);
		free(*line_data);
		line_data++;
		x++;
	}
	free(first);
}

static void	handle_row(char *line, t_dimensions **dim, t_vector **vectors, int y)
{
	char			**line_data;
	char			**first;

	line_data = ft_split(line, ' ');
	first = line_data;
	if (y == 0)
		(*dim)->width = count_width(line_data);
	handle_line(line_data, vectors, y);
}

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

t_map_data	*parse_map(int fd)
{
	char			*line;
	t_dimensions	*dim;
	t_vector		*vectors;
	t_map_data		*map;
	int				y;

	vectors = NULL;
	y = 0;
	dim = new_dimensions(0, 0);
	while (fd != 0)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		handle_row(line, &dim, &vectors, y);
		y++;
		free(line);
	}
	dim->lenght = y;
	map = new_map_data(&vectors, &dim);
	return (map);
}
