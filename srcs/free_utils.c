/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:21:20 by miltavar          #+#    #+#             */
/*   Updated: 2025/07/15 14:23:37 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_imgs(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->length)
		{
			if (game->map->cases[i][j].img)
				mlx_destroy_image(game->mlx, game->map->cases[i][j].img);
			j++;
		}
		i++;
	}
}

void	free_game(t_game *game)
{
	if (!game)
		return ;
	if (game->map)
		free_map(game->map);
	if (game->player)
		free(game->player);
	free(game);
	game = NULL;
}

void	free_split(char **strs)
{
	int	i;

	i = 0;
	if (!strs)
		return ;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

void	free_rec(char **copy, int i)
{
	while (i >= 0)
	{
		free(copy[i]);
		i--;
	}
	free(copy);
}

void	free_img(t_image **img, int height)
{
	int	i;

	i = 0;
	if (!img)
		return ;
	while (i < height)
	{
		free(img[i]);
		i++;
	}
	free(img);
}
