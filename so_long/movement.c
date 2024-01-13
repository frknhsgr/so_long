/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhosgor <fhosgor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 18:16:39 by fhosgor           #+#    #+#             */
/*   Updated: 2024/01/13 19:16:18 by fhosgor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_forward(t_map *solong, int x, int y)
{
	solong->move_count += 1;
	ft_printf("%d\n", solong->move_count);
	if (solong->map[y][x] == '0' || solong->map[y - 1][x] == 'C')
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
			map_free(solong);
			mlx_destroy_window(solong->mlx, solong->win);
			exit(1);
		}
		solong->map[y][x] = '0';
		solong->map[y - 1][x] = 'P';
		solong->player_y -= 1;
	}
}

int	ft_keyboard(int keycode, t_map *solong)
{
	if (keycode == 13)
		ft_forward(solong, solong->player_x, solong->player_y);
	print_map1(solong);
	return (1);
}
//w = 13
//a = 0
//s = 1
//d = 2
//esc = 53 