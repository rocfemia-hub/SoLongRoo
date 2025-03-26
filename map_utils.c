/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roo <roo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 02:19:33 by roo               #+#    #+#             */
/*   Updated: 2025/03/26 03:04:15 by roo              ###   ########.fr       */
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

int	count_str(char **map)
{
	int i;

	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[0]) != ft_strlen(map[i]))
			return (-1);
		i++;
	}
	return (0);
}

int	wall_check(char **map, t_maps *var_map)
{
	int i;
	size_t j;
	
	i = 0;
	while (map[i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != 'C')
				return (-1);
			if ((i == 0 && map[i][j] != '1') || (i == var_map->lines_map - 1 && map[i][j] != '1'))
				return (-1);
			if (j == 0 && map[i][j] != '1')
				return (-1);
			if (j == ft_strlen(map[0]) - 1 && map[i][j] != '1')
				return (-1);
		}
		i++;
	}
	return (0);
}

void coords_xy(char **map, char c, t_maps *var_map)
{
	int tmp_row; //fila
	int tmp_col; //columna
	
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
			}
			tmp_col++;
		}
		tmp_row++;
	}
}
