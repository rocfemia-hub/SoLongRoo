/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roo <roo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:20:05 by roo               #+#    #+#             */
/*   Updated: 2025/03/18 22:47:58 by roo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./Helicopter/libft.h"

typedef struct maps
{
	char	**map;
	char	**map_cpy;
}	t_maps;

typedef struct player
{
	int	x_player;
	int	y_player;
}	t_player;

typedef struct door
{
	int	x_door;
	int	y_door;
}	t_door;

#endif