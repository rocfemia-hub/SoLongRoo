/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roo <roo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:39:05 by roo               #+#    #+#             */
/*   Updated: 2025/04/16 17:12:33 by roo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_maps	*var_map;
	t_mlx	*var_mlx;

	var_map = ft_calloc(1, sizeof(t_maps));
	var_mlx = ft_calloc(1, sizeof(t_mlx));
	var_mlx->var_map2 = var_map;
	if (control_argv(argc, argv, var_map) == -1)
		return (-1);
	if (cpy_map(argv, var_map, var_mlx) == -1)
		return (-1);
	var_mlx->movs = 0;
	mlx_loop(var_mlx->mlx_ptr);
	return (0);
}

int	control_argv(int argc, char **argv, t_maps *var_map)
{
	int		fd;
	int		lines;
	char	*line;

	if (argc != 2)
		return (ft_printf("Error de numero de argumentos"), -1);
	if (ft_strncmp(argv[1] + (ft_strlen(argv[1]) - ft_strlen(".ber")),
			".ber", ft_strlen(".ber")) != 0)
		return (ft_printf("Error de archivo incompatible"), -1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error de apertura de archivo 1"), -1);
	line = get_next_line(fd);
	lines = 0;
	while (line)
	{
		lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	var_map->map = ft_calloc(lines + 1, sizeof(char *));
	var_map->map_cpy = ft_calloc(lines + 1, sizeof(char *));
	return (0);
}

int	cpy_map(char **argv, t_maps *var_map, t_mlx *var_mlx)
{
	int		fd;
	int		lines;
	char	*line;

	fd = open(argv[1], O_RDWR);
	if (fd == -1)
		return (ft_printf("Error de apertura de archivo 2"), -1);
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
	if (control_map(var_map, var_mlx) == -1)
		return (-1);
	return (0);
}

int	control_map(t_maps *var_map, t_mlx *var_mlx)
{
	if (count_char(var_map, 'P') != 1)
		return (ft_printf("Error player"), close_game(var_mlx), -1);
	if (count_char(var_map, 'E') != 1)
		return (ft_printf("Error exit"), close_game(var_mlx), -1);
	if (count_char(var_map, 'C') < 1)
		return (ft_printf("Error coleccionables"), close_game(var_mlx), -1);
	if (count_str(var_map->map_cpy) != 0)
		return (close_game(var_mlx), -1);
	if (wall_check(var_map->map_cpy, var_map) != 0)
		return (close_game(var_mlx), -1);
	coords_xy(var_map->map_cpy, 'P', var_map);
	flood_fill(var_map, var_map->row_player, var_map->col_player);
	if (count_char(var_map, 'P') != 0)
		return (ft_printf("Error de mapa no jugable"), close_game(var_mlx), -1);
	if (count_char(var_map, 'E') != 0)
		return (ft_printf("Error de mapa no jugable"), close_game(var_mlx), -1);
	if (count_char(var_map, 'C') != 0)
		return (ft_printf("Error de mapa no jugable"), close_game(var_mlx), -1);
	if (initiation_mlx(var_map, var_mlx) == -1)
		return (ft_printf("Error de xpm"), close_game(var_mlx), -1);
	return (0);
}

void	flood_fill(t_maps *var_map, int row, int col)
{
	if (!var_map->map_cpy[row][col])
		return ;
	if ((var_map->map_cpy[row][col] == 'X')
		|| (var_map->map_cpy[row][col] == '1'))
		return ;
	var_map->map_cpy[row][col] = 'X';
	flood_fill(var_map, row + 1, col);
	flood_fill(var_map, row - 1, col);
	flood_fill(var_map, row, col + 1);
	flood_fill(var_map, row, col - 1);
}
