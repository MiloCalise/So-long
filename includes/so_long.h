/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milo <milo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 10:23:57 by miltavar          #+#    #+#             */
/*   Updated: 2025/07/16 10:59:58 by milo             ###   ########.fr       */
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

typedef struct s_image
{
	char	c;
	void	*img;
}	t_image;

typedef struct s_player
{
	int		x;
	int		y;
}	t_player;

typedef struct s_enemy
{
	int		x;
	int		y;
}	t_enemy;

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
	t_enemy		*enemy;
}	t_game;

t_image		*char_to_img(char *line);
t_game		*init_all(char *str);

t_image		**import_map(char *str, int height);

void		free_img(t_image **img, int height);
void		free_game(t_game *game);
void		free_rec(char **copy, int i);
void		flood_fill(int x, int y, char **cases, int height);
void		free_split(char **strs);
void		free_map(t_map *map);
void		free_all(t_game *game);
void		free_imgs(t_game *game);
void		print_img(t_game *game);

void		*get_img(char c, void *mlx);
void		*img_first(char c, void *mlx, int *width, int *height);
void		*img_sec(char c, void *mlx, int *width, int *height);

int			check_each(char *str);
int			do_flood(t_game *game);
int			char_bin(char c);
int			get_length(char *str);
int			get_height(char *str);
int			check_map(t_image **cases, int *exit, int *player);
int			get_player_y(t_map *map);
int			get_player_x(t_map *map);
int			check_lim(char **str, int height);
int			check_after(char **str);
int			esc_hook(int keycode, t_game *game);
int			close_window(t_game *game);
int			compare_res(t_game *game, int x, int y);
int			create_img(t_game *game);
int			display_img(t_game *game);
int			dir_a(t_game *game, int *count);
int			dir_s(t_game *game, int *count);
int			dir_w(t_game *game, int *count);
int			dir_d(t_game *game, int *count);
int			dir_hook(int keycode, t_game *game);
int			key_hook(int keycode, t_game *game);
int			reprint_a(t_game *game);
int			reprint_d(t_game *game);
int			reprint_w(t_game *game);
int			reprint_s(t_game *game);

char		**fill_char(t_game *game);

t_map		*get_map(char *str);

t_player	*get_player(t_map *map);

t_enemy		*get_enemy(t_game *game);

#endif
