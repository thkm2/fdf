/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiraud <kgiraud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:07:20 by kgiraud           #+#    #+#             */
/*   Updated: 2024/11/26 13:37:54 by kgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* void	ft_transform(int *x, int *y)
{
	int	scale;
	int	shift_x;
	int	shift_y;
	int	previous_x;
	int	previous_y;

	scale = 20;
	shift_x = WIDTH / 2;
	shift_y = HEIGHT / 2;
	previous_x = *x;
	previous_y = *y;
	previous_x *= scale;
	previous_y *= scale;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = (previous_x + previous_y) * sin(0.523599);
	*x += shift_x + previous_x;
	*y += shift_y + previous_y;
} */

void	ft_transform(int *x, int *y, int z)
{
	double	scale;
	double	shift_x;
	double	shift_y;
	double	previous_x;
	double	previous_y;
	double	previous_z;
	double	transformed_x;
	double	transformed_y;

	scale = 15.0;
	shift_x = WIDTH / 2.0;
	shift_y = HEIGHT / 2.0;
	previous_x = *x * scale;
	previous_y = *y * scale;
	previous_z = z * scale / 5.0; // Ajustez l'échelle de z si nécessaire

	// Application de la transformation isométrique
	transformed_x = (previous_x - previous_y) * cos(0.523599);
	transformed_y = (previous_x + previous_y) * sin(0.523599) - previous_z;

	// Mise à jour des coordonnées avec décalage
	*x = (int)(transformed_x + shift_x);
	*y = (int)(transformed_y + shift_y);
}

void	ft_put_pixel_to_image(t_fdf *env, int x, int y, int color)
{
	int		position;
	char	*dst;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	position = (y * env->size_line) + (x * (env->bpp / 8));
	dst = env->addr + position;
	*(unsigned int *)dst = color;
}

void	ft_draw_line(t_fdf *env, int x_0, int y_0, int x_1, int y_1, int color)
{
	t_bresenham b;
	
	ft_transform(&x_0, &y_0, env->map->points[y_0][x_0].z);
	ft_transform(&x_1, &y_1, env->map->points[y_1][x_1].z);
	b.x_distance = ft_abs(x_0 - x_1);
	b.y_distance = ft_abs(y_0 - y_1);
	b.x_direction = 1;
	b.y_direction = 1;
	if (x_0 > x_1)
		b.x_direction = -1;
	if (y_0 > y_1)
		b.y_direction = -1;
	b.err = b.x_distance - b.y_distance;
	while (x_0 != x_1 || y_0 != y_1)
	{
		ft_put_pixel_to_image(env, x_0, y_0, color);
		b.err2 = 2 * b.err;
		if (b.err2 > -b.y_distance)
		{
			b.err -= b.y_distance;
			x_0 += b.x_direction;
		}
		if (b.err2 < b.x_distance)
		{
			b.err += b.x_distance;
			y_0 += b.y_direction;
		}
	}
}

void	ft_draw(t_fdf *env)
{
	int	x;
	int	y;

	y = 0;
	while (y < env->map->height && y + 1< env->map->height)
	{
		x = 0;
		while (x < env->map->width && x + 1 < env->map->width)
		{
			ft_draw_line(env, x, y, x + 1, y, env->map->points[y][x].color);
			ft_draw_line(env, x, y, x, y + 1, env->map->points[y][x].color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}

/* void	ft_draw(t_fdf *env)
{
	ft_draw_line(env, 1, HEIGHT / 2 - 300, WIDTH - 1, HEIGHT / 2, ft_atoi_hex("FFFFFF"));
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
} */