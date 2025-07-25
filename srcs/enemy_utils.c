/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 11:14:59 by miltavar          #+#    #+#             */
/*   Updated: 2025/07/23 11:09:50 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_right(t_game *game)
{
	game->map->cases[game->enemy->x][game->enemy->y].c = '0';
	game->map->cases[game->enemy->x][game->enemy->y + 1].c = 'M';
	game->enemy->y = game->enemy->y + 1;
	mlx_destroy_image(game->mlx,
		game->map->cases[game->enemy->x][game->enemy->y].img);
	mlx_destroy_image(game->mlx,
		game->map->cases[game->enemy->x][game->enemy->y - 1].img);
	game->map->cases[game->enemy->x][game->enemy->y].img = get_img(
			game->map->cases[game->enemy->x][game->enemy->y].c, game->mlx);
	if (!game->map->cases[game->enemy->x][game->enemy->y].img)
		return (free_all(game));
	game->map->cases[game->enemy->x][game->enemy->y - 1].img = get_img(
			game->map->cases[game->enemy->x][game->enemy->y - 1].c, game->mlx);
	if (!game->map->cases[game->enemy->x][game->enemy->y - 1].img)
		return (free_all(game));
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->map->cases[game->enemy->x][game->enemy->y].img,
		game->enemy->y * 64, game->enemy->x * 64);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->map->cases[game->enemy->x][game->enemy->y - 1].img,
		(game->enemy->y - 1) * 64, game->enemy->x * 64);
}

void	move_left(t_game *game)
{
	game->map->cases[game->enemy->x][game->enemy->y].c = '0';
	game->map->cases[game->enemy->x][game->enemy->y - 1].c = 'M';
	game->enemy->y = game->enemy->y - 1;
	mlx_destroy_image(game->mlx,
		game->map->cases[game->enemy->x][game->enemy->y].img);
	mlx_destroy_image(game->mlx,
		game->map->cases[game->enemy->x][game->enemy->y + 1].img);
	game->map->cases[game->enemy->x][game->enemy->y].img = get_img(
			game->map->cases[game->enemy->x][game->enemy->y].c, game->mlx);
	if (!game->map->cases[game->enemy->x][game->enemy->y].img)
		return (free_all(game));
	game->map->cases[game->enemy->x][game->enemy->y + 1].img = get_img(
			game->map->cases[game->enemy->x][game->enemy->y + 1].c, game->mlx);
	if (!game->map->cases[game->enemy->x][game->enemy->y + 1].img)
		return (free_all(game));
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->map->cases[game->enemy->x][game->enemy->y].img,
		game->enemy->y * 64, game->enemy->x * 64);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->map->cases[game->enemy->x][game->enemy->y + 1].img,
		(game->enemy->y + 1) * 64, game->enemy->x * 64);
}

void	move_up(t_game *game)
{
	game->map->cases[game->enemy->x][game->enemy->y].c = '0';
	game->map->cases[game->enemy->x - 1][game->enemy->y].c = 'M';
	game->enemy->x = game->enemy->x - 1;
	mlx_destroy_image(game->mlx,
		game->map->cases[game->enemy->x][game->enemy->y].img);
	mlx_destroy_image(game->mlx,
		game->map->cases[game->enemy->x + 1][game->enemy->y].img);
	game->map->cases[game->enemy->x][game->enemy->y].img = get_img(
			game->map->cases[game->enemy->x][game->enemy->y].c, game->mlx);
	if (!game->map->cases[game->enemy->x][game->enemy->y].img)
		return (free_all(game));
	game->map->cases[game->enemy->x + 1][game->enemy->y].img = get_img(
			game->map->cases[game->enemy->x + 1][game->enemy->y].c, game->mlx);
	if (!game->map->cases[game->enemy->x + 1][game->enemy->y].img)
		return (free_all(game));
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->map->cases[game->enemy->x][game->enemy->y].img,
		game->enemy->y * 64, game->enemy->x * 64);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->map->cases[game->enemy->x + 1][game->enemy->y].img,
		game->enemy->y * 64, (game->enemy->x + 1) * 64);
}

void	move_down(t_game *game)
{
	game->map->cases[game->enemy->x][game->enemy->y].c = '0';
	game->map->cases[game->enemy->x + 1][game->enemy->y].c = 'M';
	game->enemy->x = game->enemy->x + 1;
	mlx_destroy_image(game->mlx,
		game->map->cases[game->enemy->x][game->enemy->y].img);
	mlx_destroy_image(game->mlx,
		game->map->cases[game->enemy->x - 1][game->enemy->y].img);
	game->map->cases[game->enemy->x][game->enemy->y].img = get_img(
			game->map->cases[game->enemy->x][game->enemy->y].c, game->mlx);
	if (!game->map->cases[game->enemy->x][game->enemy->y].img)
		return (free_all(game));
	game->map->cases[game->enemy->x - 1][game->enemy->y].img = get_img(
			game->map->cases[game->enemy->x - 1][game->enemy->y].c, game->mlx);
	if (!game->map->cases[game->enemy->x - 1][game->enemy->y].img)
		return (free_all(game));
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->map->cases[game->enemy->x][game->enemy->y].img,
		game->enemy->y * 64, game->enemy->x * 64);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->map->cases[game->enemy->x - 1][game->enemy->y].img,
		game->enemy->y * 64, (game->enemy->x - 1) * 64);
}

void	count_write(t_game *game, int *count)
{
	char	*str;
	int		i;
	int		x;
	int		y;

	(*count)++;
	str = ft_itoa((*count));
	if (!str)
		return ;
	i = ft_strlen(str) - 1;
	x = game->screenx - 64;
	y = (game->map->height) * 64;
	while (i >= 0 && x >= 0)
	{
		if (str[i] - 48 >= 0 && str[i] - 48 <= 9)
		{
			mlx_put_image_to_window(game->mlx,
				game->mlx_win, game->digits[str[i] - 48].img,
				x, y);
		}
		i--;
		x = x - 64;
	}
	free(str);
}
