# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/09 05:04:40 by nabouzah          #+#    #+#              #
#    Updated: 2021/03/27 11:02:00 by ayagoumi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libcalculation.a
FLAGS= -Wall -Wextra -Werror
OBJDIR = ../../objs
SRCDIR= ./
OBJ= $(OBJDIR)/ft_crossproduct.o $(OBJDIR)/ft_magnitude.o\
$(OBJDIR)/ft_normalize.o $(OBJDIR)/ft_vector_const_add.o\
$(OBJDIR)/ft_vectoradd.o $(OBJDIR)/ft_vectorsub.o $(OBJDIR)/ft_dotproduct.o\
$(OBJDIR)/ft_negative.o $(OBJDIR)/ft_vector.o $(OBJDIR)/ft_vector_const_prod.o\
$(OBJDIR)/ft_vectorprod.o $(OBJDIR)/degree_to_rad.o $(OBJDIR)/cubic.o\
$(OBJDIR)/quadric.o $(OBJDIR)/quartic.o $(OBJDIR)/is_zero.o $(OBJDIR)/cbrt.o\
$(OBJDIR)/powd.o
INC = ../../includes/calculation/calc_functions.h

all	: $(NAME)

$(OBJDIR)/%.o : $(SRCDIR)%.c $(INC)
	@gcc $(FLAGS) -c -o $@ $< -I $(INC)
	@ar rc $(NAME) $@

$(NAME) : $(OBJ)
	@ranlib $(NAME)
	@printf "\033[0;32m"
	@printf "CALCULATION.a CREATED\n"
	@printf "\033[0m"

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all
