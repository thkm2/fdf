/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiraud <kgiraud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:49:56 by kgiraud           #+#    #+#             */
/*   Updated: 2024/11/25 13:15:51 by kgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_fdf	*env;

	if (ac != 2)
		return (0);
	env = ft_env_init(av[1]);
	ft_parse_map(av[1], env->map);
	//mlx_pixel_put(env->mlx, env->win, (WIDTH / 2), (HEIGHT / 2), 0xFFFFFF);
	mlx_loop(env->mlx);
	return (0);
}
