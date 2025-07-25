# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/12 13:17:19 by miltavar          #+#    #+#              #
#    Updated: 2025/07/23 15:04:17 by miltavar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror -Ilib/mlx -g3
MLXFLAGS = -L$(MLX) -lmlx_Linux -lXext -lX11

LIBFT = libft/
MLX = mlx/

AR = ar rcs
RM = rm -f

SRC = srcs/so_long.c srcs/utils.c srcs/utils2.c srcs/utils3.c srcs/utils4.c \
		srcs/utils5.c srcs/utils6.c srcs/dir_hooks.c srcs/free_utils.c \
		srcs/reprint.c srcs/dir_utils.c srcs/enemy_utils.c srcs/count_utils.c \
		srcs/utils7.c

OBJ = $(SRC:.c=.o)

LIBS = $(LIBFT)libft.a $(MLX)libmlx_Linux.a

MAKE = make -C

all : $(NAME)

$(NAME) : $(OBJ) $(LIBS)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT) -lft $(MLXFLAGS) -o $(NAME) -no-pie -lm

%.o: %.c includes/so_long.h
	$(CC) $(CFLAGS) -I$(LIBFT) -c $< -o $@

$(LIBFT)libft.a:
	$(MAKE) $(LIBFT)

$(MLX)libmlx_Linux.a:
	$(MAKE) $(MLX) > /dev/null 2>&1

clean :
	$(RM) $(OBJ)
	$(MAKE) $(LIBFT) clean

fclean : clean
	$(RM) $(NAME)
	$(MAKE) $(MLX) clean > /dev/null 2>&1

re : fclean all

.PHONY: all clean fclean re
