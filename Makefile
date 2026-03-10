# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: varandri <varandri@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/08 16:13:42 by varandri          #+#    #+#              #
#    Updated: 2026/03/10 11:53:15 by varandri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

LIBFT_DIR = libft

LIBFT = $(LIBFT_DIR)/libft.a

SRC = ft_str_toupper.c ft_printf.c ft_print_str.c \
		ft_print_hex.c ft_print_chr.c ft_print_int.c ft_print_ptr.c \
		ft_print_uint.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(LIBFT) :
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME) : $(OBJ) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar -rcs $(NAME) $(OBJ)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -f $(OBJ)

fclean : clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re : fclean $(NAME)

.PHONY : all clean fclean re