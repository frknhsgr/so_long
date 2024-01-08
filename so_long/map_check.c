/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhosgor <fhosgor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:07:57 by fhosgor           #+#    #+#             */
/*   Updated: 2024/01/08 18:07:13 by fhosgor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	getmap(t_map *map)
{
	int		fd;
	int		i;
	int		j;
	char	*str;

	fd = open("map.ber", O_RDONLY);
	str = get_next_line(fd);
	i = 0;
	while (str)
	{
		i++;
		free (str);
		str = get_next_line(fd);
	}
	map->map = malloc(sizeof(char *) * (i + 1));
	map->mapy = i;
	close (fd);
	j = 0;
	fd = open("map.ber", O_RDONLY);
	while (j < i)
	{
		map->map[j] = get_next_line(fd);
		j++;
	}
	map->mapx = ft_strlen(map->map[0]);
}

int	map_check1(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == '1' || map->map[i][j] == '0' ||
			map->map[i][j] == 'P' || map->map[i][j] == 'C' ||
			map->map[i][j] == 'E')
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	map_check2(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
			j++;
		if (j != map->mapx)
			return (0);
		i++;
	}
	return (1);
}

int	map_check3(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->mapy)
	{
		while (map->map[i][j])
		{
			if (i == 0 || i == map->mapy - 1)
				if (map->map[i][j] != '1')
					return (0);
			if (j == 0 || j == map->mapx - 1)
				if (map->map[i][j] != '1')
					return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}
