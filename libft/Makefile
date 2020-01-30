# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpladet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 11:55:40 by gpladet           #+#    #+#              #
#    Updated: 2020/01/15 15:02:29 by gpladet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

PATH_H = ./libft.h

PATH_SRC = ./

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I $(PATH_H)

LIBS = -lm

SRCS = $(PATH_SRC)ft_memset.c $(PATH_SRC)ft_bzero.c $(PATH_SRC)ft_memcpy.c 
SRCS += $(PATH_SRC)ft_memccpy.c $(PATH_SRC)ft_memmove.c 
SRCS += $(PATH_SRC)ft_memchr.c $(PATH_SRC)ft_memcmp.c 
SRCS += $(PATH_SRC)ft_strlen.c $(PATH_SRC)ft_isalpha.c $(PATH_SRC)ft_isdigit.c 
SRCS += $(PATH_SRC)ft_isalnum.c $(PATH_SRC)ft_isascii.c $(PATH_SRC)ft_isprint.c
SRCS += $(PATH_SRC)ft_toupper.c $(PATH_SRC)ft_tolower.c $(PATH_SRC)ft_strchr.c
SRCS += $(PATH_SRC)ft_strrchr.c $(PATH_SRC)ft_strncmp.c $(PATH_SRC)ft_strlcpy.c
SRCS += $(PATH_SRC)ft_strlcat.c $(PATH_SRC)ft_strnstr.c $(PATH_SRC)ft_atoi.c
SRCS += $(PATH_SRC)ft_calloc.c $(PATH_SRC)ft_strdup.c $(PATH_SRC)ft_substr.c 
SRCS += $(PATH_SRC)ft_strjoin.c $(PATH_SRC)ft_strtrim.c $(PATH_SRC)ft_split.c
SRCS += $(PATH_SRC)ft_itoa.c $(PATH_SRC)ft_strmapi.c $(PATH_SRC)ft_putchar_fd.c
SRCS += $(PATH_SRC)ft_putstr_fd.c $(PATH_SRC)ft_putendl_fd.c $(PATH_SRC)ft_putnbr_fd.c

SRCSBONUS += $(PATH_SRC)ft_lstnew_bonus.c
SRCSBONUS += $(PATH_SRC)ft_lstadd_front_bonus.c $(PATH_SRC)ft_lstsize_bonus.c
SRCSBONUS += $(PATH_SRC)ft_lstlast_bonus.c $(PATH_SRC)ft_lstadd_back_bonus.c
SRCSBONUS += $(PATH_SRC)ft_lstdelone_bonus.c $(PATH_SRC)ft_lstclear_bonus.c
SRCSBONUS += $(PATH_SRC)ft_lstiter_bonus.c $(PATH_SRC)ft_lstmap_bonus.c

OBJ = $(SRCS:.c=.o)
OBJBONUS = $(SRCSBONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(PATH_H)
	ar rc $(NAME) $(OBJ)

bonus: $(OBJBONUS) $(PATH_H)
	ar rc $(NAME) $(OBJBONUS)

clean:
	/bin/rm -f $(OBJ) $(OBJBONUS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
