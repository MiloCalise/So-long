/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milo <milo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:57:21 by miltavar          #+#    #+#             */
/*   Updated: 2025/07/16 10:13:42 by milo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	dir_a(t_game *game, int *count)
{
	if (game->map->cases[game->player->x][game->player->y - 1].c == '0' ||
		game->map->cases[game->player->x][game->player->y - 1].c == 'C')
	{
		if (game->map->cases[game->player->x][game->player->y - 1].c == 'C')
			game->map->items = game->map->items - 1;
		game->map->cases[game->player->x][game->player->y].c = '0';
		game->map->cases[game->player->x][game->player->y - 1].c = 'P';
		game->player->y = game->player->y - 1;
		reprint_a(game);
		(*count)++;
		return (ft_printf("%d\n", *count), 1);
	}
	else if (game->map->cases[game->player->x][game->player->y - 1].c == 'E'
		&& game->map->items == 0)
	{
		game->map->cases[game->player->x][game->player->y].c = '0';
		game->map->cases[game->player->x][game->player->y - 1].c = 'P';
		game->player->y = game->player->y - 1;
		reprint_a(game);
		(*count)++;
		ft_printf("%d\n", *count);
		free_all(game);
		exit (1);
	}
	return (-1);
}

int	dir_s(t_game *game, int *count)
{
	if (game->map->cases[game->player->x + 1][game->player->y].c == '0' ||
		game->map->cases[game->player->x + 1][game->player->y].c == 'C')
	{
		if (game->map->cases[game->player->x + 1][game->player->y].c == 'C')
			game->map->items = game->map->items - 1;
		game->map->cases[game->player->x][game->player->y].c = '0';
		game->map->cases[game->player->x + 1][game->player->y].c = 'P';
		game->player->x = game->player->x + 1;
		reprint_s(game);
		(*count)++;
		return (ft_printf("%d\n", *count), 1);
	}
	else if (game->map->cases[game->player->x + 1][game->player->y].c == 'E'
		&& game->map->items == 0)
	{
		game->map->cases[game->player->x][game->player->y].c = '0';
		game->map->cases[game->player->x + 1][game->player->y].c = 'P';
		game->player->x = game->player->x + 1;
		reprint_s(game);
		(*count)++;
		ft_printf("%d\n", *count);
		free_all(game);
		exit (1);
	}
	return (-1);
}

int	dir_w(t_game *game, int *count)
{
	if (game->map->cases[game->player->x - 1][game->player->y].c == '0' ||
		game->map->cases[game->player->x - 1][game->player->y].c == 'C')
	{
		if (game->map->cases[game->player->x - 1][game->player->y].c == 'C')
			game->map->items = game->map->items - 1;
		game->map->cases[game->player->x][game->player->y].c = '0';
		game->map->cases[game->player->x - 1][game->player->y].c = 'P';
		game->player->x = game->player->x - 1;
		reprint_w(game);
		(*count)++;
		return (ft_printf("%d\n", *count), 1);
	}
	else if (game->map->cases[game->player->x - 1][game->player->y].c == 'E'
		&& game->map->items == 0)
	{
		game->map->cases[game->player->x][game->player->y].c = '0';
		game->map->cases[game->player->x - 1][game->player->y].c = 'P';
		game->player->x = game->player->x - 1;
		reprint_w(game);
		(*count)++;
		ft_printf("%d\n", *count);
		free_all(game);
		exit (1);
	}
	return (-1);
}

int	dir_d(t_game *game, int *count)
{
	if (game->map->cases[game->player->x][game->player->y + 1].c == '0' ||
		game->map->cases[game->player->x][game->player->y + 1].c == 'C')
	{
		if (game->map->cases[game->player->x][game->player->y + 1].c == 'C')
			game->map->items = game->map->items - 1;
		game->map->cases[game->player->x][game->player->y].c = '0';
		game->map->cases[game->player->x][game->player->y + 1].c = 'P';
		game->player->y = game->player->y + 1;
		reprint_d(game);
		(*count)++;
		return (ft_printf("%d\n", *count), 1);
	}
	else if (game->map->cases[game->player->x][game->player->y + 1].c == 'E'
		&& game->map->items == 0)
	{
		game->map->cases[game->player->x][game->player->y].c = '0';
		game->map->cases[game->player->x][game->player->y + 1].c = 'P';
		game->player->y = game->player->y + 1;
		reprint_a(game);
		(*count)++;
		ft_printf("%d\n", *count);
		free_all(game);
		exit (1);
	}
	return (-1);
}

int	dir_hook(int keycode, t_game *game)
{
	static int	count;

	if (!count)
		count = 0;
	if (keycode == XK_a)
	{
		if (dir_a(game, &count) == -1)
			return (1);
	}
	else if (keycode == XK_w)
	{
		if (dir_w(game, &count) == -1)
			return (1);
	}
	else if (keycode == XK_s)
	{
		if (dir_s(game, &count) == -1)
			return (1);
	}
	else if (keycode == XK_d)
	{
		if (dir_d(game, &count) == -1)
			return (1);
	}
	return (1);
}
