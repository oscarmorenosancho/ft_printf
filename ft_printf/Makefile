# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/30 11:08:24 by omoreno-          #+#    #+#              #
#    Updated: 2022/10/30 12:47:50 by omoreno-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c

OBJ := $(SRC:.c=.o)
DEPS = $(SRC:.c=.d)
CC	= 	gcc
CFLAGS = -Wall -Werror -Wextra -MMD
RM	= 	rm -f
LIBC	= 	ar -rcs
HEADER = ft_printf.h
LIBFT = libft/libft.a

%.o : %.c ${HEADER}
	${CC} ${CFLAGS} -I ${HEADER} -c $< -o $@

all : $(NAME) 

$(LIBFT) :
	make -f libft/Makefile
	
-include: $(DEPS)
$(NAME) : $(OBJ) $(HEADER) $(LIBFT)
	$(LIBC) $(NAME) $(OBJ) $(LIBFT)

clean :
	$(RM) $(OBJ)
	$(RM) $(DEPS)

fclean : clean
	$(RM) $(NAME)

re: fclean all

.PHONY : clean fclean re all