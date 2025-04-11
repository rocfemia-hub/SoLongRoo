/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roo <roo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:00:19 by roo               #+#    #+#             */
/*   Updated: 2025/04/12 01:30:56 by roo              ###   ########.fr       */
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
	if (keycode == 119)
	{
		next_row--;
		next_tile = var_mlx->var_map2->map[next_row][next_col];
		if (next_tile == '1')
			return (0);
		ft_printf("W presionado\n");
	}
	else if (keycode == 97)
	{
		next_col--;
		next_tile = var_mlx->var_map2->map[next_row][next_col];
		if (next_tile == '1')
			return (0);
		ft_printf("A presionado\n");
	}
	else if (keycode == 115)
	{
		next_row++;
		next_tile = var_mlx->var_map2->map[next_row][next_col];
		if (next_tile == '1')
			return (0);
		ft_printf("S presionado\n");
	}
	else if (keycode == 100)
	{
		next_col++;
		next_tile = var_mlx->var_map2->map[next_row][next_col];
		if (next_tile == '1')
			return (0);
		ft_printf("D presionado\n");
	}
	else if (keycode == 65307)
		exit(0);
	return (0);
}