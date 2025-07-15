/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 10:23:42 by miltavar          #+#    #+#             */
/*   Updated: 2025/07/15 15:13:11 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_game	*init_all(char *str)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->map = get_map(str);
	if (!game->map)
		return (free_map(game->map), free(game), NULL);
	game->player = get_player(game->map);
	if (!game->player)
		return (free_game(game), NULL);
	if (do_flood(game) == -1)
		return (free_game(game), NULL);
	return (game);
}

int	game_init(t_game *game)
{
	int	x;
	int	y;
	x = 0;
	y = 0;
	game->mlx = mlx_init();
	if (!game->mlx)
		return (free_game(game), -1);
	mlx_get_screen_size(game->mlx, &x, &y);
	if (compare_res(game, x, y) == -1)
		return (mlx_destroy_display(game->mlx), free_game(game), -1);
	game->mlx_win = mlx_new_window(game->mlx, x, y, "Cats world");
	if (!game->mlx_win)
		return (mlx_destroy_display(game->mlx), -1);
	if (display_img(game) == -1)
		return (free_all(game), -1);
	mlx_hook(game->mlx_win, 2, 1L << 0, key_hook, game);
	mlx_hook(game->mlx_win, 17, 0L, close_window, game);
	mlx_loop(game->mlx);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (1);
	game = init_all(argv[1]);
	if (!game)
		return (1);
	if (game_init(game) == -1)
		return (1);
	return (0);
}
