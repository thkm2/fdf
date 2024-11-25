/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiraud <kgiraud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:18:33 by kgiraud           #+#    #+#             */
/*   Updated: 2024/11/25 13:13:36 by kgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	return_error(char *s)
{
	perror(s);
	exit(1);
}

int	ft_atoi_hex(const char *s)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	if (s[i] == '0' && (s[i + 1] == 'x' || s[i + 1] == 'x'))
		i += 2;
	while ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'f')
		|| (s[i] >= 'A' && s[i] <= 'F'))
	{
		nb *= 16;
		if (s[i] >= 'a' && s[i] <= 'f')
			nb += s[i] - 87;
		else if (s[i] >= 'A' && s[i] <= 'F')
			nb += s[i] - 55;
		else if (s[i] >= '0' && s[i] <= '9')
			nb += s[i] - '0';
		i++;
	}
	return (nb);
}
