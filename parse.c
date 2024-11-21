/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiraud <kgiraud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:47:02 by kgiraud           #+#    #+#             */
/*   Updated: 2024/11/20 19:22:25 by kgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*parse_map_line(int fd)
{
	
}

char	**parse_map(char *map_file)
{
	int		fd;
	int		i;
	int		checker;
	char	**map;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	i = 0;
	checker = 1;
	map = NULL;
	while (checker)
	{
		map[i] = parse_map_line(fd);
		if (!map[i])
			checker = 0;
		i++;
	}
	
}