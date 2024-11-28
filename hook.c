/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiraud <kgiraud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:24:32 by kgiraud           #+#    #+#             */
/*   Updated: 2024/11/28 14:49:48 by kgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_controls_hook(int key, t_fdf *env)
{
	printf("%d\n", key);
	if (key == 53)
		exit(0);
	if (key == 126)
		env->camera->zoom += 2;
	if (key == 125)
		if (env->camera->zoom > 3)
			env->camera->zoom -= 2;
	if (key == 47)
		env->camera->z_height += 2;
	if (key == 44)
		env->camera->z_height -= 2;
	env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	env->addr = mlx_get_data_addr(env->img, &env->bpp, &env->size_line, &env->endian);
	ft_draw(env);
	return (0);
}

void	ft_hook(t_fdf *env)
{
	mlx_key_hook(env->win, ft_controls_hook, env);
}