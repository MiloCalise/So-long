/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:57:21 by miltavar          #+#    #+#             */
/*   Updated: 2025/07/23 10:27:26 by miltavar         ###   ########.fr       */
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
		reprint_a(game, count);
		return (1);
	}
	else if (exit_if(game->map->cases[game->player->x][game->player->y - 1].c,
		game->map->items))
	{
		game->map->cases[game->player->x][game->player->y].c = '0';
		game->map->cases[game->player->x][game->player->y - 1].c = 'P';
		game->player->y = game->player->y - 1;
		reprint_a(game, count);
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
		reprint_s(game, count);
		return (1);
	}
	else if (exit_if(game->map->cases[game->player->x + 1][game->player->y].c,
		game->map->items))
	{
		game->map->cases[game->player->x][game->player->y].c = '0';
		game->map->cases[game->player->x + 1][game->player->y].c = 'P';
		game->player->x = game->player->x + 1;
		reprint_s(game, count);
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
		reprint_w(game, count);
		return (1);
	}
	else if (exit_if(game->map->cases[game->player->x - 1][game->player->y].c,
		game->map->items))
	{
		game->map->cases[game->player->x][game->player->y].c = '0';
		game->map->cases[game->player->x - 1][game->player->y].c = 'P';
		game->player->x = game->player->x - 1;
		reprint_w(game, count);
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
		reprint_d(game, count);
		return (1);
	}
	else if (exit_if(game->map->cases[game->player->x][game->player->y + 1].c,
		game->map->items))
	{
		game->map->cases[game->player->x][game->player->y].c = '0';
		game->map->cases[game->player->x][game->player->y + 1].c = 'P';
		game->player->y = game->player->y + 1;
		reprint_a(game, count);
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
	if (count == 2147483646)
		count = 0;
	if (keycode == XK_a)
		dir_a(game, &count);
	else if (keycode == XK_w)
		dir_w(game, &count);
	else if (keycode == XK_s)
		dir_s(game, &count);
	else if (keycode == XK_d)
		dir_d(game, &count);
	return (0);
}
