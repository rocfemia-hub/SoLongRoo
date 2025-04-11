/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roo <roo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:24:13 by roo               #+#    #+#             */
/*   Updated: 2025/04/11 16:39:57 by roo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initiation_mlx(t_maps *var_map, t_mlx *var_mlx)
{
	var_mlx->mlx_ptr = mlx_init();
	var_mlx->win_ptr = mlx_new_window(var_mlx->mlx_ptr, var_map->map_w * 64, var_map->map_h * 64, "Bienvenido");
	var_mlx->xpm_water = mlx_xpm_file_to_image(var_mlx->mlx_ptr, "./textures/water.xpm", &var_map->map_w, &var_map->map_h);
	var_mlx->xpm_stone = mlx_xpm_file_to_image(var_mlx->mlx_ptr, "./textures/stone.xpm", &var_map->map_w, &var_map->map_h);
	var_mlx->xpm_player = mlx_xpm_file_to_image(var_mlx->mlx_ptr, "./textures/player.xpm", &var_map->map_w, &var_map->map_h);
	var_mlx->xpm_colecc = mlx_xpm_file_to_image(var_mlx->mlx_ptr, "./textures/colecc.xpm", &var_map->map_w, &var_map->map_h);
	var_mlx->xpm_exit = mlx_xpm_file_to_image(var_mlx->mlx_ptr, "./textures/exit.xpm", &var_map->map_w, &var_map->map_h);
	put_xpm(var_map, var_mlx);
	mlx_key_hook(var_mlx->win_ptr, press_keys, &var_mlx);
	//mlx_destroy_window(var_mlx->mlx_ptr, win_ptr);
	//mlx_destroy_image(var_mlx->mlx_ptr, var_mlx->xpm_water);
	//mlx_destroy_image(var_mlx->mlx_ptr, var_mlx->xpm_stone);
	//mlx_destroy_image(var_mlx->mlx_ptr, var_mlx->xpm_player);
	//mlx_destroy_image(var_mlx->mlx_ptr, var_mlx->xpm_colecc);
	//mlx_destroy_image(var_mlx->mlx_ptr, var_mlx->xpm_exit);
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
			if (var_map->map[i][j] == '0')
				mlx_put_image_to_window(var_mlx->mlx_ptr, var_mlx->win_ptr, var_mlx->xpm_water, j * 64, i *64);
			else if (var_map->map[i][j] == '1')
				mlx_put_image_to_window(var_mlx->mlx_ptr, var_mlx->win_ptr, var_mlx->xpm_stone, j * 64, i *64);
			else if (var_map->map[i][j] == 'P')
				mlx_put_image_to_window(var_mlx->mlx_ptr, var_mlx->win_ptr, var_mlx->xpm_player, j * 64, i *64);
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
//mlx_put_image_to_window(mlx, win_ptr, var_mlx->xpm_player, var_map->col_player * 64, var_map->row_player *64);