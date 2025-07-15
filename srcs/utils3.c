/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:32:11 by miltavar          #+#    #+#             */
/*   Updated: 2025/07/15 15:05:58 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	get_player_y(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->cases[i])
	{
		j = 0;
		while (map->cases[i][j].c)
		{
			if (map->cases[i][j].c == 'P')
				return (j);
			j++;
		}
		i++;
	}
	return (-1);
}

int	esc_hook(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
	{
		free_all(game);
		exit (0);
	}
	return (0);
}
