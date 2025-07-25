/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 09:48:08 by miltavar          #+#    #+#             */
/*   Updated: 2025/07/24 10:38:36 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	exit_if(char c, int item)
{
	if (c == 'E' && item == 0)
		return (1);
	else if (c == 'M')
		return (1);
	return (0);
}

int	loop_hook(t_game *game)
{
	if (game->enemy)
		enemy_update(game);
	if (game->map->items == 0 && game->door == 0)
	{
		door_anim(game);
		game->door = 1;
	}
	return (0);
}

void	enemy_update(t_game *game)
{
	static time_t	last_move;
	time_t			now;

	if (!last_move)
		last_move = 0;
	now = time(NULL);
	if (now - last_move >= 1)
	{
		last_move = now;
		move(game);
	}
}

void	move(t_game *game)
{
	int	random;

	random = rand() % 4;
	if (cond(game, random) == 0)
		move_right(game);
	else if (cond(game, random) == 1)
		move_left(game);
	else if (cond(game, random) == 2)
		move_up(game);
	else if (cond(game, random) == 3)
		move_down(game);
}

char	*get_path(int nbr)
{
	char	*path;
	char	*digit;
	char	*temp;

	digit = ft_itoa(nbr);
	if (!digit)
		return (NULL);
	path = ft_strjoin(digit, ".xpm");
	if (!path)
		return (free(digit), NULL);
	temp = ft_strjoin("textures/", path);
	if (!temp)
	{
		ft_printf("Error\nFailed to load path\n");
		return (free(digit), free(path), NULL);
	}
	return (free(digit), free(path), temp);
}
