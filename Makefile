# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frajaona <frajaona@student.42antanana      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/12 15:47:39 by frajaona          #+#    #+#              #
#    Updated: 2024/06/24 09:52:02 by frajaona         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fahaleovantena

MLX = lib/minilibx-linux/libmlx.a

GNL =	lib/gnl/get_next_line_utils.c lib/gnl/get_next_line.c

SRC = 	src/map/map_utils.c src/map/map_read.c src/map/map_initialization.c src/map/map.c\
		src/quiz/quiz.c\
		src/audio/audio.c\
		src/graphique/window.c src/graphique/draw.c src/graphique/image.c\
		src/setting/input.c src/setting/action.c src/setting/check.c\
		src/fahaleovantena.c

OBJG = ${GNL:.c=.o}

OBJS = ${SRC:.c=.o}

FLAG = -Wall -Wextra -Werror

INC = -I include

MLXF = -lXext -lX11 -lm

SDL = -lSDL2

$(NAME) :  $(OBJG) $(OBJS)
	@make -C lib/minilibx-linux
	cc $(FLAG) $(OBJG) $(OBJS) $(INC) $(MLX)  -I/usr/include/SDL2 -D_REENTRANT -lSDL2 -o $(NAME) $(MLXF)

all : $(NAME)

clean :
	rm -f $(OBJG)
	rm -f $(OBJS)

fclean : clean
		rm -f $(NAME)

re : fclean all
