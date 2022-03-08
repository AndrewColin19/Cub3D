# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmataris <lmataris@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/09 17:07:04 by lmataris          #+#    #+#              #
#    Updated: 2022/03/08 13:03:56 by lmataris         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS=-Wall -Wextra -Werror \
					-fomit-frame-pointer -mtune=native \
					-msse4.2 -mfpmath=sse -march=native \
					-funsafe-math-optimizations -funroll-loops \
					-ffast-math -flto
CLINK= -framework OpenGL -framework AppKit #-fsanitize=address

SRCS= 	srcs/main.c srcs/parsing/valid_map.c srcs/parsing/parse_map.c \
		srcs/utils/ft_split.c srcs/utils/ft_utils.c srcs/utils/get_next_line.c \
		srcs/parsing/check_map.c srcs/utils/ft_str.c srcs/draw_map.c \
		srcs/ray.c srcs/player.c srcs/ft_event.c srcs/texture.c

SRCS_BONUS= 	srcs_bonus/main.c srcs_bonus/parsing/valid_map.c srcs_bonus/parsing/parse_map.c \
				srcs_bonus/utils/ft_split.c srcs_bonus/utils/ft_utils.c srcs_bonus/utils/get_next_line.c \
				srcs_bonus/parsing/check_map.c srcs_bonus/utils/ft_str.c srcs_bonus/draw_utils.c  srcs_bonus/draw.c \
				srcs_bonus/ray.c srcs_bonus/player.c srcs_bonus/ft_event.c srcs_bonus/texture.c srcs_bonus/ft_bonus.c \
				srcs_bonus/ft_key_event.c

OBJ=$(SRCS:.c=.o)
OBJS_BONUS=$(SRCS_BONUS:.c=.o)

ifndef BONUS
NAME= cub3D
OBJS=$(SRCS:.c=.o)
else
NAME= cub3D_bonus
OBJS=$(SRCS_BONUS:.c=.o)
endif

NAMEM= cub3D
NAME_BONUS= cub3D_bonus

all:$(NAME)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

$(NAME):$(OBJS)
	gcc $(CFLAGS) $(CLINK) $(OBJS) libmlx.a -o $(NAME)

bonus:
	@make BONUS=1

clean:
	rm -f $(OBJ) $(OBJS_LIB) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAMEM) $(NAME_BONUS)

re: fclean all

reb: fclean bonus

run: re
	./cub3D map.cub
runb: reb
	./cub3D_bonus mapb.cub
