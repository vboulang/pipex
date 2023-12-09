# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/01 14:34:28 by vboulang          #+#    #+#              #
#    Updated: 2023/12/06 13:35:32 by vboulang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Program names
NAME		=	pipex

#Compiling variables
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -g #-fsanitize=address
LIBFLAGS	=	-L. -I. -lftprintf

#Directories
LIBDIR		=	libft
SRCDIR		=	src
INCDIR		=	inc
OBJDIR		=	obj

#Library names
LIBFT		=	$(LIBDIR)/libft.a

#.h files name
INC			=	$(INCDIR)/pipex.h

#Command lines
RM			=	rm -rf
MK			=	mkdir -p

#Source files

SRC			= 	pipex.c 

VPATH		=	$(SRCDIR)

#Object files
OBJ			=	$(addprefix $(OBJDIR)/,$(SRC:%.c=%.o))

all: $(NAME)

$(NAME):	$(OBJDIR) $(OBJ)
	@make -C $(LIBDIR)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJDIR)/%.o: %.c $(INC)
	$(CC) $(CFLAGS) -I$(INC) -I$(LIBDIR)/libft.h -c $< -o $@

$(OBJDIR):
	@$(MK) $(OBJDIR)

clean:
	$(RM) $(OBJDIR)
	@make -C $(LIBDIR) clean

fclean: clean
	$(RM) $(NAME)
	@make -C $(LIBDIR) fclean

re: fclean all

.PHONY: all clean fclean re
