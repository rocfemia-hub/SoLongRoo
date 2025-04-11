/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roo <roo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:00:19 by roo               #+#    #+#             */
/*   Updated: 2025/04/11 16:07:33 by roo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	press_keys(int keycode)
{
	if (keycode == 119)
		ft_printf("W presionado\n");
	else if (keycode == 97)
		ft_printf("A presionado\n");
	else if (keycode == 115)
		ft_printf("S presionado\n");
	else if (keycode == 100)
		ft_printf("D presionado\n");
	else if (keycode == 65307)
		exit(0);
	return (0);
}