/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 13:23:09 by miltavar          #+#    #+#             */
/*   Updated: 2025/07/24 12:22:36 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	door_anim(t_game *game)
{
	int	x;
	int	y;
	int	w;
	int	h;

	h = 64;
	w = 64;
	x = get_exit_x(game);
	if (x == -1)
		return ;
	y = get_exit_y(game);
	if (y == -1)
		return ;
	mlx_destroy_image(game->mlx, game->map->cases[x][y].img);
	game->map->cases[x][y].img = mlx_xpm_file_to_image(game->mlx,
			"textures/open_exit.xpm", &w, &h);
	if (!game->map->cases[x][y].img)
		return ;
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->map->cases[x][y].img, y * 64, x * 64);
}

int	get_exit_x(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map->cases[i])
	{
		j = 0;
		while (game->map->cases[i][j].c)
		{
			if (game->map->cases[i][j].c == 'E')
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}

int	get_exit_y(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map->cases[i])
	{
		j = 0;
		while (game->map->cases[i][j].c)
		{
			if (game->map->cases[i][j].c == 'E')
				return (j);
			j++;
		}
		i++;
	}
	return (-1);
}

int	sprite(t_game *game, int x, int y)
{
	static int	i;
	int			w;
	int			h;

	h = 64;
	w = 64;
	if (!i)
		i = 0;
	if (i == 0)
	{
		game->map->cases[x][y].img = mlx_xpm_file_to_image(game->mlx,
				"textures/player.xpm", &w, &h);
		if (!game->map->cases[x][y].img)
			return (-1);
		i = 1;
	}
	else if (i == 1)
	{
		game->map->cases[x][y].img = mlx_xpm_file_to_image(game->mlx,
				"textures/player2.xpm", &w, &h);
		if (!game->map->cases[x][y].img)
			return (-1);
		i = 0;
	}
	return (1);
}

t_image	**malloc_open(int *fd, int height, char *str)
{
	t_image	**map;

	(*fd) = open(str, O_RDONLY);
	if ((*fd) < 0)
		return (perror("Error\n"), NULL);
	map = malloc(sizeof(t_image *) * (height + 1));
	if (!map)
		return (close((*fd)), ft_putstr_fd("Error\nMalloc failed\n", 2), NULL);
	return (map);
}
