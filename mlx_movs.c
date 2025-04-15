/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_movs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roo <roo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:24:13 by roo               #+#    #+#             */
/*   Updated: 2025/04/15 17:28:05 by roo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initiation_mlx(t_maps *var_map, t_mlx *var_mlx)
{
	var_mlx->mlx_ptr = mlx_init();
	var_mlx->win_ptr = mlx_new_window(var_mlx->mlx_ptr, var_map->map_w * 64, var_map->map_h * 64, "so_long");
	var_mlx->xpm_water = mlx_xpm_file_to_image(var_mlx->mlx_ptr, "./textures/water.xpm", &var_map->map_w, &var_map->map_h);
	var_mlx->xpm_stone = mlx_xpm_file_to_image(var_mlx->mlx_ptr, "./textures/stone.xpm", &var_map->map_w, &var_map->map_h);
	var_mlx->xpm_izplayer = mlx_xpm_file_to_image(var_mlx->mlx_ptr, "./textures/izplayer.xpm", &var_map->map_w, &var_map->map_h);
	var_mlx->xpm_dplayer = mlx_xpm_file_to_image(var_mlx->mlx_ptr, "./textures/dplayer.xpm", &var_map->map_w, &var_map->map_h);
	var_mlx->xpm_player = var_mlx->xpm_dplayer;
	var_mlx->xpm_colecc = mlx_xpm_file_to_image(var_mlx->mlx_ptr, "./textures/colecc.xpm", &var_map->map_w, &var_map->map_h);
	var_mlx->xpm_exit = mlx_xpm_file_to_image(var_mlx->mlx_ptr, "./textures/exit.xpm", &var_map->map_w, &var_map->map_h);
	put_xpm(var_map, var_mlx);
	mlx_hook(var_mlx->win_ptr, KeyPress, KeyPressMask, &press_keys, var_mlx);
	mlx_hook(var_mlx->win_ptr, 17, 0, close_game, var_mlx);
}

void	put_xpm(t_maps *var_map, t_mlx *var_mlx)
{
	int i;
	int	j;
	
	i = 0;
	while (var_map->map[i])
	{
		j = 0;
		while (var_map->map[i][j])
		{
			if (i == var_map->row_player && j == var_map->col_player)
				mlx_put_image_to_window(var_mlx->mlx_ptr, var_mlx->win_ptr, var_mlx->xpm_player, j * 64, i *64);
			else if (var_map->map[i][j] == '0')
				mlx_put_image_to_window(var_mlx->mlx_ptr, var_mlx->win_ptr, var_mlx->xpm_water, j * 64, i *64);
			else if (var_map->map[i][j] == '1')
				mlx_put_image_to_window(var_mlx->mlx_ptr, var_mlx->win_ptr, var_mlx->xpm_stone, j * 64, i *64);
			else if (var_map->map[i][j] == 'E')
				mlx_put_image_to_window(var_mlx->mlx_ptr, var_mlx->win_ptr, var_mlx->xpm_exit, j * 64, i *64);
			else if (var_map->map[i][j] == 'C')
				mlx_put_image_to_window(var_mlx->mlx_ptr, var_mlx->win_ptr, var_mlx->xpm_colecc, j * 64, i *64);
			j++;
		}
		i++;
	}
	return ;
}

int	press_keys(int keycode, t_mlx *var_mlx)
{
	char	next_tile;
	
	var_mlx->next_row = var_mlx->var_map2->row_player;
	var_mlx->next_col = var_mlx->var_map2->col_player;
	if (var_mlx->var_map2->map[var_mlx->next_row][var_mlx->next_col] == 'P')
		var_mlx->var_map2->map[var_mlx->next_row][var_mlx->next_col] = '0';
	keycodes(keycode, var_mlx);
	if (var_mlx->next_row < 0 || var_mlx->next_row >= var_mlx->var_map2->map_h || var_mlx->next_col < 0 || var_mlx->next_col >= var_mlx->var_map2->map_w)
		return (0);
	next_tile = var_mlx->var_map2->map[var_mlx->next_row][var_mlx->next_col];
	if (var_mlx->var_map2->map[var_mlx->next_row][var_mlx->next_col] == 'E' && var_mlx->var_map2->total_colecc == 0)
		close_game(var_mlx);
	if (var_mlx->var_map2->map[var_mlx->next_row][var_mlx->next_col] == 'C')
	{
		var_mlx->var_map2->map[var_mlx->next_row][var_mlx->next_col] = '0';	
		var_mlx->var_map2->total_colecc--;
	}
	if (next_tile != '1' && (var_mlx->next_row != var_mlx->var_map2->row_player || var_mlx->next_col != var_mlx->var_map2->col_player))
		var_mlx->movs = var_mlx->movs + 1;
	if (next_tile == '1')
		return (0);
	var_mlx->var_map2->row_player = var_mlx->next_row;
	var_mlx->var_map2->col_player = var_mlx->next_col;
	put_xpm(var_mlx->var_map2, var_mlx);
	return (0);
}

int		keycodes(int keycode, t_mlx *var_mlx)
{
	if (keycode == 119) //W
	{
		var_mlx->next_row--;
		ft_printf("%d\n", var_mlx->movs);
	}
	else if (keycode == 97) //A
	{
		var_mlx->next_col--;
		var_mlx->xpm_player = var_mlx->xpm_izplayer;
		ft_printf("%d\n", var_mlx->movs);
	}
	else if (keycode == 115) //S
	{
		var_mlx->next_row++;
		ft_printf("%d\n", var_mlx->movs);
	}
	else if (keycode == 100) //D
	{
		var_mlx->next_col++;
		var_mlx->xpm_player = var_mlx->xpm_dplayer;
		ft_printf("%d\n", var_mlx->movs);
	}
	else if (keycode == 65307) //ESC
		close_game(var_mlx);
	return (0);
}

int	close_game(t_mlx *var_mlx)
{
	mlx_destroy_window(var_mlx->mlx_ptr, var_mlx->win_ptr);
	mlx_destroy_image(var_mlx->mlx_ptr, var_mlx->xpm_water);
	mlx_destroy_image(var_mlx->mlx_ptr, var_mlx->xpm_stone);
	mlx_destroy_image(var_mlx->mlx_ptr, var_mlx->xpm_dplayer);
	mlx_destroy_image(var_mlx->mlx_ptr, var_mlx->xpm_izplayer);
	mlx_destroy_image(var_mlx->mlx_ptr, var_mlx->xpm_colecc);
	mlx_destroy_image(var_mlx->mlx_ptr, var_mlx->xpm_exit);
	mlx_destroy_display(var_mlx->mlx_ptr);
	free(var_mlx->mlx_ptr);
	exit (0);
}

//var_mlx->movs = var_mlx->movs + 1;