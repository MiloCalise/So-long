/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:49:56 by miltavar          #+#    #+#             */
/*   Updated: 2025/07/15 15:50:35 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	compare_res(t_game *game, int x, int y)
{
	int	mapx;
	int	mapy;

	mapx = game->map->length * 64;
	mapy = game->map->height * 64;
	if (mapx > x || mapy > y)
		return (-1);
	return (1);
}

int	create_img(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->length)
		{
			game->map->cases[i][j].img = get_img(game->map->cases[i][j].c,
				game->mlx);
			if (!game->map->cases[i][j].img)
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

void	*get_img(char c, void *mlx)
{
	void	*img;
	int		width;
	int		height;

	img = NULL;
	width = 64;
	height = 64;
	if (c == '1')
		img = mlx_xpm_file_to_image(mlx,
			"textures/wall.xpm", &width, &height);
	else if (c == '0')
		img = mlx_xpm_file_to_image(mlx,
			"textures/floor.xpm", &width, &height);
	else if (c == 'C')
		img = mlx_xpm_file_to_image(mlx,
			"textures/item.xpm", &width, &height);
	else if (c == 'P')
		img = mlx_xpm_file_to_image(mlx,
			"textures/player.xpm", &width, &height);
	else if (c == 'E')
		img = mlx_xpm_file_to_image(mlx,
			"textures/exit.xpm", &width, &height);
	if (width != 64 || height != 64)
		return (NULL);
	return (img);
}

int	display_img(t_game *game)
{
	if (create_img(game) == -1)
		return (free_all(game), -1);
	print_img(game);
	return (1);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		return (esc_hook(keycode, game));
	else
		return (dir_hook(keycode, game));
}
