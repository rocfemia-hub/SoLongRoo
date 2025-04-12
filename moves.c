/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roo <roo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:00:19 by roo               #+#    #+#             */
/*   Updated: 2025/04/13 00:33:59 by roo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	press_keys(int keycode, t_mlx *var_mlx)
{
	int		next_row;
	int		next_col;
	char	next_tile;
	
	next_row = var_mlx->var_map2->row_player;
	next_col = var_mlx->var_map2->col_player;
	if (keycode == 119) //W
	{
		next_row--;
		var_mlx->var_map2->movs = var_mlx->var_map2->movs + 1;
		ft_printf("%d\n", var_mlx->var_map2->movs);
	}
	else if (keycode == 97) //A
	{
		next_col--;
		var_mlx->var_map2->movs = var_mlx->var_map2->movs + 1;
		ft_printf("%d\n", var_mlx->var_map2->movs);
	}
	else if (keycode == 115) //S
	{
		next_row++;
		var_mlx->var_map2->movs = var_mlx->var_map2->movs + 1;
		ft_printf("%d\n", var_mlx->var_map2->movs);
	}
	else if (keycode == 100) //D
	{
		next_col++;
		var_mlx->var_map2->movs = var_mlx->var_map2->movs + 1;
		ft_printf("%d\n", var_mlx->var_map2->movs);
	}
	else if (keycode == 65307) //ESC
		exit(0);
	//validar
	if (next_row < 0 || next_row >= var_mlx->var_map2->map_h || next_col < 0 || next_col >= var_mlx->var_map2->map_w)
		return (0);
	next_tile = var_mlx->var_map2->map[next_row][next_col];
	//if (var_mlx->var_map2->map[next_row][next_col] == 'P')
	//	var_mlx->var_map2->map[next_row][next_col] = '0';	
	if (var_mlx->var_map2->map[next_row][next_col] == 'C')
	{
		var_mlx->var_map2->map[next_row][next_col] = '0';	
		var_mlx->var_map2->total_colecc--;
	}
	//evitar si son muros
	if (next_tile == '1')
		return (0);
	//Actualizar posición
	var_mlx->var_map2->row_player = next_row;
	var_mlx->var_map2->col_player = next_col;
	//Redibujar el mapa
	put_xpm(var_mlx->var_map2, var_mlx);
	return (0);
}
