/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhosgor <fhosgor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:34:19 by fhosgor           #+#    #+#             */
/*   Updated: 2024/01/13 19:09:11 by fhosgor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_map	solong;

	if (ac != 2)
		return (0);
	check_mapname(av[1]);
	assigment_int(&solong);
	get_map(&solong, av[1]);
	solong.mlx = mlx_init();
	solong.win = mlx_new_window(solong.mlx, solong.mapx * 64, \
	solong.mapy * 64, "so_long");
	assigment_img(&solong);
	print_map1(&solong);
	mlx_hook(solong.win, 2, 0, ft_keyboard, &solong);
	//mlx_hook(solong.win,17,0,fonksiyon,solong);//çarpı tuşu için
	mlx_loop(solong.mlx);
}


