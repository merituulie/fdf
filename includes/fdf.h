/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 09:52:20 by meskelin          #+#    #+#             */
/*   Updated: 2023/05/26 12:11:07 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"

# ifndef WIN_WIDTH
#  define WIN_WIDTH 1920
# endif

# ifndef WIN_HEIGHT
#  define WIN_HEIGHT 1080
# endif

# ifndef COLOR
#  define COLOR 0x00FFFFFF
# endif

# ifndef ALTITUDE
#  define ALTITUDE 3
# endif

# ifndef SCALE
#  define SCALE 0.1
# endif

typedef struct s_pixel
{
	int				x;
	int				y;
	int				z;
	struct s_pixel	*next;
}	t_pixel;

typedef struct s_coord
{
	double	x;
	double	y;
}	t_coord;

typedef struct s_bres
{
	int	slope_x;
	int	slope_y;
	int	dir_x;
	int	dir_y;
	int	error;
	int	errort2;
	int	x;
	int	y;
}	t_bres;

typedef struct s_dimensions
{
	int		width;
	int		height;
	int		leftest_x;
	int		rightest_x;
	int		highest_y;
	int		lowest_y;
	int		offset_x;
	int		offset_y;
	int		scale;
}	t_dimensions;

typedef struct s_map_data
{
	t_dimensions	*dimensions;
	t_pixel			*pixels;
	t_coord			**coords;
}	t_map_data;

typedef struct s_img_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img_data;

typedef struct s_mlx
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
t_mlx			*init_mlx_win(void);

// HOOK
int				key_hook(int keycode, t_mlx **mlx);
int				on_destroy(t_mlx **mlx);

// IMG
t_img_data		*init_img_data(t_mlx **mlx);

// LIST
t_pixel			*lstnew(int x, int y, int z);
void			lstclear(t_pixel **pixels);
void			lstadd(t_pixel **pixels, t_pixel *new);
int				lstsize(t_pixel *pixels);
t_pixel			*lstlast(t_pixel **pixels);
t_pixel			*lstadd_to_pixels(t_pixel **pixels, int x, int y, int z);

// MAP
t_pixel			*new_pixel(int x, int z, int y);
t_dimensions	*new_dimensions(int width, int length);
t_map_data		*new_map_data(t_pixel **pixels, t_dimensions **dimensions);
t_map_data		*parse_map(int fd);

// COORDS AND DRAW
void			put_pixel(t_img_data **img, double x, double y, int color);
void			calculate_transformation(t_mlx **mlx);
void			transform_relative(t_mlx **mlx);
void			find_relative_dimensions(t_mlx **mlx);
void			calculate_relative_dimensions(t_mlx **mlx);
void			draw_fdf(t_mlx **mlx);
void			draw_bresenham(t_mlx **mlx, t_coord *from, t_coord *to);
void			scale(t_mlx **mlx);

// FILE
int				get_fd(char *filename);

void			run(char *input);

#endif
