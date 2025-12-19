# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/19 01:39:22 by asoria            #+#    #+#              #
#    Updated: 2025/12/19 02:26:36 by asoria           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libftprintf.a
CC		?= cc
CFLAGS		:= -Wall -Wextra -Werror -Wpedantic
CPPFLAGS	:= -Iincludes
AR		?= ar
ARFLAGS		?= rcs
RM		?= rm
SRC_DIR		:= src
OBJ_DIR		:= obj

SRC := \
	ft_printf.c \
	printf_print_addr.c \
	printf_print_hex.c \
	printf_print_unsigned.c \
	printf_putchar.c \
	printf_putnbr.c \
	printf_putstr.c

OBJ := $(SRC:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c includes/ft_printf.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) -rf $(OBJ_DIR)

fclean:
	$(MAKE) clean
	$(RM) -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
