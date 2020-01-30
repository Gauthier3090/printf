# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpladet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/15 09:58:49 by gpladet           #+#    #+#              #
#    Updated: 2020/01/15 15:11:51 by gpladet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

LIBFT_PATH = ./libft/

INC_PATH = ./includes/

SRC_PATH = ./srcs/

OBJ_PATH = ./objs/

INC_NAME = *.h

LIBFT_NAME = libft.a

TEMP = .temp.a

LIB = $(addprefix $(LIBFT_PATH), $(LIBFT_NAME))

SRC_NAME =	ft_printf.c							\
			ft_printf_utils.c					\
			ft_handle_conversion.c				\
			ft_handle_flags.c					\
			ft_handle_specifier.c				\
			ft_handle_width.c					\
			ft_handle_precision.c				\
			ft_handle_output.c					\
			ft_handle_formatted.c				\
			ft_write_width.c					\
			ft_write_output.c					\
			ft_write_flags.c					\
			ft_write_width_and_precision.c		\
			ft_write_width_and_precision_more.c	\

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(sort $(addprefix $(SRC_PATH), $(SRC_NAME)))

INC = $(sort $(addprefix $(INC_PATH), $(INC_NAME)))

OBJ = $(sort $(addprefix $(OBJ_PATH), $(OBJ_NAME)))

all : $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_PATH)
	@echo "\033[91mCreation of $(NAME) ...\033[0m"
	@ar rc $(TEMP) $(OBJ)
	@libtool -static -o $(NAME) $(TEMP) $(LIB)
	@rm -f $(TEMP)
	@echo "\033[92m$(NAME) created\n\033[0m"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@make clean -C $(LIBFT_PATH)
	@echo "\033[91mDelete .o files of $(NAME) ...\033[0m"
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2>/dev/null || true
	@echo "\033[92mFiles .o deleted\n\033[0m"

fclean: clean
	@make fclean -C $(LIBFT_PATH)
	@echo "\033[91mDelete $(NAME)...\033[0m"
	@rm -f $(NAME)
	@echo "\033[92m$(NAME) deleted\n\033[0m"

run:
	@make
	@$(CC) $(CFLAGS) $(NAME) main.c
	@./a.out
re: fclean all

.PHONY: all, clean, fclean, re
