/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhosgor <fhosgor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:03:41 by fhosgor           #+#    #+#             */
/*   Updated: 2024/01/14 18:14:16 by fhosgor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include "mlx/mlx.h"
# include <fcntl.h>

typedef struct s_map
{
	char	**map;
	char	**map_copy;
	char	*map_name;
	void	*mlx;
	void	*win;
	void	*player;
	void	*coin;
	void	*ground;
	void	*exit;
	void	*wall;
	void	*p_on_e;
	int		mapx;
	int		mapy;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		p_count;
	int		c_count;
	int		e_count;
	int		move_count;
	int		collected_c;
}	t_map;
void	assigment_int(t_map *solong);
void	map_len(t_map *solong, char *mapname);
void	get_map(t_map *solong, char *mapname);
void	get_map_copy(t_map *solong, char *mapname);

void	map_checker(t_map *solong);
void	check_mapname(char *str);
void	check_openablefd(char *str);
void	count_objects(t_map *solong);
void	check_objects(t_map *solong);
void	ft_error(t_map *solong, char c);
void	fill(t_map *solong, int x, int y);
void	flood_fill(t_map *solong);
void	check_texture(t_map *solong);

void	assigment_img(t_map *solong);
void	print_map1(t_map *solong);
void	print_map2(t_map *solong, char c, int x, int y);
void	map_free(t_map *solong);

void	ft_up(t_map *solong, int x, int y);
void	ft_left(t_map *solong, int x, int y);
void	ft_right(t_map *solong, int x, int y);
void	ft_down(t_map *solong, int x, int y);
void	ft_close(t_map *solong);
int		ft_keyboard(int keycode, t_map *solong);

#endif