# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matruman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/17 14:12:57 by matruman          #+#    #+#              #
#    Updated: 2019/11/08 15:00:13 by matruman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c\
		  ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c\
		  ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c\
		  ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c\
		  ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c\
		  ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c\
		  ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c\
		  ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c\
		  ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c\
		  ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c\
		  ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c\
		  ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c\
		  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
		  ft_putnbr_fd.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c\
		  ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_lstcutelem.c\
		  ft_putstrn.c ft_fstrncpy.c\
		  ft_explode.c smart_malloc.c file_get_content.c\
		  gnl/get_next_line.c\
		  \
		  ft_printf/src/ft_itoa_base.c\
		  ft_printf/src/ft_printf.c\
		  ft_printf/src/get_format.c\
		  ft_printf/src/get_format_list.c\
		  ft_printf/src/pf_helps.c\
		  ft_printf/src/pf_helps1.c\
		  ft_printf/src/print_conv_di.c\
		  ft_printf/src/print_format.c\
		  ft_printf/src/print_conv_pouxx.c\
		  ft_printf/src/print_conv_cp.c\
		  ft_printf/src/print_conv_s.c\
		  ft_printf/src/get_fl.c\
		  ft_printf/src/print_conv_float.c\
		  ft_printf/src/buffer.c\
		  ft_printf/src/long_arithmetic/big_int_print.c\
		  ft_printf/src/long_arithmetic/la_helps.c\
		  ft_printf/src/long_arithmetic/multiplication.c\
		  ft_printf/src/long_arithmetic/pow_mult.c\
		  ft_printf/src/long_arithmetic/read_long_long.c

CC = gcc
HEADER_DIR	=	includes/
HEADER		=	includes/libft.h\
				includes/ft_printf.h\
				includes/ft_printf_lib.h\
				includes/long_arithmetic.h\
				includes/get_next_line.h

CFLAGS = -Wall -Wextra -Werror -I $(HEADER_DIR)

OBJ = $(patsubst %.c,%.o,$(SRC))

%.o: %.c $(HEADER)
	gcc -c $(CFLAGS) $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
