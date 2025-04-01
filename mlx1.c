/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roo <roo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:24:13 by roo               #+#    #+#             */
/*   Updated: 2025/04/01 20:14:12 by roo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initiation_mlx(t_maps *var_map, t_mlx *var_xpm)
{
	void	*mlx;
	void	*mlx_window;
	
	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, var_map->map_w * 64, var_map->map_h * 64, "Bienvenido");
	var_xpm->xpm_water = mlx_xpm_file_to_image(mlx, "./textures/water.xpm", &var_map->map_w, &var_map->map_h);
	var_xpm->xpm_stone = mlx_xpm_file_to_image(mlx, "./textures/stone.xpm", &var_map->map_w, &var_map->map_h);
	var_xpm->xpm_player = mlx_xpm_file_to_image(mlx, "./textures/player.xpm", &var_map->map_w, &var_map->map_h);
	var_xpm->xpm_colecc = mlx_xpm_file_to_image(mlx, "./textures/colecc.xpm", &var_map->map_w, &var_map->map_h);
	put_player(var_map, var_xpm, mlx, mlx_window);
	mlx_destroy_window(mlx, mlx_window);
	mlx_destroy_image(mlx, var_xpm->xpm_water);
	mlx_destroy_image(mlx, var_xpm->xpm_stone);
	mlx_destroy_image(mlx, var_xpm->xpm_player);
	mlx_destroy_image(mlx, var_xpm->xpm_colecc);
}

void	put_player(t_maps *var_map, t_mlx *var_xpm, void *mlx, void *mlx_window)
{
	mlx_put_image_to_window(mlx, mlx_window, var_xpm->xpm_player, var_map->col_player * 64, var_map->row_player *64);
	mlx_loop(mlx);
	return ;
}