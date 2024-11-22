/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiraud <kgiraud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:04:47 by kgiraud           #+#    #+#             */
/*   Updated: 2024/11/22 15:30:29 by kgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_get_width(char *s)
{
	char	**split;
	int		width;

	width = 0;
	split = ft_split(s, ' ');
	if (!split)
		return_error("Split error");
	while (split[width])
	{
		free(split[width]);
		width++;
	}
	free(split);
	return (width);
}

void	ft_get_map_dimensions(char *file_name, int *width, int *height)
{
	int		fd;
	char	*line;
	int		tmp_width;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return_error("Creation fd error");
	while (get_next_line(fd, &line) > 0)
	{
		tmp_width = ft_get_width(line);
		if (*width == 0)
			*width = tmp_width;
		else if (*width != tmp_width)
			return_error("Irregular width map error");
		(*height)++;
		free(line);
	}
	close(fd);
}

t_map	*ft_map_init(char *file_name)
{
	int		i;
	t_map	*map;

	i = 0;
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return_error("Malloc struct map error");
	ft_get_map_dimensions(file_name, &map->width, &map->height);
	map->points = (t_point **)malloc(sizeof(t_point *) * (map->height));
	if (!map->points)
		return_error("Malloc map *points error");
	while (i < map->height)
	{
		map->points[i] = (t_point *)malloc(sizeof(t_point) * map->width);
		if (!map->points[i])
			return_error("Malloc map **points error");
		i++;
	}
	return (map);
}

t_fdf	*ft_env_init(char *file_name)
{
	t_fdf	*env;

	env = (t_fdf *)malloc(sizeof(t_fdf));
	if (!env)
		return_error("Malloc env error");
	env->mlx = mlx_init();
	if (!env->mlx)
		return_error("Mlx init error");
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, file_name);
	if (!env->win)
		return_error("Mlx new window error");
	env->map = ft_map_init(file_name);
	return (env);
}
