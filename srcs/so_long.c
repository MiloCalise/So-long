/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 10:23:42 by miltavar          #+#    #+#             */
/*   Updated: 2025/07/10 15:17:54 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_player	*get_player(t_map *map)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->x = get_player_x(map);
	if (player->x < 0)
		return (NULL);
	player->y = get_player_y(map);
	if (player->x < 0)
		return (NULL);
	return (player);
}

t_map	*get_map(char *str)
{
	t_map	*map;
	int		exit;
	int		player;

	exit = 0;
	player = 0;
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->length = get_length(str);
	if (map->length == -1)
		return (free(map), NULL);
	map->height = get_height(str);
	if (map->height == -1)
		return (free(map), NULL);
	map->cases = import_map(str, map->height);
	if (!map->cases)
		return (free_map(map), ft_putstr_fd("Error\nBad map\n", 2), NULL);
	map->items = check_map(map->cases, &exit, &player);
	if (map->items < 1)
		return (free_map(map), ft_putstr_fd("Error\nBad map\n", 2), NULL);
	if (exit != 1 || player != 1)
		return (free_map(map), ft_putstr_fd("Error\nBad map\n", 2), NULL);
	return (map);
}

int	do_flood(t_game *game)
{
	char	**copy;
	int		i;

	copy = fill_char(game);
	if (!copy)
		return (-1);
	i = 0;
	if (check_lim(copy, game->map->height) == -1)
		return (free_split(copy), -1);
	flood_fill(game->player->x, game->player->y, copy, game->map->height);
	if (check_after(copy) == -1)
		return (free_split(copy), -1);
	return (free_split(copy), 1);
}

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

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (1);
	game = init_all(argv[1]);
	if (!game)
		return (1);
	game->mlx = mlx_init();
	if (!game->mlx)
		return (free_game(game), 1);
	game->mlx_win = mlx_new_window(game->mlx,
		2560, 1440, "Cats world");
	if (!game->mlx_win)
		return (mlx_destroy_display(game->mlx), 1);
	mlx_loop(game->mlx);
	mlx_clear_window(game->mlx, game->mlx_win);
	return (mlx_destroy_window(game->mlx, game->mlx_win),
		mlx_destroy_display(game->mlx), free_game(game), 1);
}
