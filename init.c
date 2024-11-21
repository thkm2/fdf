/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiraud <kgiraud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:04:47 by kgiraud           #+#    #+#             */
/*   Updated: 2024/11/21 15:49:41 by kgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*ft_map_init(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return_error("Malloc struct map error");
	map->width = 0;
	map->height = 0;
	return (map);
}

t_fdf	*ft_env_init(char *map_path)
{
	t_fdf	*env;

	env = (t_fdf *)malloc(sizeof(t_fdf));
	if (!env)
		return_error("Malloc env error");
	env->mlx = mlx_init();
	if (!env->mlx)
		return_error("Mlx init error");
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, map_path);
	if (!env->win)
		return_error("Mlx new window error");
	env->map = ft_map_init();
	return (env);
}
