/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:30:24 by meskelin          #+#    #+#             */
/*   Updated: 2023/05/05 13:59:40 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
#include "../../libft/libft.h"
#include <stdio.h>

static int	count_width(char **line)
{
	int	count;

	count = 0;
	while (line[count])
		count++;
	return (count);
}

static void	handle_line(char **line_data, t_pixel **pixels, int y)
{
	int		z;
	int		x;
	char	**first;

	x = WIN_WIDTH / 4;
	first = line_data;
	while (*line_data)
	{
		z = ft_atoi(*line_data);
		*pixels = lstadd_to_pixels(pixels, x, y, z);
		free(*line_data);
		line_data++;
		x += SCALE;
	}
	free(first);
}

static void	handle_row(char *line, t_dimensions **dim, t_pixel **pixels, int y)
{
	char			**line_data;
	char			**first;

	line_data = ft_split(line, ' ');
	first = line_data;
	if (y == 1)
		(*dim)->width = count_width(line_data);
	handle_line(line_data, pixels, y);
}

// static void	print_parsed(t_pixel **pixels, t_dimensions *dim)
// {
// 	t_pixel	*temp;
// 	int			counter;

// 	printf("Map width %i\n", dim->width);
// 	printf("Map length %i\n", dim->pixel);
// 	printf("Map read:\n");
// 	temp = *pixels;
// 	counter = dim->width;
// 	while (dim->pixel >= 1)
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
// 		dim->pixel--;
// 	}
// }

t_map_data	*parse_map(int fd)
{
	char			*line;
	t_dimensions	*dim;
	t_pixel			*pixels;
	t_map_data		*map;
	int				y;

	pixels = NULL;
	y = WIN_HEIGHT / 4;
	dim = new_dimensions(0, 0);
	while (fd != 0)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		handle_row(line, &dim, &pixels, y);
		y += (SCALE / 2);
		free(line);
	}
	dim->height = y;
	map = new_map_data(&pixels, &dim);
	return (map);
}
