/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiraud <kgiraud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:47:02 by kgiraud           #+#    #+#             */
/*   Updated: 2024/11/22 13:51:08 by kgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_parse_line(char *line, t_point *row, int width)
{
	int		i;
	char	**split;
	char	*comma;

	i = 0;
	split = ft_split(line, ' ');
	while (i < width)
	{
		row[i].z = ft_atoi(split[i]);
		comma = ft_strchr(line, ',');
		if (comma)
			row[i].color = 1;
		else
			row[i].color = -1;
		free(split[i]);
		i++;
	}
	free(split);
}

void	ft_parse_map(char *file_name, t_map *map)
{
	int		fd;
	char	*line;
	int		row;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return_error("Creation fd error");
	row = 0;
	while (get_next_line(fd, &line) > 0)
	{
		ft_parse_line(line, map->points[row], map->width);
		free(line);
		row++;
	}
	close(fd);
}