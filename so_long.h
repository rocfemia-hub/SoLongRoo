/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roo <roo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:20:05 by roo               #+#    #+#             */
/*   Updated: 2025/03/19 02:43:47 by roo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./Helicopter/libft.h"

typedef struct maps
{
	char	**map;
	char	**map_cpy;
	int		row_player;
	int		col_player;
	
}	t_maps;

// MAP

int	ft_cpy_map(char **argv, t_maps *var_map);
int control_map(t_maps *var_map);

//MAP UTILS

int	count_char(char **map, char c);
int	count_str(char **map, t_maps *var_map);
int coords_xy(char **map, int c, t_maps *var_map);

#endif