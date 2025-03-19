/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roo <roo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 02:17:00 by roo               #+#    #+#             */
/*   Updated: 2025/03/19 04:41:14 by roo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_cpy_map(char **argv, t_maps *var_map)
{
	int 	fd;
	int		lines;
	char	*line;
	
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return(ft_printf("Error de apertura de archivo 2"), -1);
	line = get_next_line(fd);
	lines = 0;
	while (line)
	{
		var_map->map[lines] = line;
		var_map->map_cpy[lines] = ft_strdup(line);
		line = get_next_line(fd);
		lines++;
	}
	var_map->map[lines] = NULL;
	var_map->map_cpy[lines] = NULL;
	close(fd);
	control_map(var_map);
	return(0);
}

int control_map(t_maps *var_map)
{
	if (count_char(var_map->map_cpy, 'P') != 1)
		return (ft_printf("Error de PEC 1"), -1);
	if (count_char(var_map->map_cpy, 'E') != 1)
		return (ft_printf("Error de PEC 2"), -1);
	if (count_char(var_map->map_cpy, 'C') < 1)
		return (ft_printf("Error de PEC 3"), -1);
	if (coords_xy(var_map->map_cpy, 'P', var_map) != 0)
		return (ft_printf("Error de PEC 4"), -1);
	if (count_str(var_map->map_cpy) != 0)
		return(ft_printf("Error de longitud de mapa"), -1);
	if (wall_check(var_map->map_cpy, var_map) != 0)
		return(ft_printf("Error de pared del mapa"), -1);
	return (0);
}
