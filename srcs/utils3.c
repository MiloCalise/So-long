/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:32:11 by miltavar          #+#    #+#             */
/*   Updated: 2025/07/23 10:19:43 by miltavar         ###   ########.fr       */
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
	enemy->x = get_enemy_x(game);
	if (enemy->x == -1)
		return (free(enemy), NULL);
	enemy->y = get_enemy_y(game);
	if (enemy->y == -1)
		return (free(enemy), NULL);
	return (enemy);
}
