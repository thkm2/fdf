/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiraud <kgiraud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:49:51 by kgiraud           #+#    #+#             */
/*   Updated: 2024/11/21 15:50:02 by kgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx/mlx.h"
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

# include <fcntl.h>
# include <stdio.h>

# define WIDTH 1280
# define HEIGHT 720

# define ESC 53

typedef struct s_map
{
	int	width;
	int height;
}	t_map;

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	t_map	*map;
}	t_fdf;

// init.c
t_fdf	*ft_env_init(char *map_path);

// utils.c
void	return_error(char *s);

#endif