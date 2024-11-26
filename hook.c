/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiraud <kgiraud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:24:32 by kgiraud           #+#    #+#             */
/*   Updated: 2024/11/26 16:48:40 by kgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_controls_hook(int key)
{
	printf("%d\n", key);
	if (key == 6530)
		exit(0);
	return (0);
}

void	ft_hook(t_fdf *env)
{
	mlx_hook(env->win, 2, 0, ft_controls_hook, env);
}