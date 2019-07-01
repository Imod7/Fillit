#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ravan-de <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/05/02 15:57:41 by ravan-de      #+#    #+#                  #
#    Updated: 2019/07/01 16:19:03 by ravan-de      ########   odam.nl          #
#                                                                              #
#******************************************************************************#

NAME = fillit

OBJ = ft_printboard.o ft_readtet.o ft_shiftsave.o ft_initialize_board.o \
		ft_print.o ft_isvalid.o ft_solver.o fillit.o ft_free.o

FLAGS = -Wall -Wextra -Werror

INCL = libft/includes

LIB = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(FLAGS) $(OBJ) $(LIB)  

%.o: %.c
	gcc -c $(FLAGS) -I $(INCL) $<

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

doei: clean
	rm -f *~
	rm -f *#
