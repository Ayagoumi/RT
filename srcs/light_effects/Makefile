# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/09 05:04:40 by nabouzah          #+#    #+#              #
#    Updated: 2021/03/26 15:43:33 by ayagoumi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = liblights.a
FLAGS= -Wall -Wextra -Werror
OBJDIR = ../../objs
SRCDIR= ./
OBJ= $(OBJDIR)/ambient.o $(OBJDIR)/diffuse.o $(OBJDIR)/lights.o\
	 $(OBJDIR)/lights2.o $(OBJDIR)/shadows.o $(OBJDIR)/specular.o\
	 $(OBJDIR)/textures.o $(OBJDIR)/textures_wave_effect.o \
	 $(OBJDIR)/direct_light.o $(OBJDIR)/textures2.o

INC = ../../includes/
INC1 = ../../includes/functions.h
INC2 = ../../includes/define.h
INC5 = ../../includes/struct.h
INC3 = ../../includes/rt.h

all	: $(NAME)

$(OBJDIR)/%.o : $(SRCDIR)%.c $(INC) $(INC1) $(INC2) $(INC5) $(INC3)
	@gcc $(FLAGS) -c -o $@ $< -I $(INC)
	@ar rc $(NAME) $@

$(NAME) : $(OBJ)
	@ranlib $(NAME)
	@printf "\033[0;32m"
	@printf "LIBLIGHT.a CREATED\n"
	@printf "\033[0m"

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all
