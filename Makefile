# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/01 15:27:01 by vboulang          #+#    #+#              #
#    Updated: 2023/11/08 11:13:46 by vboulang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRC	= 	ft_printf.c \
		ft_hexa.c \
		ft_putnbr_fd_return.c \
		ft_putstr_fd_return.c \
		ft_strlen.c \
		ft_putchar_fd.c \
		ft_hexa_add.c \
		ft_putnbr_ui_return.c

OBJ	=	$(SRC:.c=.o)

AR	=	ar

CC	=	gcc

CFLAGS	=	-Wall -Werror -Wextra #-fsanitize=address

LIBFLAGS	=	-L. -I. -lftprintf

RM	=	rm -f

all: $(NAME)

$(NAME):	$(OBJ)
	$(AR) -rcs $(NAME) $?

test: all
	$(CC) $(CFLAGS) $(LIBFLAGS) main.c -o test
	
%.o: %.c
	$(CC) -c $(CFLAGS) $?	

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re test
