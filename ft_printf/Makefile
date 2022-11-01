# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/30 11:08:24 by omoreno-          #+#    #+#              #
#    Updated: 2022/11/01 11:51:21 by omoreno-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c \
ft_delegates.c \
ft_delegates2.c

OBJ := $(SRC:.c=.o)
DEPS = $(SRC:.c=.d)
CC	= 	gcc
CFLAGS = -Wall -Werror -Wextra -MMD
RM	= 	rm -f
LIBC	= 	ar -rcs
LIBFT = libft/libft.a
HEADER = ft_printf.h
LIBFT_H = libft/libft.h

%.o : %.c ${HEADER}
	${CC} ${CFLAGS} -I ${HEADER} -c $< -o $@

all : makelibft $(NAME)

makelibft:
	make -Clibft bonus

$(LIBFT) : makelibft

-include: $(DEPS)
$(NAME) : $(LIBFT) $(OBJ) $(HEADER) $(LIBFT_H)
	cp  -f $(LIBFT) $(NAME)
	$(LIBC) $(NAME) $(OBJ)

clean :
	$(RM) $(OBJ)
	$(RM) $(DEPS)
	make -Clibft clean


fclean : clean
	$(RM) $(NAME)
	$(RM) link
	make -Clibft fclean

re: fclean all

.PHONY : clean fclean re all makelibft