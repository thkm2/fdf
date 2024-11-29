/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiraud <kgiraud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:49:51 by kgiraud           #+#    #+#             */
/*   Updated: 2024/11/29 14:34:51 by kgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx/mlx.h"
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

# include <fcntl.h>
# include <stdio.h>
# include <math.h>

# define WIDTH 1280
# define HEIGHT 720

# define ESC 53

typedef struct s_point
{
	int	z;
	int	color;
}	t_point;

typedef struct s_map
{
	int		width;
	int		height;
	t_point	**points;
}	t_map;

typedef struct s_camera
{
	int		zoom;
	int		z_height;
	double	angle;
}	t_camera;

typedef struct s_fdf
{
	void		*mlx;
	void		*win;
	t_map		*map;
	void		*img;
	char		*addr;
	int			bpp;
	int			size_line;
	int			endian;
	t_camera	*camera;
}	t_fdf;

typedef struct s_bresenham
{
	int	x_distance;
	int	y_distance;
	int	x_direction;
	int	y_direction;
	int	err;
	int	err2;
}	t_bresenham;

// init.c
t_fdf	*ft_env_init(char *map_path);

// utils.c
void	return_error(char *s);
int		ft_atoi_hex(const char *s);
int		ft_abs(int nb);
int		ft_min(int a, int b);

// parse.c
void	ft_parse_map(char *file_name, t_map *map);

// draw.c
void	ft_draw(t_fdf *env);

// hook.c
void	ft_hook(t_fdf *env);

#endif