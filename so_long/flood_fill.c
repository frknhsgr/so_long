/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhosgor <fhosgor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:26:38 by fhosgor           #+#    #+#             */
/*   Updated: 2024/01/13 19:05:10 by fhosgor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill(t_map *solong, int x, int y)
{
	char	**to_fill;

	to_fill = solong->map_copy;
	if (x < 0 || x >= solong->mapx || y < 0 || y >= solong->mapy)
		return ;
	if (to_fill[y][x] == '1' || to_fill[y][x] == 'F')
		return ;
	to_fill[y][x] = 'F';
	fill(solong, x + 1, y);
	fill(solong, x - 1, y);
	fill(solong, x, y + 1);
	fill(solong, x, y - 1);
}

void	flood_fill(t_map *solong)
{
	int	x;
	int	y;
	int	i;

	y = -1;
	fill(solong, solong->player_x, solong->player_y);
	while (solong->map_copy[++y])
	{
		x = -1;
		while (solong->map_copy[y][++x])
		{
			if (ft_strchar("EC", solong->map_copy[y][x]))
				ft_error(solong);
		}
	}
	i = 0;
	while (solong->map_copy[i])
	{
		if (solong->map_copy[i] != NULL)
			free (solong->map_copy[i]);
		i++;
	}
	if (solong->map_copy)
		free (solong->map_copy);
}
