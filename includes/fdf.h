/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 09:52:20 by meskelin          #+#    #+#             */
/*   Updated: 2023/04/24 18:35:33 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"

#ifndef WIN_WIDTH
# define WIN_WIDTH 700
#endif

#ifndef WIN_HEIGHT
# define WIN_HEIGHT 700
#endif

typedef struct s_vector
{
	int				x;
	int				y;
	int				z;
	struct s_vector	*next;
}	t_vector;

typedef struct s_dimensions
{
	int	width;
	int	lenght;
}	t_dimensions;

typedef	struct s_map_data
{
	t_dimensions	*dimensions;
	t_vector		*vectors;
}	t_map_data;

typedef	struct s_img_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img_data;

typedef	struct s_mlx
{
	void		*mlx;
	void		*window;
	t_img_data	*img;
	t_map_data	*map;
}	t_mlx;

// COMMON
void			exit_failure(void);
void			exit_success(t_mlx **mlx);

// MLX
t_mlx			*init_mlx_win();

// IMG
t_img_data		*init_img_data(t_mlx **mlx);
void			put_pixel(t_img_data **img, int x, int y, int color);

// LIST
t_vector		*lstnew(int x, int y, int z);
void			lstclear(t_vector **vectors);
void			lstadd(t_vector **vectors, t_vector *new);
int				lstsize(t_vector *vectors);
t_vector		*lstlast(t_vector **vectors);
t_vector		*lstadd_to_vectors(t_vector **vectors, int x, int y, int z);

// MAP
t_vector		*new_vector(int x, int z, int y);
t_vector		*subtract_vector(t_vector *v1, t_vector *v2);
t_vector		*addition_vector(t_vector *v1, t_vector *v2);
t_dimensions	*new_dimensions(int width, int length);
t_map_data		*new_map_data(t_vector **vectors, t_dimensions **dimensions);
t_map_data		*parse_map(int fd);

// FILE
int				get_fd(char *filename);

void			run_fdf(char *input);

#endif
