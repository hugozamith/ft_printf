# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hteixeir <hteixeir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/26 10:09:06 by hteixeir          #+#    #+#              #
#    Updated: 2024/06/25 12:30:30 by hteixeir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC	=		wwriter.c print_str.c print_int.c print_char.c ft_strlen.c \
			ft_strchrr.c ft_printf.c ft_memiset.c format_utils.c format_handler.c

OBJS = $(SRC:.c=.o)

BONUS_OBJS = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
AR = ar crs

NAME = libftprintf.a

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)	

all: $(NAME)

bonus:	all

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean:	clean
	$(RM) $(NAME)		

re:	fclean all

.PHONY:	all clean fclean re bonus