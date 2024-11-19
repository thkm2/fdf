/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiraud <kgiraud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:49:56 by kgiraud           #+#    #+#             */
/*   Updated: 2024/11/19 11:17:57 by kgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

int close_window(int keycode, void *param)
{
    (void)keycode;
    (void)param;
    exit(0); // Quitte proprement le programme
    return (0);
}

int main()
{
    void *mlx;          // Pointeur pour la connexion à la MiniLibX
    void *win;          // Pointeur pour la fenêtre

    // Initialisation de la connexion à la MiniLibX
    mlx = mlx_init();
    if (!mlx)
        return (1); // Vérifie si l'initialisation a échoué

    // Création de la fenêtre (640x480 est la taille par exemple)
    win = mlx_new_window(mlx, 800, 600, "Ma Fenetre MiniLibX");
    if (!win)
        return (1); // Vérifie si la création de la fenêtre a échoué

    // Définir un hook pour fermer la fenêtre en appuyant sur la croix
    mlx_hook(win, 17, 0, close_window, 0);

    // Boucle principale pour maintenir la fenêtre ouverte
    mlx_loop(mlx);

    return (0);
}
