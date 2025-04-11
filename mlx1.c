/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roo <roo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:24:13 by roo               #+#    #+#             */
/*   Updated: 2025/04/11 16:09:53 by roo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initiation_mlx(t_maps *var_map, t_mlx *var_mlx)
{
	void	*mlx;
	void	*mlx_window;
	
	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, var_map->map_w * 64, var_map->map_h * 64, "Bienvenido");
	var_mlx->xpm_water = mlx_xpm_file_to_image(mlx, "./textures/water.xpm", &var_map->map_w, &var_map->map_h);
	var_mlx->xpm_stone = mlx_xpm_file_to_image(mlx, "./textures/stone.xpm", &var_map->map_w, &var_map->map_h);
	var_mlx->xpm_player = mlx_xpm_file_to_image(mlx, "./textures/player.xpm", &var_map->map_w, &var_map->map_h);
	var_mlx->xpm_colecc = mlx_xpm_file_to_image(mlx, "./textures/colecc.xpm", &var_map->map_w, &var_map->map_h);
	var_mlx->xpm_exit = mlx_xpm_file_to_image(mlx, "./textures/exit.xpm", &var_map->map_w, &var_map->map_h);
	put_xpm(var_map, var_mlx, mlx, mlx_window);
	mlx_key_hook(mlx_window, press_keys, &var_mlx);
	mlx_destroy_window(mlx, mlx_window);
	mlx_destroy_image(mlx, var_mlx->xpm_water);
	mlx_destroy_image(mlx, var_mlx->xpm_stone);
	mlx_destroy_image(mlx, var_mlx->xpm_player);
	mlx_destroy_image(mlx, var_mlx->xpm_colecc);
	mlx_destroy_image(mlx, var_mlx->xpm_exit);
}

void	put_xpm(t_maps *var_map, t_mlx *var_mlx, void *mlx, void *mlx_window)
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
				mlx_put_image_to_window(mlx, mlx_window, var_mlx->xpm_water, j * 64, i *64);
			else if (var_map->map[i][j] == '1')
				mlx_put_image_to_window(mlx, mlx_window, var_mlx->xpm_stone, j * 64, i *64);
			else if (var_map->map[i][j] == 'P')
				mlx_put_image_to_window(mlx, mlx_window, var_mlx->xpm_player, j * 64, i *64);
			else if (var_map->map[i][j] == 'E')
				mlx_put_image_to_window(mlx, mlx_window, var_mlx->xpm_exit, j * 64, i *64);
			else if (var_map->map[i][j] == 'C')
				mlx_put_image_to_window(mlx, mlx_window, var_mlx->xpm_colecc, j * 64, i *64);
			j++;
		}
		i++;
	}
	mlx_loop(mlx);
	return ;
}
//mlx_put_image_to_window(mlx, mlx_window, var_mlx->xpm_player, var_map->col_player * 64, var_map->row_player *64);