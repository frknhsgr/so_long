/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhosgor <fhosgor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:07:57 by fhosgor           #+#    #+#             */
/*   Updated: 2024/01/09 19:12:57 by fhosgor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	ft_error(t_map *solong, char *str)
{
	int	i;

	i = 0;
	ft_printf("%s", str);
	while (solong->map[i])
	{
		if (solong->map[i] != NULL)
			free (solong->map[i]);
		i++;
	}
	if (solong->map)
		free (solong->map);
	system ("leaks a.out");
	exit(1);
}

void	map_checker(t_map *solong)
{
	char	**map_check;
	int		x;
	int		y;

	y = -1;
	map_check = solong->map;
	if (!solong->map[0])
		ft_error(solong, "Map didn't creat!");
	while (map_check[++y])
	{
		x = -1;
		while (map_check[y][++x])
		{
			if ((y == 0 || y == solong->mapy -1) && map_check[y][x] != '1')
				ft_error(solong, "Edges of map isn't wall!");
			else if ((x == 0 || x == solong->mapx -1) && map_check[y][x] != '1')
				ft_error(solong, "Edges of map isn't wall!");
			else if (!ft_strchar("10PEC", map_check[y][x]))
				ft_error(solong, "Map has got invalied character!");
		}
		if (x != solong->mapx)
			ft_error(solong, "Map isn't rectangle");
	}
}

void	count_objects(t_map *solong)
{
	int	x;
	int	y;

	y = -1;
	solong->p_count = 0;
	solong->c_count = 0;
	solong->e_count = 0;
	while (solong->map[++y])
	{
		x = -1;
		while (solong->map[y][++x])
		{
			if (solong->map[y][x] == 'P')
				solong->p_count += 1;
			else if (solong->map[y][x] == 'E')
				solong->e_count += 1;
			else if (solong->map[y][x] == 'C')
				solong->c_count += 1;
		}
	}
}

void	check_objects(t_map *solong)
{
	count_objects(solong);
	if (solong->p_count != 1)
		ft_error(solong, "Invalied number of player!");
	else if (solong->e_count != 1)
		ft_error(solong, "Invalied number of exit!");
	else if (solong->c_count < 1)
		ft_error(solong, "Invalied number of coin!");
}
