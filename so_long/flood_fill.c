/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhosgor <fhosgor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:26:38 by fhosgor           #+#    #+#             */
/*   Updated: 2024/01/14 18:15:30 by fhosgor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_openablefd(char *str)
{
	int	i;

	i = open(str, O_RDONLY);
	if (i < 0)
		exit(1);
}

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
	get_map_copy(solong, solong->map_name);
	fill(solong, solong->player_x, solong->player_y);
	while (solong->map_copy[++y])
	{
		x = -1;
		while (solong->map_copy[y][++x])
		{
			if (ft_strchar("EC", solong->map_copy[y][x]))
			{
				i = 0;
				while (solong->map_copy[i])
				{
					free (solong->map_copy[i]);
					i++;
				}
				free (solong->map_copy);
				ft_error(solong, 'm');
			}
		}
	}
}

void	ft_error(t_map *solong, char c)
{
	if (c == 'm')
		ft_printf("Map Error!");
	else if (c == 't')
		ft_printf("Texture Error!");
	map_free(solong);
	exit(1);
}

void	map_free(t_map *solong)
{
	int	i;

	i = 0;
	while (i < solong->mapy)
	{
		free (solong->map[i]);
		i++;
	}
	free(solong->map);
}
