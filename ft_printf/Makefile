# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/30 11:08:24 by omoreno-          #+#    #+#              #
#    Updated: 2022/11/07 11:11:16 by omoreno-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c \
ft_delegates.c\
ft_delegates2.c\
ft_strlen.c\
ft_toupper.c\
ft_memcpy.c\
ft_strdup.c\
ft_itoa.c\
ft_putchar_fd.c\
ft_putstr_fd.c\
ft_putendl_fd.c\
ft_putnbr_fd.c


OBJ := $(SRC:.c=.o)
DEPS = $(SRC:.c=.d)
CC	= 	gcc
CFLAGS = -Wall -Werror -Wextra -MMD
RM	= 	rm -f
LIBC	= 	ar -rcs
HEADER = ft_printf.h

%.o : %.c ${HEADER}
	${CC} ${CFLAGS} -I ${HEADER} -c $< -o $@

all : $(NAME) 

-include: $(DEPS)
$(NAME) : $(OBJ) $(HEADER)
	$(LIBC) $(NAME) $(OBJ)

clean :
	$(RM) $(OBJ)
	$(RM) $(DEPS)

fclean : clean
	$(RM) $(NAME)

re: fclean all

.PHONY : clean fclean re all