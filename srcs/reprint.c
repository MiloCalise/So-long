/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reprint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:12:52 by miltavar          #+#    #+#             */
/*   Updated: 2025/07/24 10:37:29 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	reprint_a(t_game *game, int *count)
{
	int	x;
	int	y;

	x = game->player->x;
	y = game->player->y;
	mlx_destroy_image(game->mlx,
		game->map->cases[x][y].img);
	mlx_destroy_image(game->mlx,
		game->map->cases[x][y + 1].img);
	count_write(game, count);
	if (sprite(game, x, y) == -1)
		return (free_all(game), -1);
	game->map->cases[x][y + 1].img = get_img(game->map->cases[x][y + 1].c,
			game->mlx);
	if (!game->map->cases[x][y + 1].img)
		return (free_all(game), -1);
	mlx_put_image_to_window(game->mlx,
		game->mlx_win, game->map->cases[x][y].img, y * 64, x * 64);
	mlx_put_image_to_window(game->mlx,
		game->mlx_win, game->map->cases[x][y + 1].img,
		(y + 1) * 64, x * 64);
	return (1);
}

int	reprint_d(t_game *game, int *count)
{
	int	x;
	int	y;

	x = game->player->x;
	y = game->player->y;
	mlx_destroy_image(game->mlx,
		game->map->cases[x][y].img);
	mlx_destroy_image(game->mlx,
		game->map->cases[x][y - 1].img);
	count_write(game, count);
	if (sprite(game, x, y) == -1)
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

int	reprint_w(t_game *game, int *count)
{
	int	x;
	int	y;

	x = game->player->x;
	y = game->player->y;
	mlx_destroy_image(game->mlx,
		game->map->cases[x][y].img);
	mlx_destroy_image(game->mlx,
		game->map->cases[x + 1][y].img);
	count_write(game, count);
	if (sprite(game, x, y) == -1)
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

int	reprint_s(t_game *game, int *count)
{
	int	x;
	int	y;

	x = game->player->x;
	y = game->player->y;
	mlx_destroy_image(game->mlx,
		game->map->cases[x][y].img);
	mlx_destroy_image(game->mlx,
		game->map->cases[x - 1][y].img);
	count_write(game, count);
	if (sprite(game, x, y) == -1)
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

int	cond(t_game *game, int random)
{
	if (game->map->cases[game->enemy->x][game->enemy->y + 1].c == '0'
		&& (game->map->cases[game->enemy->x + 1][game->enemy->y + 1].c == '0'
		|| game->map->cases[game->enemy->x - 1][game->enemy->y + 1].c == '0')
		&& random == 0)
		return (0);
	if (game->map->cases[game->enemy->x][game->enemy->y - 1].c == '0'
		&& (game->map->cases[game->enemy->x + 1][game->enemy->y - 1].c == '0'
		|| game->map->cases[game->enemy->x - 1][game->enemy->y - 1].c == '0')
		&& random == 1)
		return (1);
	if (game->map->cases[game->enemy->x - 1][game->enemy->y].c == '0'
		&& (game->map->cases[game->enemy->x - 1][game->enemy->y + 1].c == '0'
		|| game->map->cases[game->enemy->x - 1][game->enemy->y - 1].c == '0')
		&& random == 2)
		return (2);
	if (game->map->cases[game->enemy->x + 1][game->enemy->y].c == '0'
		&& (game->map->cases[game->enemy->x + 1][game->enemy->y + 1].c == '0'
		|| game->map->cases[game->enemy->x + 1][game->enemy->y - 1].c == '0')
		&& random == 3)
		return (3);
	return (-1);
}
