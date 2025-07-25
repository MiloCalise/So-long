/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 10:23:42 by miltavar          #+#    #+#             */
/*   Updated: 2025/07/24 10:43:51 by miltavar         ###   ########.fr       */
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
	game->enemy = get_enemy(game);
	if (game->enemy)
	{
		if (check_nbr_enemy(game) == -1)
			return (free_game(game), NULL);
	}
	if (do_flood(game) == -1)
		return (free_game(game), NULL);
	return (game);
}

int	game_init(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (free_game(game), ft_printf("Error\nMalloc failed\n"), -1);
	game->screenx = 0;
	game->screeny = 0;
	mlx_get_screen_size(game->mlx, &game->screenx, &game->screeny);
	if (compare_res(game, game->screenx, game->screeny - 128) == -1)
		return (mlx_destroy_display(game->mlx), free(game->mlx),
			free_game(game), -1);
	game->mlx_win = mlx_new_window(game->mlx,
			game->screenx, game->screeny, "Cats world");
	if (!game->mlx_win)
		return (mlx_destroy_display(game->mlx),
			ft_printf("Error\nCouldn't open window\n"),
			free(game->mlx), free_game(game), -1);
	if (get_digits(game) == -1)
		return (free_all(game), -1);
	if (display_img(game) == -1)
		return (free_all(game), -1);
	game->door = 0;
	mlx_hook(game->mlx_win, 2, 1L << 0, key_hook, game);
	mlx_hook(game->mlx_win, 17, 0L, close_window, game);
	mlx_loop_hook(game->mlx, loop_hook, game);
	mlx_loop(game->mlx);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (ft_printf("Error\nMissing argument\n"), 1);
	game = init_all(argv[1]);
	if (!game)
		return (1);
	if (game_init(game) == -1)
		return (1);
	return (0);
}
