/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiraud <kgiraud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:07:20 by kgiraud           #+#    #+#             */
/*   Updated: 2024/11/25 23:01:00 by kgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_transform(int *x, int *y)
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
	*x += shift_x;
	*y += shift_y;
}

void	ft_put_pixel_to_image(t_fdf *env, int x, int y, int color)
{
	int		position;
	char	*dst;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	ft_transform(&x, &y);
	position = (y * env->size_line) + (x * (env->bpp / 8));
	dst = env->addr + position;
	*(unsigned int *)dst = color;
}

void	ft_draw_line(t_fdf *env, int x_0, int y_0, int x_1, int y_1, int color)
{
	t_bresenham b;
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
	int	x2;
	int	y2;

	y = 0;
	while (y < env->map->height && y + 1< env->map->height)
	{
		x = 0;
		while (x < env->map->width && x + 1 < env->map->width)
		{
			x2 = x + 1;
			y2 = y + 1;
			ft_transform(&x, &y);
			ft_transform(&x2, &y2);
			ft_draw_line(env, x, y, x2, y, env->map->points[y][x].z);
			ft_draw_line(env, x, y, x, y2, env->map->points[y][x].z);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}