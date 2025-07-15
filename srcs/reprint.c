/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reprint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:12:52 by miltavar          #+#    #+#             */
/*   Updated: 2025/07/15 15:45:45 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	reprint_a(t_game *game)
{
	int	x;
	int	y;

	x = game->player->x;
	y = game->player->y;
	mlx_destroy_image(game->mlx,
		game->map->cases[x][y].img);
	mlx_destroy_image(game->mlx,
		game->map->cases[x][y + 1].img);
	game->map->cases[x][y].img = get_img(game->map->cases[x][y].c,
		game->mlx);
	if (!game->map->cases[x][y].img)
		return (free_all(game), -1);
	game->map->cases[x][y + 1].img = get_img(game->map->cases[x][y + 1].c,
		game->mlx);
	if (!game->map->cases[x][y + 1].img)
		return (free_all(game), -1);
	mlx_put_image_to_window(game->mlx,
		game->mlx_win, game->map->cases[x][y].img, y * 64, x * 64);
	mlx_put_image_to_window(game->mlx,
		game->mlx_win, game->map->cases[x][y + 1].img,
		(y + 1) * 64, (x) * 64);
	return (1);
}

int	reprint_d(t_game *game)
{
	int	x;
	int	y;

	x = game->player->x;
	y = game->player->y;
	mlx_destroy_image(game->mlx,
		game->map->cases[x][y].img);
	mlx_destroy_image(game->mlx,
		game->map->cases[x][y - 1].img);
	game->map->cases[x][y].img = get_img(game->map->cases[x][y].c,
		game->mlx);
	if (!game->map->cases[x][y].img)
		return (free_all(game), -1);
	game->map->cases[x][y - 1].img = get_img(game->map->cases[x][y - 1].c,
		game->mlx);
	if (!game->map->cases[x][y - 1].img)
		return (free_all(game), -1);
	mlx_put_image_to_window(game->mlx,
		game->mlx_win, game->map->cases[x][y].img, y * 64, x * 64);
	mlx_put_image_to_window(game->mlx,
		game->mlx_win, game->map->cases[x][y - 1].img,
		(y - 1) * 64, x * 64);
	return (1);
}

int	reprint_w(t_game *game)
{
	int	x;
	int	y;

	x = game->player->x;
	y = game->player->y;
	mlx_destroy_image(game->mlx,
		game->map->cases[x][y].img);
	mlx_destroy_image(game->mlx,
		game->map->cases[x + 1][y].img);
	game->map->cases[x][y].img = get_img(game->map->cases[x][y].c,
		game->mlx);
	if (!game->map->cases[x][y].img)
		return (free_all(game), -1);
	game->map->cases[x + 1][y].img = get_img(game->map->cases[x + 1][y].c,
		game->mlx);
	if (!game->map->cases[x + 1][y].img)
		return (free_all(game), -1);
	mlx_put_image_to_window(game->mlx,
		game->mlx_win, game->map->cases[x][y].img, y * 64, x * 64);
	mlx_put_image_to_window(game->mlx,
		game->mlx_win, game->map->cases[x + 1][y].img,
		y * 64, (x + 1) * 64);
	return (1);
}

int	reprint_s(t_game *game)
{
	int	x;
	int	y;

	x = game->player->x;
	y = game->player->y;
	mlx_destroy_image(game->mlx,
		game->map->cases[x][y].img);
	mlx_destroy_image(game->mlx,
		game->map->cases[x - 1][y].img);
	game->map->cases[x][y].img = get_img(game->map->cases[x][y].c,
		game->mlx);
	if (!game->map->cases[x][y].img)
		return (free_all(game), -1);
	game->map->cases[x - 1][y].img = get_img(game->map->cases[x - 1][y].c,
		game->mlx);
	if (!game->map->cases[x - 1][y].img)
		return (free_all(game), -1);
	mlx_put_image_to_window(game->mlx,
		game->mlx_win, game->map->cases[x][y].img, y * 64, x * 64);
	mlx_put_image_to_window(game->mlx,
		game->mlx_win, game->map->cases[x - 1][y].img,
		y * 64, (x - 1) * 64);
	return (1);
}
