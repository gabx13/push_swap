# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/03 17:28:00 by vgabovs           #+#    #+#              #
#    Updated: 2023/10/25 00:37:08 by vgabovs          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS = checker

SRCS = $(wildcard main.c src/*.c)

OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

SRC_DIR = src

OBJ_DIR = obj

SRC_BONUS = $(wildcard bonus/*.c src/*.c)

SRC_BONUS_DIR = bonus

BONUS_OBJ = $(SRC_BONUS:%.c=$(OBJ_DIR)/%.o)

INC_DIR = inc

CC = cc

CCS = $(CC) -g -fsanitize=address

CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR)

LIBFTDIR = ./inc/libft

LIBFTA = $(LIBFTDIR)/libftprintf.a

PUSH_SWAP_INC = inc/push_swap.h

VALG = valgrind --leak-check=full --show-leak-kinds=all

AT = leaks -atExit --

RM = rm -rf

ARGS ?= 4 2 3 1

NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'
WARNING='\033[33m'

USE_SANITIZER ?= 1

ifeq ($(USE_SANITIZER), 1)
	CCFLAGS = $(CCS)
else
	CCFLAGS = $(CC)
endif

all: $(NAME)

$(NAME): $(LIBFTA) $(SRCS) $(OBJS)
	@$(CCFLAGS) $(OBJS) $(LIBFTA) -o $@
	@echo $(GREEN)"- Compiled -"$(NONE)

$(OBJ_DIR)/%.o:%.c $(PUSH_SWAP_INC) $(LIBFTA)
	@echo $(CURSIVE)$(GRAY) "     - Building $<" $(NONE)
	@mkdir -p $(dir $@)
	@if [ "$(USE_SANITIZER)" = "1" ]; then $(CCS) $(CFLAGS) -c $< -o $@ ; else $(CC) $(CFLAGS) -c $< -o $@ ; fi

$(LIBFTA):
	@make all -C $(LIBFTDIR)

$(BONUS): $(LIBFTA) $(SRCS) $(SRC_BONUS) $(BONUS_OBJ)
	@$(CCFLAGS) $(BONUS_OBJ) $(LIBFTA) -o $@
	@echo $(GREEN)"- Bonus Compiled -"$(NONE)

bonus: USE_SANITIZER = 0
bonus: $(BONUS)

val: USE_SANITIZER = 0
val: fclean $(LIBFTA) $(SRCS) $(OBJS)
	@$(CC) $(OBJS) $(LIBFTA) -o $(NAME)
	@$(VALG) ./$(NAME) $(ARGS)
	@echo $(GREEN)"- Compiled with valgrind-"$(NONE)

at: USE_SANITIZER = 0
at: fclean $(LIBFTA) $(SRCS) $(OBJS)
	@$(CC) $(OBJS) $(LIBFTA) -o $(NAME)
	@$(AT) ./$(NAME) $(ARGS)
	@echo $(GREEN)"- Compiled with atExit-"$(NONE)

h:
	@echo '------ make at ARGS=" "  ------'
	@echo '------ make val ARGS=" " ------'
	@echo '------ make test3 5 100 500 ------'

clean:
	@$(RM) $(OBJS) $(OBJ_DIR)
	@make -C $(LIBFTDIR) clean
	@echo $(CURSIVE)$(GRAY) "     - Object files removed" $(NONE)

fclean: clean
	@rm -f $(NAME) $(BONUS)
	@make -C $(LIBFTDIR) fclean
	@echo $(CURSIVE)$(GRAY) "     - $(NAME) & $(BONUS) removed" $(NONE)

re: fclean all

test: $(NAME)
	$(eval ARG = $(shell jot -r 100 -2147483648 2147483647))
	@./push_swap $(ARG)
	@echo $(WARNING)"Iteration count: "$(NONE)
	@./push_swap $(ARG) | wc -l

test3: $(NAME)
	$(eval ARG = $(shell jot -r 3 -2147483648 2147483647))
	@echo $(GREEN)""; ./push_swap $(ARG) | ./checker_Mac $(ARG)
	@echo $(WARNING)"Iteration count: "
	@./push_swap $(ARG) | wc -l

test5: $(NAME)
	$(eval ARG = $(shell jot -r 5 -2147483648 2147483647))
	@echo $(GREEN)""; ./push_swap $(ARG) | ./checker_Mac $(ARG)
	@echo $(WARNING)"Iteration count: "
	@./push_swap $(ARG) | wc -l

test20: $(NAME)
	$(eval ARG = $(shell jot -r 21 -2147483648 2147483647))
	@echo $(GREEN)""; ./push_swap $(ARG) | ./checker_Mac $(ARG)
	@echo $(WARNING)"Iteration count: "
	@./push_swap $(ARG) | wc -l

test100: $(NAME)
	$(eval ARG = $(shell jot -r 100 -2147483648 2147483647))
	@echo $(GREEN)""; ./push_swap $(ARG) | ./checker_Mac $(ARG)
	@echo $(WARNING)"Iteration count: "
	@./push_swap $(ARG) | wc -l

test500: $(NAME)
	$(eval ARG = $(shell jot -r 500 -2147483648 2147483647))
	@echo $(GREEN)""; ./push_swap $(ARG) | ./checker_Mac $(ARG)
	@echo $(WARNING)"Iteration count: "
	@./push_swap $(ARG) | wc -l

.PHONY: all bonus val at re h clean fclean test test3 test5 test100 test500
