/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 11:15:34 by miltavar          #+#    #+#             */
/*   Updated: 2025/07/23 15:01:09 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	destroy_count(t_game *game)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (game->digits[i].img)
			mlx_destroy_image(game->mlx, game->digits[i].img);
		i++;
	}
}

int	get_digits(t_game *game)
{
	char	*path;
	int		i;
	int		w;
	int		h;

	i = 0;
	while (i < 10)
	{
		path = get_path(i);
		if (!path)
			return (ft_printf("Error\nFailed to get path\n"), -1);
		game->digits[i].img = mlx_xpm_file_to_image(game->mlx, path, &w, &h);
		if (!game->digits[i].img)
			return (free(path), ft_printf("Error\nFailed to load xpm\n"), -1);
		game->digits[i].c = i + 48;
		free(path);
		if (w > 64 || w < 64 || h > 64 || h < 64)
			return (ft_printf("Error\nXpm isn't 64 by 64 pixel\n"), -1);
		i++;
	}
	return (1);
}

void	*img_sec(char c, void *mlx, int *width, int *height)
{
	void	*img;

	img = NULL;
	if (c == 'E')
		img = mlx_xpm_file_to_image(mlx,
				"textures/close_exit.xpm", width, height);
	else if (c == 'M')
			img = mlx_xpm_file_to_image(mlx,
				"textures/enemy.xpm", width, height);
	return (img);
}

int	check_nbr_enemy(t_game *game)
{
	int	enemy;
	int	i;
	int	j;

	i = 0;
	enemy = 0;
	while (game->map->cases[i])
	{
		j = 0;
		while (game->map->cases[i][j].c)
		{
			if (game->map->cases[i][j].c == 'M')
				enemy++;
			j++;
		}
		i++;
	}
	if (enemy > 1)
		return (ft_printf("Error\nPlayer greater than 1\n"), -1);
	return (1);
}
