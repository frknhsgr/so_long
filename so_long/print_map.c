/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhosgor <fhosgor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:50:45 by fhosgor           #+#    #+#             */
/*   Updated: 2024/01/13 19:15:18 by fhosgor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	assigment_img(t_map *solong)
{
	int	x;
	int	y;

	solong->player = mlx_xpm_file_to_image(solong->mlx, "img/player.xpm", \
	&x, &y);
	solong->coin = mlx_xpm_file_to_image(solong->mlx, "img/coin.xpm", &x, &y);
	solong->ground = mlx_xpm_file_to_image(solong->mlx, "img/ground.xpm", \
	&x, &y);
	solong->exit = mlx_xpm_file_to_image(solong->mlx, "img/exit.xpm", &x, &y);
	solong->wall = mlx_xpm_file_to_image(solong->mlx, "img/wall.xpm", &x, &y);
	solong->p_on_e = mlx_xpm_file_to_image(solong->mlx, "img/p_on_e.xpm", \
	&x, &y);
}

void	print_map2(t_map *solong, char c, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window(solong->mlx, solong->win, \
		solong->wall, x * 64, y * 64);
	else if (c == '0')
		mlx_put_image_to_window(solong->mlx, solong->win, \
		solong->ground, x * 64, y * 64);
	else if (c == 'P')
	{
		if (solong->exit_x == solong->player_x && \
		solong->exit_y == solong->player_y)
			mlx_put_image_to_window(solong->mlx, solong->win, \
			solong->p_on_e, x * 64, y * 64);
		else
			mlx_put_image_to_window(solong->mlx, solong->win, \
			solong->player, x * 64, y * 64);
	}
	else if (c == 'E')
		mlx_put_image_to_window(solong->mlx, solong->win, \
		solong->exit, x * 64, y * 64);
	else if (c == 'C')
		mlx_put_image_to_window(solong->mlx, solong->win, \
		solong->coin, x * 64, y * 64);
}

void	print_map1(t_map *solong)
{
	int	x;
	int	y;

	y = -1;
	while (solong->map[++y])
	{
		x = -1;
		while (solong->map[y][++x])
		{
			if (solong->map[y][x] == '1')
				print_map2(solong, '1', x, y);
			else if (solong->map[y][x] == '0')
				print_map2(solong, '0', x, y);
			else if (solong->map[y][x] == 'P')
				print_map2(solong, 'P', x, y);
			else if (solong->map[y][x] == 'E')
				print_map2(solong, 'E', x, y);
			else if (solong->map[y][x] == 'C')
				print_map2(solong, 'C', x, y);
		}
	}
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
