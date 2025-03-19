/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roo <roo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:39:05 by roo               #+#    #+#             */
/*   Updated: 2025/03/19 02:19:13 by roo              ###   ########.fr       */
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
