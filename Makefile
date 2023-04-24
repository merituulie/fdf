# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/27 17:25:35 by meskelin          #+#    #+#              #
#    Updated: 2023/04/21 15:13:24 by meskelin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
LIBFT_PATH = ./libft

BUILD_FLAGS = -Wall -Wextra -Werror

COMMON_SRC = exit \
			file

MAP_SRC = vector \
		dimension \
		map_data \
		map_parse \
		img_data \
		mlx_win \
		put_pixel

LIST_SRC = lstnew \
		lstlast \
		lstadd \
		lstclear \
		lstsize \
		lstadd_to_vectors

SRC = run_fdf

COMMONSRCPRE = $(addprefix ./src/common/, $(COMMON_SRC))
COMMONSRCSUFF = $(addsuffix .c, $(COMMONSRCPRE))
LISTSRCPRE = $(addprefix ./src/list/, $(LIST_SRC))
LISTSRCSUFF = $(addsuffix .c, $(LISTSRCPRE))
MAPSRCPRE = $(addprefix ./src/map/, $(MAP_SRC))
MAPSRCSUFF = $(addsuffix .c, $(MAPSRCPRE))
SRCPRE = $(addprefix ./src/, $(SRC))
SRCSUFF = $(addsuffix .c, $(SRCPRE))

.PHONY = all
all: $(NAME)

$(NAME):
	make -C $(LIBFT_PATH)
	cc $(BUILD_FLAGS) main.c $(LISTSRCSUFF) $(COMMONSRCSUFF) $(MAPSRCSUFF) $(SRCSUFF) -lmlx -Llibft -lft -framework OpenGL -framework AppKit -o $(NAME)

.PHONY: clean
clean:
	make clean -C $(LIBFT_PATH)
	rm -f $(SRCSO)

.PHONY: fclean
fclean: clean
	make fclean -C $(LIBFT_PATH)
	rm -f $(NAME)

.PHONY: re
re: fclean all

