/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 10:03:16 by miltavar          #+#    #+#             */
/*   Updated: 2025/07/10 11:22:22 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	flood_fill(int x, int y, char **copy, int height)
{
	int	len;

	len = ft_strlen(copy[y]);
	if (x < 0 || x >= len || y < 0 || y >= height)
		return ;
	if (copy[y][x] == '1' || copy[y][x] == '3')
		return ;
	else if (copy[y][x] == '0' || copy[y][x] == 'C'
		|| copy[y][x] == 'P' || copy[y][x] == 'E')
	{
		copy[y][x] = '3';
		flood_fill(x - 1, y, copy, height);
		flood_fill(x + 1, y, copy, height);
		flood_fill(x, y - 1, copy, height);
		flood_fill(x, y + 1, copy, height);
	}
}

char	**fill_char(t_game *game)
{
	int		i;
	int		j;
	char	**copy;

	copy = malloc(sizeof(char *) * (game->map->height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < game->map->height)
	{
		copy[i] = malloc(sizeof(char) * (game->map->length + 1));
		if (!copy[i])
			return (free_rec(copy, i - 1), NULL);
		j = 0;
		while (j < game->map->length)
		{
			copy[i][j] = game->map->cases[i][j].c;
			j++;
		}
		copy[i][j] = '\0';
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

int	check_lim(char **str, int height)
{
	int	len;
	int	i;
	int	j;

	len = ft_strlen(str[0]);
	i = 0;
	while (str[i])
	{
		j = 0;
		if (i == 0 || i == height - 1)
		{
			while (str[i][j])
			{
				if (str[i][j] != '1')
					return (-1);
				j++;
			}
		}
		else
			if (str[i][0] != '1' && str[i][len - 1] != '1')
				return (-1);
		i++;
	}
	return (1);
}

int	check_after(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '1' || str[i][j] == '0' || str[i][j] == '3')
				j++;
			else
				return (-1);
		}
		i++;
	}
	return (1);
}
