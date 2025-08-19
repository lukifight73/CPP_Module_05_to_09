# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbenatar <lbenatar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/09 15:05:53 by lbenatar          #+#    #+#              #
#    Updated: 2025/04/07 12:12:04 by lbenatar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

YO      = c++
CFLAGS  = -Wall -Werror -Wextra -std=c++98
NAME	= temp
SRC	= main.cpp \

OBJ     = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(YO) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(YO) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
