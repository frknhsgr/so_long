/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhosgor <fhosgor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:10:28 by fhosgor           #+#    #+#             */
/*   Updated: 2024/01/09 18:10:50 by fhosgor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	map_len(t_map *solong, char *mapname)
{
	int		fd;
	int		i;
	char	*str;

	fd = open(mapname, O_RDONLY);
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
	while (i < solong->mapy)
	{
		solong->map[i] = get_next_line(fd);
		i++;
	}
	solong->map[i] = NULL;
	close (fd);
}