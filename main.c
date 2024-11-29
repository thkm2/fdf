/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiraud <kgiraud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:25:56 by kgiraud           #+#    #+#             */
/*   Updated: 2024/11/29 18:11:36 by kgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_fdf	*env;

	if (ac != 2)
	{
		ft_putendl_fd("Usage: ./fdf <map.fdf>", 2);
		return (1);
	}
	env = ft_env_init(av[1]);
	ft_parse_map(av[1], env->map);
	ft_hook(env);
	ft_draw(env);
	mlx_loop(env->mlx);
	return (0);
}
