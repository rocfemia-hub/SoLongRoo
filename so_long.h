/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roo <roo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:20:05 by roo               #+#    #+#             */
/*   Updated: 2025/04/13 03:48:48 by roo              ###   ########.fr       */
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
	int		map_w;
	int		map_h;
	int		total_colecc;
	
}	t_maps;

typedef	struct mlx
{
	void	*xpm_player;
	void	*xpm_water;
	void	*xpm_stone;
	void	*xpm_colecc;
	void	*xpm_exit;
	void	*mlx_ptr;
	void	*win_ptr;
	int		next_row;
	int		next_col;
	int		movs;
	t_maps	*var_map2;
	
}	t_mlx;


// MAIN

int control_argv(int argc, char **argv, t_maps *var_map);

// MAP

int		cpy_map(char **argv, t_maps *var_map);
int 	control_map(t_maps *var_map);
void	flood_fill(t_maps *var_map, int	row, int col);

// MAP UTILS

int		count_char(t_maps *var_map, char c);
int		count_str(char **map);
int		wall_check(char **map, t_maps *var_map);
void	coords_xy(char **map, char c, t_maps *var_map);

// MLX

void	initiation_mlx(t_maps *var_map, t_mlx *var_xpm);
void	put_xpm(t_maps *var_map, t_mlx *var_mlx);

//MOVES

int		press_keys(int keycode, t_mlx *var_mlx);
int		keycodes(int keycode, t_mlx *var_mlx);

#endif