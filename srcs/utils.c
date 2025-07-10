/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:18:51 by miltavar          #+#    #+#             */
/*   Updated: 2025/07/10 12:21:44 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

t_image	*char_to_img(char *line)
{
	t_image	*row;
	int		i;

	row = malloc(sizeof(t_image) * (ft_strlen(line)));
	if (!row)
		return (ft_putstr_fd("Error\nMap length incorrect", 2), NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		row[i].c = line[i];
		row[i].img = NULL;
		i++;
	}
	row[i].c = '\0';
	return (row);
}

int	check_each(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = (int)ft_strlen(str);
	while (i < len - 1)
	{
		if (char_bin(str[i]))
			i++;
		else
			return (-1);
	}
	return (0);
}

int	char_bin(char c)
{
	if (c == '1' || c == '0' || c == 'P' || c == 'E' || c == 'C')
		return (1);
	return (0);
}

void	free_map(t_map *map)
{
	if (!map)
		return ;
	if (map->cases)
		free_img(map->cases, map->height);
	free(map);
}
