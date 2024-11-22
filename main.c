/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiraud <kgiraud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:49:56 by kgiraud           #+#    #+#             */
/*   Updated: 2024/11/22 14:39:51 by kgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void print_map(t_map *map)
{
	int x = 0;
	int y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			ft_printf("%d ", map->points[y][x].z);
			x++;
		}
		ft_printf("\n");
		y++;
	}
}

int	main(int ac, char **av)
{
	t_fdf	*env;

	if (ac != 2)
		return (0);
	env = ft_env_init(av[1]);
	ft_parse_map(av[1], env->map);
	//print_map(env->map);
	//mlx_pixel_put(env->mlx, env->win, (WIDTH / 2), (HEIGHT / 2), 0xFFFFFF);
	draw_map_2d(env->map, env->mlx, env->win);
	mlx_loop(env->mlx);
	return (0);
}
