/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roo <roo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:39:05 by roo               #+#    #+#             */
/*   Updated: 2025/03/18 21:56:08 by roo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	int 	fd;
	int		lines;
	char	*line;
	t_maps	*var_map;
	
	if (argc != 2)
		return(ft_printf("Error de numero de argumentos"), -1);
	if (ft_strncmp(argv[1] + (ft_strlen(argv[1]) - ft_strlen(".ber")), ".ber", ft_strlen(".ber")) != 0)
		return (ft_printf("Error de archivo incompatible"), -1);
	var_map = ft_calloc(1, sizeof(t_maps));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return(ft_printf("Error de apertura de archivo 1"), -1);
	line = get_next_line(fd);
	while(line)
	{
		lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	var_map->map = ft_calloc(lines + 1, sizeof(char *));
	var_map->map_cpy = ft_calloc(lines + 1, sizeof(char *));
	ft_cpy_map(argv, var_map);
	return (0);
}
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
	if ((count_char(var_map, 'P') != 1) || (count_char(var_map, 'E') != 1))
		return (ft_printf("Error de numero de personaje o exit"), -1);
	if (count_char(var_map, 'C') < 1)
		return (ft_printf("Error de numero de coleccionables"), -1);
	return(0);
}

int	count_char(char **matrix, char c)
{
	int i;
	int j;
	int count;
	
	i = 0;
	count = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			if (matrix[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	/* if ((c == 'P' || c == 'E') && count != 1)
		return (-1);
	else if (c == 'C' && count < 1)
		return (-1); */
	return (count);
}
