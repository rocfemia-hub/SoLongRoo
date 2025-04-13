/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roo <roo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:00:19 by roo               #+#    #+#             */
/*   Updated: 2025/04/13 06:04:39 by roo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	press_keys(int keycode, t_mlx *var_mlx)
{
	char	next_tile;
	
	var_mlx->next_row = var_mlx->var_map2->row_player;
	var_mlx->next_col = var_mlx->var_map2->col_player;
	if (var_mlx->var_map2->map[var_mlx->next_row][var_mlx->next_col] == 'P')
		var_mlx->var_map2->map[var_mlx->next_row][var_mlx->next_col] = '0';
	if (var_mlx->var_map2->map[var_mlx->next_row][var_mlx->next_col] == 'E' && var_mlx->var_map2->total_colecc == 0)
		exit(0);
	keycodes(keycode, var_mlx);
	if (var_mlx->next_row < 0 || var_mlx->next_row >= var_mlx->var_map2->map_h || var_mlx->next_col < 0 || var_mlx->next_col >= var_mlx->var_map2->map_w)
		return (0);
	next_tile = var_mlx->var_map2->map[var_mlx->next_row][var_mlx->next_col];
	if (var_mlx->var_map2->map[var_mlx->next_row][var_mlx->next_col] == 'C')
	{
		var_mlx->var_map2->map[var_mlx->next_row][var_mlx->next_col] = '0';	
		var_mlx->var_map2->total_colecc--;
	}
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
		ft_printf("%d\n", var_mlx->movs);
	}
	else if (keycode == 65307) //ESC
		exit(0);
	var_mlx->movs = var_mlx->movs + 1;
	return (0);
}
