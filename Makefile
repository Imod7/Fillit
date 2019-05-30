#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ravan-de <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/05/02 15:57:41 by ravan-de      #+#    #+#                  #
#    Updated: 2019/05/30 18:24:40 by ravan-de      ########   odam.nl          #
#                                                                              #
#******************************************************************************#

NAME = fillit

OBJ = ft_recursive.o fillit.o ft_read.o

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