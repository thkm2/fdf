/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiraud <kgiraud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:24:32 by kgiraud           #+#    #+#             */
/*   Updated: 2024/11/29 18:49:31 by kgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_close_window(t_fdf *env)
{
	ft_free_fdf(env);
	exit(0);
	return (0);
}

// Mac
int	ft_controls_hook(int key, t_fdf *env)
{
	printf("%d\n", key);
	if (key == 53)
		ft_close_window(env);
	if (key == 126)
		env->camera->zoom += 2;
	if (key == 125)
		if (env->camera->zoom > 3)
			env->camera->zoom -= 2;
	if (key == 262)
		env->camera->z_height += 1;
	if (key == 260)
		env->camera->z_height -= 1;
	if (key == 124)
		if (env->camera->angle < M_PI / 5.5)
			env->camera->angle += M_PI / 128;
	if (key == 123)
		if (env->camera->angle > M_PI / 12)
			env->camera->angle -= M_PI / 128;
	env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	env->addr = mlx_get_data_addr(env->img, &env->bpp,
			&env->size_line, &env->endian);
	ft_draw(env);
	return (0);
}

void	ft_hook(t_fdf *env)
{
	mlx_hook(env->win, 2, 0, ft_controls_hook, env);
	mlx_hook(env->win, 17, 0, ft_close_window, env);
}
