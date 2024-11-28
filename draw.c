/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiraud <kgiraud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:07:20 by kgiraud           #+#    #+#             */
/*   Updated: 2024/11/28 14:56:32 by kgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_transform(t_fdf *env, int *x, int *y, int z)
{
	int	scale;
	int	old_x;
	int	old_y;

	scale = env->camera->zoom;
	*x *= scale;
	*y *= scale;
	z *= env->camera->z_height;
	*x -= (env->map->width * scale) / 2;
	*y -= (env->map->height * scale) / 2;
	old_x = *x;
	old_y = *y;
	*x = (old_x - old_y) * cos(M_PI / 6);
	*y = (old_x + old_y) * sin(M_PI / 6) - z;
	*x += WIDTH / 2;
	*y += HEIGHT / 2;
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
	
	ft_transform(env, &x_0, &y_0, env->map->points[y_0][x_0].z);
	ft_transform(env, &x_1, &y_1, env->map->points[y_1][x_1].z);
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
	while (y < env->map->height)
	{
		x = 0;
		while (x < env->map->width)
		{
			if (x + 1 < env->map->width)
				ft_draw_line(env, x, y, x + 1, y, env->map->points[y][x].color);
			if (y + 1< env->map->height)
				ft_draw_line(env, x, y, x, y + 1, env->map->points[y][x].color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}
