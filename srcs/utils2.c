/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:39:14 by miltavar          #+#    #+#             */
/*   Updated: 2025/07/24 12:22:15 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	get_length(char *str)
{
	int		length;
	int		fd;
	char	*line;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (perror("Error\n"), -1);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), ft_putstr_fd("Error\nGNL failed\n", 2), -1);
	length = ft_strlen(line);
	while (line)
	{
		if ((size_t)length != ft_strlen(line))
		{
			ft_putstr_fd("Error\nMap length incorrect\n", 2);
			return (get_next_line(-42), close(fd), free(line), -1);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (length < 4)
		return (ft_putstr_fd("Error\nMap length incorrect\n", 2), -1);
	return (length - 1);
}

int	get_height(char *str)
{
	int		height;
	int		fd;
	char	*line;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (perror("Error\n"), -1);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), ft_putstr_fd("Error\nGNL failed\n", 2), -1);
	height = 0;
	while (line)
	{
		height++;
		if (check_each(line) == -1)
		{
			ft_putstr_fd("Error\nMap contains forbidden char\n", 2);
			return (get_next_line(-42), free(line), close(fd), -1);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

t_image	**import_map(char *str, int height)
{
	int		fd;
	int		i;
	char	*line;
	t_image	**map;

	map = malloc_open(&fd, height, str);
	if (!map)
		return (NULL);
	line = get_next_line(fd);
	if (!line)
		return (free(map), close(fd), NULL);
	i = 0;
	while (line)
	{
		map[i] = char_to_img(line);
		if (!map[i])
			return (free(line), free_img(map, i), close(fd), NULL);
		i++;
		free(line);
		line = get_next_line(fd);
		if (!line && i < height)
			return (free_img(map, i), close(fd), NULL);
	}
	map[i] = NULL;
	return (close(fd), map);
}

int	check_map(t_image **cases, int *exit, int *player)
{
	int	i;
	int	j;
	int	item;

	i = 0;
	j = 0;
	item = 0;
	while (cases[i])
	{
		j = 0;
		while (cases[i][j].c)
		{
			if (cases[i][j].c == 'C')
				item++;
			else if ((cases[i][j].c) == 'P')
				(*player)++;
			else if ((cases[i][j].c) == 'E')
				(*exit)++;
			j++;
		}
		i++;
	}
	return (item);
}

int	get_player_x(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->cases[i])
	{
		j = 0;
		while (map->cases[i][j].c)
		{
			if (map->cases[i][j].c == 'P')
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}
