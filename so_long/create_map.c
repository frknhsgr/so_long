/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhosgor <fhosgor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:10:28 by fhosgor           #+#    #+#             */
/*   Updated: 2024/01/14 17:42:17 by fhosgor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	assigment_int(t_map *solong)
{
	solong->mapx = 0;
	solong->mapy = 0;
	solong->player_y = 0;
	solong->player_x = 0;
	solong->exit_x = 0;
	solong->exit_y = 0;
	solong->c_count = 0;
	solong->e_count = 0;
	solong->p_count = 0;
	solong->move_count = 0;
	solong->collected_c = 0;
}

void	map_len(t_map *solong, char *mapname)
{
	int		fd;
	int		i;
	char	*str;

	fd = open(mapname, O_RDONLY);
	if (fd < 0)
		return ;
	str = get_next_line(fd);
	i = 0;
	solong->mapx = ft_strlen(str);
	while (str)
	{
		i++;
		free(str);
		str = get_next_line(fd);
	}
	solong->mapy = i;
	close(fd);
}

void	get_map(t_map *solong, char *mapname)
{
	int	i;
	int	fd;

	i = 0;
	map_len(solong, mapname);
	solong->map = malloc(sizeof(char *) * (solong->mapy + 1));
	if (!solong->map)
		return ;
	fd = open(mapname, O_RDONLY);
	if (fd < 0)
		return ;
	while (i < solong->mapy)
	{
		solong->map[i] = get_next_line(fd);
		i++;
	}
	solong->map[i] = NULL;
	close (fd);
	solong->map_name = mapname;
	if (solong->mapx > 40 || solong->mapy > 22)
		ft_error(solong, 'm');
	map_checker(solong);
}

void	get_map_copy(t_map *solong, char *mapname)
{
	int	i;
	int	fd;

	i = 0;
	solong->map_copy = malloc(sizeof(char *) * (solong->mapy + 1));
	if (!solong->map_copy)
		return ;
	fd = open(mapname, O_RDONLY);
	if (fd < 0)
		return ;
	while (i < solong->mapy)
	{
		solong->map_copy[i] = get_next_line(fd);
		i++;
	}
	solong->map_copy[i] = NULL;
	close (fd);
}
