# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwrzosek <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/11 15:45:52 by kwrzosek          #+#    #+#              #
#    Updated: 2025/01/26 22:17:36 by kwrzosek         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c printf_utils.c
OBJS = $(SRC:.c=.o)
NAME = libftprintf.a
AR = ar rcs

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJS) $(BOBJS)

fclean:
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
