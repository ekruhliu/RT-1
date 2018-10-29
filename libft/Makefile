# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/30 12:34:38 by ekruhliu          #+#    #+#              #
#    Updated: 2017/10/30 12:34:40 by ekruhliu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEADER = ./libft.h
FLAGS = -Wall -Wextra -Werror
SRC = ./ft_isalpha.c ./ft_memchr.c ./ft_strcat.c ./ft_strlcat.c ./ft_strnstr.c \
		./ft_isascii.c ./ft_memcmp.c ./ft_strchr.c ./ft_strlen.c ./ft_strrchr.c \
		./ft_atoi.c ./ft_isdigit.c ./ft_memcpy.c ./ft_strcmp.c ./ft_strncat.c	\
		./ft_strstr.c ./ft_bzero.c ./ft_isprint.c ./ft_memmove.c ./ft_strcpy.c \
		./ft_strncmp.c ./ft_tolower.c ./ft_isalnum.c ./ft_memccpy.c ./ft_memset.c \
		./ft_strdup.c ./ft_strncpy.c ./ft_toupper.c ./ft_memalloc.c ./ft_memdel.c \
		./ft_strnew.c ./ft_strdel.c ./ft_strclr.c ./ft_striter.c  ./ft_striteri.c \
		./ft_strmap.c ./ft_strmapi.c ./ft_strequ.c ./ft_strnequ.c ./ft_strsub.c \
		./ft_strjoin.c ./ft_strtrim.c ./ft_strsplit.c ./ft_itoa.c ./ft_putchar.c \
		./ft_putstr.c ./ft_putendl.c ./ft_putnbr.c ./ft_putchar_fd.c ./ft_putstr_fd.c \
		./ft_putendl_fd.c ./ft_putnbr_fd.c ./ft_lstnew.c ./ft_lstdelone.c ./ft_middle.c \
		./ft_lstdel.c ./ft_lstadd.c ./ft_lstiter.c ./ft_lstmap.c ./ft_isnegative.c \
		./ft_strnlen.c ./ft_same_symbol.c ./ft_swap.c ./exit_x.c ./get_next_line.c \
		./ft_ftoa.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		@ ar rc $(NAME) $(OBJ)
		@ ranlib $(NAME)

%.o: %.c $(HEADER)
		@ gcc $(FLAGS) -o $@ -c $< -I$(HEADER)
clean:
		@ /bin/rm -f $(OBJ)
		
fclean: clean
		@ /bin/rm -f $(NAME)

re: fclean all
