# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaboukha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/30 15:11:48 by aaboukha          #+#    #+#              #
#    Updated: 2020/01/30 17:55:38 by aaboukha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
SRC		=	filling_spaces.c ft_strchr.c      ft_percent.c\
			ft_substr.c      ft_stars.c       ft_print.c\
	 		ft_putchar.c     flag_minus.c     ft_p.c\
	 		ft_strdup.c      ft_atoi.c        ft_printf.c\
	  		ft_putstr.c      ft_strlen.c      ft_character.c\
			ft_itoa.c        ft_itoa_precision.c   ft_x.c\
			ft_uitoa.c       ft_uitoa_precision.c   ft_u.c\
		    dtoex.c          ft_to_upper.c        ft_integer.c\
		    ft_nb_digit.c    ft_string.c           dtoex_prec.c
OBJ		=	$(SRC:.c=.o)
F		=	-Wall -Wextra -Werror
H		=	ft_printf.h

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ): $(SRC) $(H)
	cc $(F) -c $(SRC)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
