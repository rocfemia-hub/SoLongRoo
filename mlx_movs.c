/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_movs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roo <roo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:24:13 by roo               #+#    #+#             */
/*   Updated: 2025/04/16 17:17:39 by roo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	initiation_mlx(t_maps *var_map, t_mlx *var_mlx)
{
	var_mlx->mlx_ptr = mlx_init();
	var_mlx->win_ptr = mlx_new_window(var_mlx->mlx_ptr, var_map->map_w * 64,
			var_map->map_h * 64, "so_long");
	var_mlx->xpm_water = mlx_xpm_file_to_image(var_mlx->mlx_ptr,
			"./textures/water.xpm", &var_map->map_w, &var_map->map_h);
	var_mlx->xpm_stone = mlx_xpm_file_to_image(var_mlx->mlx_ptr,
			"./textures/stone.xpm", &var_map->map_w, &var_map->map_h);
	var_mlx->xpm_izplayer = mlx_xpm_file_to_image(var_mlx->mlx_ptr,
			"./textures/izplayer.xpm", &var_map->map_w, &var_map->map_h);
	var_mlx->xpm_dplayer = mlx_xpm_file_to_image(var_mlx->mlx_ptr,
			"./textures/dplayer.xpm", &var_map->map_w, &var_map->map_h);
	var_mlx->xpm_colecc = mlx_xpm_file_to_image(var_mlx->mlx_ptr,
			"./textures/colecc.xpm", &var_map->map_w, &var_map->map_h);
	var_mlx->xpm_exit = mlx_xpm_file_to_image(var_mlx->mlx_ptr,
			"./textures/exit.xpm", &var_map->map_w, &var_map->map_h);
	if (!var_mlx->xpm_water || !var_mlx->xpm_stone || !var_mlx->xpm_izplayer
		|| !var_mlx->xpm_dplayer || !var_mlx->xpm_colecc || !var_mlx->xpm_exit)
		return (-1);
	var_mlx->xpm_player = var_mlx->xpm_dplayer;
	put_xpm(var_map, var_mlx, 0, 0);
	mlx_hook(var_mlx->win_ptr, KeyPress, KeyPressMask, &press_keys, var_mlx);
	mlx_hook(var_mlx->win_ptr, 17, 0, close_game, var_mlx);
	return (0);
}

void	put_xpm(t_maps *var_map, t_mlx *var_mlx, int i, int j)
{
	while (var_map->map[i])
	{
		j = 0;
		while (var_map->map[i][j])
		{
			if (i == var_map->row_player && j == var_map->col_player)
				mlx_put_image_to_window(var_mlx->mlx_ptr, var_mlx->win_ptr,
					var_mlx->xpm_player, j * 64, i * 64);
			else if (var_map->map[i][j] == '0')
				mlx_put_image_to_window(var_mlx->mlx_ptr, var_mlx->win_ptr,
					var_mlx->xpm_water, j * 64, i * 64);
			else if (var_map->map[i][j] == '1')
				mlx_put_image_to_window(var_mlx->mlx_ptr, var_mlx->win_ptr,
					var_mlx->xpm_stone, j * 64, i * 64);
			else if (var_map->map[i][j] == 'E')
				mlx_put_image_to_window(var_mlx->mlx_ptr, var_mlx->win_ptr,
					var_mlx->xpm_exit, j * 64, i * 64);
			else if (var_map->map[i][j] == 'C')
				mlx_put_image_to_window(var_mlx->mlx_ptr, var_mlx->win_ptr,
					var_mlx->xpm_colecc, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

int	press_keys(int keycode, t_mlx *var_mlx)
{
	char	next_tile;

	if (keycodes(keycode, var_mlx) == -1)
		return (0);
	next_tile = var_mlx->var_map2->map[var_mlx->next_row][var_mlx->next_col];
	if (var_mlx->var_map2->map[var_mlx->next_row][var_mlx->next_col] == 'E'
		&& var_mlx->var_map2->total_colecc == 0)
		close_game(var_mlx);
	if (var_mlx->var_map2->map[var_mlx->next_row][var_mlx->next_col] == 'C')
	{
		var_mlx->var_map2->map[var_mlx->next_row][var_mlx->next_col] = '0';
		var_mlx->var_map2->total_colecc--;
	}
	if (next_tile == '1')
		return (0);
	if (keycode == 119 || keycode == 97 || keycode == 115 || keycode == 100)
	{
		var_mlx->movs = var_mlx->movs + 1;
		ft_printf("Movimiento: %d\n", var_mlx->movs);
	}
	var_mlx->var_map2->row_player = var_mlx->next_row;
	var_mlx->var_map2->col_player = var_mlx->next_col;
	put_xpm(var_mlx->var_map2, var_mlx, 0, 0);
	return (0);
}

int	keycodes(int keycode, t_mlx *var_mlx)
{
	var_mlx->next_row = var_mlx->var_map2->row_player;
	var_mlx->next_col = var_mlx->var_map2->col_player;
	if (var_mlx->var_map2->map[var_mlx->next_row][var_mlx->next_col] == 'P')
		var_mlx->var_map2->map[var_mlx->next_row][var_mlx->next_col] = '0';
	if (keycode == 119)
		var_mlx->next_row--;
	else if (keycode == 97)
	{
		var_mlx->next_col--;
		var_mlx->xpm_player = var_mlx->xpm_izplayer;
	}
	else if (keycode == 115)
		var_mlx->next_row++;
	else if (keycode == 100)
	{
		var_mlx->next_col++;
		var_mlx->xpm_player = var_mlx->xpm_dplayer;
	}
	else if (keycode == 65307)
		close_game(var_mlx);
	if (var_mlx->next_row < 0 || var_mlx->next_row >= var_mlx->var_map2->map_h
		|| var_mlx->next_col >= var_mlx->var_map2->map_w
		|| var_mlx->next_col < 0)
		return (-1);
	return (0);
}

int	close_game(t_mlx *var_mlx)
{
	if (var_mlx->mlx_ptr && var_mlx->win_ptr)
		mlx_destroy_window(var_mlx->mlx_ptr, var_mlx->win_ptr);
	if (var_mlx->xpm_water)
		mlx_destroy_image(var_mlx->mlx_ptr, var_mlx->xpm_water);
	if (var_mlx->xpm_stone)
		mlx_destroy_image(var_mlx->mlx_ptr, var_mlx->xpm_stone);
	if (var_mlx->xpm_dplayer)
		mlx_destroy_image(var_mlx->mlx_ptr, var_mlx->xpm_dplayer);
	if (var_mlx->xpm_izplayer)
		mlx_destroy_image(var_mlx->mlx_ptr, var_mlx->xpm_izplayer);
	if (var_mlx->xpm_colecc)
		mlx_destroy_image(var_mlx->mlx_ptr, var_mlx->xpm_colecc);
	if (var_mlx->xpm_exit)
		mlx_destroy_image(var_mlx->mlx_ptr, var_mlx->xpm_exit);
	if (var_mlx->mlx_ptr)
		mlx_destroy_display(var_mlx->mlx_ptr);
	if (var_mlx->mlx_ptr)
		free(var_mlx->mlx_ptr);
	free_map(var_mlx->var_map2->map);
	free_map(var_mlx->var_map2->map_cpy);
	free(var_mlx->var_map2);
	if (var_mlx)
		free(var_mlx);
	exit (0);
}
