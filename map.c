/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roo <roo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 02:17:00 by roo               #+#    #+#             */
/*   Updated: 2025/04/01 23:55:39 by roo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	cpy_map(char **argv, t_maps *var_map)
{
	int 	fd;
	int		lines;
	char	*line;
	
	fd = open(argv[1], O_RDWR);
	if (fd == -1)
		return(ft_printf("Error de apertura de archivo 2"), -1);
	line = get_next_line(fd);
	lines = 0;
	while (line)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		var_map->map[lines] = line;
		var_map->map_cpy[lines] = ft_strdup(var_map->map[lines]);
		line = get_next_line(fd);
		lines++;
	}
	var_map->lines_map = lines;
	var_map->map[lines] = NULL;
	var_map->map_cpy[lines] = NULL;
	close(fd);
	if(control_map(var_map) == -1)
		return(-1);
	return(0);
}

int control_map(t_maps *var_map)
{
	if (count_char(var_map->map_cpy, 'P') != 1)
		return (ft_printf("Error player"), -1);
	if (count_char(var_map->map_cpy, 'E') != 1)
		return (ft_printf("Error exit"), -1);
	if (count_char(var_map->map_cpy, 'C') < 1)
		return (ft_printf("Error coleccionables"), -1);
	if (count_str(var_map->map_cpy) != 0)
		return(-1);
	if (wall_check(var_map->map_cpy, var_map) != 0)
		return(-1);
	coords_xy(var_map->map_cpy, 'P', var_map);
	flood_fill(var_map, var_map->row_player, var_map->col_player);
	if (count_char(var_map->map_cpy, 'P') != 0)
		return (ft_printf("Error de mapa no jugable"), -1);
	if (count_char(var_map->map_cpy, 'E') != 0)
		return (ft_printf("Error de mapa no jugable"), -1);
	if (count_char(var_map->map_cpy, 'C') != 0)
		return (ft_printf("Error de mapa no jugable"), -1);
	return (0);
}

void	flood_fill(t_maps *var_map, int	row, int col)
{	
	if (!var_map->map_cpy[row][col])
		return ;
	if ((var_map->map_cpy[row][col] == 'X') || (var_map->map_cpy[row][col] == '1'))
		return ;
	var_map->map_cpy[row][col] = 'X';
	flood_fill(var_map, row + 1, col);
	flood_fill(var_map, row - 1, col);
	flood_fill(var_map, row, col + 1);
	flood_fill(var_map, row, col - 1);
}
