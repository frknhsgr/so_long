/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhosgor <fhosgor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:03:41 by fhosgor           #+#    #+#             */
/*   Updated: 2024/01/09 18:44:20 by fhosgor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include <fcntl.h>

typedef struct s_map
{
	char	**map;
	int		mapx;
	int		mapy;
	int		p_count;
	int		c_count;
	int		e_count;
}	t_map;
void	map_len(t_map *solong, char *mapname);
void	get_map(t_map *solong, char *mapname);
void	map_checker(t_map *solong);
void	count_objects(t_map *solong);
void	check_objects(t_map *solong);
void	ft_error(t_map *solong, char *str);
int		main(int ac, char **av);

#endif