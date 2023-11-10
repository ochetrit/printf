# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ochetrit <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 09:42:34 by ochetrit          #+#    #+#              #
#    Updated: 2023/11/09 09:47:22 by ochetrit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_format.c ft_write.c ft_printf.c

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

CC = cc

RM = rm -f

FLAGS = -Wall -Wextra -Werror

$(NAME):  $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) -c $(FLAGS) $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
