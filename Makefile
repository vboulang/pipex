# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vincent <vincent@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/01 14:34:28 by vboulang          #+#    #+#              #
#    Updated: 2024/01/10 15:38:12 by vincent          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Program names
NAME		=	pipex
NAME_BONUS	=	pipex_bonus

#Compiling variables
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -g #-fsanitize=address

#Directories
LIBDIR			=	libft
SRCDIR			=	src
INCDIR			=	inc
OBJDIR			=	obj
SRCDIR_BONUS	=	bonus

#Library names
LIBFT		=	$(LIBDIR)/libft.a

#.h files name
INC			=	$(INCDIR)/pipex.h
INC_BONUS	=	$(INCDIR)/pipex_bonus.h

#Command lines
RM			=	rm -rf
MK			=	mkdir -p

#Source files

SRC			= 	pipex.c 

SRC_BONUS	=	pipex_bonus.c

VPATH		=	$(SRCDIR) $(SRCDIR_BONUS)

#Object files
OBJ			=	$(addprefix $(OBJDIR)/,$(SRC:%.c=%.o))
OBJ_BONUS	=	$(addprefix $(OBJDIR)/,$(SRC_BONUS:%.c=%.o))

all: $(NAME)

$(NAME):	$(OBJDIR) $(OBJ)
	make -C $(LIBDIR)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJDIR)/%.o: %.c $(INC)
	$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBDIR)/inc -c $< -o $@

$(OBJDIR):
	$(MK) $(OBJDIR)

bonus: $(NAME_BONUS)

$(NAME_BONUS):	$(OBJDIR) $(OBJ_BONUS)
	make -C $(LIBDIR)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) -o $(NAME_BONUS)

$(OBJDIR)/%.o: %.c $(INC_BONUS)
	$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBDIR)/inc -c $< -o $@
	
clean:
	$(RM) $(OBJDIR)
	make -C $(LIBDIR) clean

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)
	make -C $(LIBDIR) fclean

re: fclean all

.PHONY: all clean fclean re
