/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roo <roo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 02:19:33 by roo               #+#    #+#             */
/*   Updated: 2025/03/19 02:42:26 by roo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_char(char **map, char c)
{
	int i;
	int j;
	int count;
	
	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	count_str(char **map, t_maps *var_map)
{
	int i;

	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[i - 1]))
			return (-1);
		i++;
	}
	return (0);
}

int coords_xy(char **map, int c, t_maps *var_map)
{
	int tmp_row;
	int tmp_col;
	
	tmp_row = 0;
	while (map[tmp_row])
	{
		tmp_col = 0;
		while (map[tmp_row][tmp_col])
		{
			if (map[tmp_row][tmp_col] == c)
			{
				var_map->row_player = tmp_row;
				var_map->col_player = tmp_col;
				return (0);
			}
			tmp_col++;
		}
		tmp_row++;
	}
	return (-1);
}
