# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/30 11:08:24 by omoreno-          #+#    #+#              #
#    Updated: 2022/10/31 12:02:10 by omoreno-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c \
ft_delegates.c

OBJ := $(SRC:.c=.o)
DEPS = $(SRC:.c=.d)
CC	= 	gcc
CFLAGS = -Wall -Werror -Wextra -MMD
RM	= 	rm -f
LIBC	= 	ar -rcs
LIBFT = libft/libft.a
HEADER = ft_printf.h

%.o : %.c ${HEADER}
	${CC} ${CFLAGS} -I ${HEADER} -c $< -o $@

all : $(NAME) 

$(LIBFT) :
	make -Clibft bonus

-include: $(DEPS)
$(NAME) : $(OBJ) $(HEADER) $(LIBFT)
	$(LIBC) $(NAME) $(OBJ) $(LIBFT)

clean :
	$(RM) $(OBJ)
	$(RM) $(DEPS)
	make -Clibft clean


fclean : clean
	$(RM) $(NAME)
	make -Clibft fclean

re: fclean all

.PHONY : clean fclean re all $(LIBFT)