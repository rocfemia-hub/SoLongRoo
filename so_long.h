/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roo <roo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:20:05 by roo               #+#    #+#             */
/*   Updated: 2025/03/26 03:04:24 by roo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./Helicopter/libft.h"
# include "./minilibx-linux/mlx_int.h"
# include "./minilibx-linux/mlx.h"

typedef struct maps
{
	char	**map;
	char	**map_cpy;
	int		lines_map;
	int		row_player;
	int		col_player;
	
}	t_maps;

// MAIN

int control_argv(int argc, char **argv, t_maps *var_map);

// MAP

int		cpy_map(char **argv, t_maps *var_map);
int 	control_map(t_maps *var_map);
void	flood_fill(t_maps *var_map, int	row, int col);

//MAP UTILS

int		count_char(char **map, char c);
int		count_str(char **map);
int		wall_check(char **map, t_maps *var_map);
void	coords_xy(char **map, char c, t_maps *var_map);

#endif