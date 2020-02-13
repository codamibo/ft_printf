# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: iboeters <iboeters@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/02/06 11:35:24 by iboeters       #+#    #+#                 #
#    Updated: 2020/02/11 10:24:08 by iboeters      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c \
	printf_utils.c \
	handle_int.c \
	handle_uns.c \
	handle_hex.c \
	handle_char.c \
	handle_str.c \
	handle_ptr.c \
	handle_n.c \
	handle_percent.c

SRCB = ft_printf_bonus.c \
 	printf_utils_bonus.c \
 	handle_int_bonus.c \
 	handle_uns_bonus.c \
 	handle_hex_bonus.c \
 	handle_char_bonus.c \
 	handle_str_bonus.c \
 	handle_ptr_bonus.c \
 	handle_n_bonus.c \
	handle_percent_bonus.c

OBJ = $(SRC:.c=.o)

OBJB = $(SRCB:.c=.o)

INC = ./ft_printf.h

INCB = ./ft_printf_bonus.h

all: $(NAME)

$(NAME): $(OBJ)
		@make -C ./libft
		@cp ./libft/libft.a $(NAME)
		gcc -Wall -Werror -Wextra -c $(SRC) $(INC) ./libft/libft.h
		ar -rc $(NAME) $(OBJ) ./libft/libft.a

bonus: $(OBJB)
		@make -C ./libft
		@cp ./libft/libft.a $(NAME)
		gcc -Wall -Werror -Wextra -c $(SRCB) $(INCB) ./libft/libft.h
		ar -rc $(NAME) $(OBJB) ./libft/libft.a

clean:
		@make clean -C ./libft
		/bin/rm -f $(OBJ) $(OBJB)
		/bin/rm -f libftprintf.h.gch

fclean: clean
		@make fclean -C ./libft
		/bin/rm -f $(NAME)

re: fclean all
