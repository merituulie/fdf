/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:30:24 by meskelin          #+#    #+#             */
/*   Updated: 2023/05/26 13:29:22 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
#include "../../libft/libft.h"

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
	int			z;
	int			x;
	char		**first;

	x = 0;
	first = line_data;
	while (*line_data)
	{
		z = ft_atoi(*line_data);
		*pixels = lstadd_to_pixels(pixels, x, y, z);
		free(*line_data);
		line_data++;
		x++;
	}
	free(first);
}

static int	handle_row(char *line, t_dimensions **dim, t_pixel **pixels, int y)
{
	char			**line_data;

	line_data = ft_split(line, ' ');
	if (y == 0)
		(*dim)->width = count_width(line_data);
	if (y != 0 && count_width(line_data) != (*dim)->width)
		return (0);
	handle_line(line_data, pixels, y);
	return (1);
}

t_map_data	*parse_map(int fd)
{
	char			*line;
	t_dimensions	*dim;
	t_pixel			*pixels;
	t_map_data		*map;
	int				y;

	pixels = NULL;
	y = 0;
	dim = new_dimensions(0, 0);
	if (!dim)
		exit_failure();
	while (fd != 0)
	{
		line = get_next_line(fd);
		if (!line || line[0] == '\0')
			break ;
		if (!handle_row(line, &dim, &pixels, y))
			break ;
		y++;
		free(line);
	}
	dim->height = y;
	map = new_map_data(&pixels, &dim);
	return (map);
}
