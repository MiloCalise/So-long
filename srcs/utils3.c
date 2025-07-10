/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:32:11 by miltavar          #+#    #+#             */
/*   Updated: 2025/07/10 11:40:02 by miltavar         ###   ########.fr       */
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
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}

void	free_game(t_game *game)
{
	if (!game)
		return ;
	if (game->map)
		free_map(game->map);
	if (game->player)
		free(game->player);
	free(game);
}

void	free_split(char **strs)
{
	int	i;

	i = 0;
	if (!strs)
		return ;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

void	free_rec(char **copy, int i)
{
	while (i >= 0)
	{
		free(copy[i]);
		i--;
	}
	free(copy);
}
