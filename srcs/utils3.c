/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milo <milo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:32:11 by miltavar          #+#    #+#             */
/*   Updated: 2025/07/16 10:30:45 by milo             ###   ########.fr       */
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

int	get_enemy_x(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map->cases[i])
	{
		j = 0;
		while (game->map->cases[i][j].c)
		{
			if (game->map->cases[i][j].c == 'M')
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}

int	get_enemy_y(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map->cases[i])
	{
		j = 0;
		while (game->map->cases[i][j].c)
		{
			if (game->map->cases[i][j].c == 'M')
				return (j);
			j++;
		}
		i++;
	}
	return (-1);
}

t_enemy	*get_enemy(t_game *game)
{
	t_enemy	*enemy;

	enemy = malloc(sizeof(t_enemy));
	if (!enemy)
		return (NULL);
	if (get_enemy_x(game) == -1)
		return (free(game->enemy), NULL);
	if (get_enemy_y(game) == -1)
		return (free(game->enemy), NULL);
	return (enemy);
}
