/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:49:56 by miltavar          #+#    #+#             */
/*   Updated: 2025/07/23 09:38:50 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	compare_res(t_game *game, int x, int y)
{
	int	mapx;
	int	mapy;

	mapx = (game->map->length) * 64;
	mapy = (game->map->height) * 64;
	if (mapx > x || mapy > y)
		return (ft_printf("Error\nMap too big\n"), -1);
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

	width = 64;
	height = 64;
	img = NULL;
	img = img_first(c, mlx, &width, &height);
	if (width != 64 || height != 64)
		return (NULL);
	return (img);
}

int	display_img(t_game *game)
{
	if (create_img(game) == -1)
		return (ft_printf("Error\nCouldn't create imgs\n"), -1);
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
