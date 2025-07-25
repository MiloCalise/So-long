/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:24:55 by miltavar          #+#    #+#             */
/*   Updated: 2025/07/23 09:51:17 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_img(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->length)
		{
			mlx_put_image_to_window(game->mlx,
				game->mlx_win, game->map->cases[i][j].img, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

int	do_flood(t_game *game)
{
	char	**copy;

	copy = fill_char(game);
	if (!copy)
		return (ft_printf("Error\nMap filling failed\n"), -1);
	if (check_lim(copy, game->map->height) == -1)
		return (free_split(copy), ft_printf("Error\nBad map\n"), -1);
	flood_fill(game->player->x, game->player->y, copy, game->map->height);
	if (check_after(copy) == -1)
		return (free_split(copy), ft_printf("Error\nFlood fill failed\n"), -1);
	return (free_split(copy), 1);
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

t_player	*get_player(t_map *map)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (ft_printf("Error\nMalloc failed\n"), NULL);
	player->x = get_player_x(map);
	if (player->x < 0)
		return (ft_printf("Error\ninvalid player\n"), NULL);
	player->y = get_player_y(map);
	if (player->x < 0)
		return (ft_printf("Error\nFailed to gather player infos\n"), NULL);
	return (player);
}

void	free_all(t_game *game)
{
	free_imgs(game);
	destroy_count(game);
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_game(game);
}
