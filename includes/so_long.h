/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 10:23:57 by miltavar          #+#    #+#             */
/*   Updated: 2025/07/10 15:08:02 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"

#define KEY_ESC 65307

typedef struct s_image
{
	char	c;
	void	*img;
}	t_image;

typedef struct s_player
{
	int		x;
	int		y;
	void	*img;
}	t_player;

typedef struct s_data
{
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_data;

typedef struct s_map
{
	t_image	**cases;
	int		height;
	int		length;
	int		items;
}	t_map;

typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	t_map		*map;
	t_player	*player;
	t_data		*data;
}	t_game;

t_image	*char_to_img(char *line);
t_game	*init_all(char *str);

t_image	**import_map(char *str, int height);

void	free_img(t_image **img, int height);
void	free_game(t_game *game);
void	free_rec(char **copy, int i);
void	flood_fill(int x, int y, char **cases, int height);
void	free_split(char **strs);
void	free_map(t_map *map);

int		check_each(char *str);
int		char_bin(char c);
int		get_length(char *str);
int		get_height(char *str);
int		check_map(t_image **cases, int *exit, int *player);
int		get_player_y(t_map *map);
int		get_player_x(t_map *map);
int		check_lim(char **str, int height);
int		check_after(char **str);

char	**fill_char(t_game *game);

#endif
