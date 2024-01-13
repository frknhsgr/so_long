/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhosgor <fhosgor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:07:57 by fhosgor           #+#    #+#             */
/*   Updated: 2024/01/13 18:40:35 by fhosgor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_mapname(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (i <= 3)
	{
		ft_printf("Wrong Map Name!");
		exit (1);
	}
	if (str[i] != 'r' || str[i - 1] != 'e' || str[i - 2] != 'b'
		|| str[i - 3] != '.')
	{
		ft_printf("Wrong Map Name!");
		exit (1);
	}
	if (str[i - 4] == '.' || str[i - 4] == '/')
	{
		if (str[i - 5] && str[i - 4] != '/')
			return ;
		ft_printf("Wrong Map Name!");
		exit (1);
	}
}

void	ft_error(t_map *solong)
{
	int	i;

	i = 0;
	ft_printf("Map Error!");
	while (solong->map[i])
	{
		if (solong->map[i] != NULL)
		{
			free (solong->map[i]);
			free (solong->map_copy[i]);
		}
		i++;
	}
	if (solong->map)
	{
		free (solong->map);
		free (solong->map_copy);
	}
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
		ft_error(solong);
	while (map_check[++y])
	{
		x = -1;
		while (map_check[y][++x])
		{
			if ((y == 0 || y == solong->mapy -1) && map_check[y][x] != '1')
				ft_error(solong);
			else if ((x == 0 || x == solong->mapx -1) && map_check[y][x] != '1')
				ft_error(solong);
			else if (!ft_strchar("10PEC", map_check[y][x]))
				ft_error(solong);
		}
		if (x != solong->mapx)
			ft_error(solong);
	}
	check_objects(solong);
}

void	count_objects(t_map *solong)
{
	int	x;
	int	y;

	y = -1;
	while (solong->map[++y])
	{
		x = -1;
		while (solong->map[y][++x])
		{
			if (solong->map[y][x] == 'P')
			{
				solong->p_count += 1;
				solong->player_x = x;
				solong->player_y = y;
			}
			else if (solong->map[y][x] == 'E')
			{
				solong->exit_x = x;
				solong->exit_y = y;
				solong->e_count += 1;
			}
			else if (solong->map[y][x] == 'C')
				solong->c_count += 1;
		}
	}
}

void	check_objects(t_map *solong)
{
	count_objects(solong);
	if (solong->p_count != 1)
		ft_error(solong);
	else if (solong->e_count != 1)
		ft_error(solong);
	else if (solong->c_count < 1)
		ft_error(solong);
	flood_fill(solong);
}
