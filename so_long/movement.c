/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhosgor <fhosgor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 18:16:39 by fhosgor           #+#    #+#             */
/*   Updated: 2024/01/14 16:21:58 by fhosgor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_up(t_map *solong, int x, int y)
{
	solong->move_count += 1;
	ft_printf("Step = %d\n", solong->move_count);
	if (solong->map[y - 1][x] == '0' || solong->map[y - 1][x] == 'C')
	{
		if (solong->map[y - 1][x] == 'C')
			solong->collected_c += 1;
		solong->map[y][x] = '0';
		solong->map[y - 1][x] = 'P';
		solong->player_y -= 1;
	}
	else if (solong->map[y - 1][x] == 'E')
	{
		if (solong->collected_c == solong->c_count)
		{
			ft_printf("You did it!");
			map_free(solong);
			mlx_destroy_window(solong->mlx, solong->win);
			exit(1);
		}
		solong->map[y][x] = '0';
		solong->map[y - 1][x] = 'P';
		solong->player_y -= 1;
	}
}

void	ft_left(t_map *solong, int x, int y)
{
	solong->move_count += 1;
	ft_printf("Step = %d\n", solong->move_count);
	if (solong->map[y][x - 1] == '0' || solong->map[y][x - 1] == 'C')
	{
		if (solong->map[y][x - 1] == 'C')
			solong->collected_c += 1;
		solong->map[y][x] = '0';
		solong->map[y][x - 1] = 'P';
		solong->player_x -= 1;
	}
	else if (solong->map[y][x - 1] == 'E')
	{
		if (solong->collected_c == solong->c_count)
		{
			ft_printf("You did it!");
			map_free(solong);
			mlx_destroy_window(solong->mlx, solong->win);
			exit(1);
		}
		solong->map[y][x] = '0';
		solong->map[y][x - 1] = 'P';
		solong->player_x -= 1;
	}
}

void	ft_right(t_map *solong, int x, int y)
{
	solong->move_count += 1;
	ft_printf("Step = %d\n", solong->move_count);
	if (solong->map[y][x + 1] == '0' || solong->map[y][x + 1] == 'C')
	{
		if (solong->map[y][x + 1] == 'C')
			solong->collected_c += 1;
		solong->map[y][x] = '0';
		solong->map[y][x + 1] = 'P';
		solong->player_x += 1;
	}
	else if (solong->map[y][x + 1] == 'E')
	{
		if (solong->collected_c == solong->c_count)
		{
			ft_printf("You did it!");
			map_free(solong);
			mlx_destroy_window(solong->mlx, solong->win);
			exit(1);
		}
		solong->map[y][x] = '0';
		solong->map[y][x + 1] = 'P';
		solong->player_x += 1;
	}
}

void	ft_down(t_map *solong, int x, int y)
{
	solong->move_count += 1;
	ft_printf("Step = %d\n", solong->move_count);
	if (solong->map[y + 1][x] == '0' || solong->map[y + 1][x] == 'C')
	{
		if (solong->map[y + 1][x] == 'C')
			solong->collected_c += 1;
		solong->map[y][x] = '0';
		solong->map[y + 1][x] = 'P';
		solong->player_y += 1;
	}
	else if (solong->map[y + 1][x] == 'E')
	{
		if (solong->collected_c == solong->c_count)
		{
			ft_printf("You did it!");
			map_free(solong);
			mlx_destroy_window(solong->mlx, solong->win);
			exit(1);
		}
		solong->map[y][x] = '0';
		solong->map[y + 1][x] = 'P';
		solong->player_y += 1;
	}
}

int	ft_keyboard(int keycode, t_map *solong)
{
	int	x;
	int	y;

	x = solong->player_x;
	y = solong->player_y;
	if (keycode == 13 && solong->map[y - 1][x] != '1')
		ft_up(solong, solong->player_x, solong->player_y);
	else if (keycode == 0 && solong->map[y][x - 1] != '1')
		ft_left(solong, solong->player_x, solong->player_y);
	else if (keycode == 2 && solong->map[y][x + 1] != '1')
		ft_right(solong, solong->player_x, solong->player_y);
	else if (keycode == 1 && solong->map[y + 1][x] != '1')
		ft_down(solong, solong->player_x, solong->player_y);
	else if (keycode == 53)
		ft_close(solong);
	print_map1(solong);
	return (1);
}
