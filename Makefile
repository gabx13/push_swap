# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/03 17:28:00 by vgabovs           #+#    #+#              #
#    Updated: 2023/10/17 23:51:09 by vgabovs          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = $(wildcard main.c src/*.c)

SRC_DIR = src

OBJ_DIR = obj

INC_DIR = inc

OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

CC = cc

CCS = $(CC) -g -fsanitize=address -fno-omit-frame-pointer

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
	@rm -f $(NAME)
	@make -C $(LIBFTDIR) fclean
	@echo $(CURSIVE)$(GRAY) "     - $(NAME) removed" $(NONE)

re: fclean all

test: $(NAME)
	$(eval ARG = $(shell jot -r 30 -1000 40000))
	@./push_swap $(ARG)
	@echo $(WARNING)"Instructions: "$(NONE)
	@./push_swap $(ARG) | wc -l

test3: $(NAME)
	$(eval ARG = $(shell jot -r 3 -1000 40000))
	@./push_swap $(ARG) | ./checker_Mac $(ARG)
	@echo $(WARNING)"Instructions: "$(NONE)
	@./push_swap $(ARG) | wc -l

test5: $(NAME)
	$(eval ARG = $(shell jot -r 5 -10000 40000))
	@./push_swap $(ARG) | ./checker_Mac $(ARG)
	@echo "Instructions: "; ./push_swap $(ARG) | wc -l
# @./push_swap $(ARG) | wc -l

test20: $(NAME)
	$(eval ARG = $(shell jot -r 21 -10000 40000))
	@./push_swap $(ARG) | ./checker_Mac $(ARG)
	@echo "Instructions: "; ./push_swap $(ARG) | wc -l

test100: $(NAME)
	$(eval ARG = $(shell jot -r 100 -1000000 1000000))
	@./push_swap $(ARG) | ./checker_Mac $(ARG)
	@echo "Instructions: "
	@./push_swap $(ARG) | wc -l

test500: $(NAME)
	$(eval ARG = $(shell jot -r 500 -1000000 4000000))
	@./push_swap $(ARG) | ./checker_Mac $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

#####################################

# NAME = push_swap
# SRCS = $(wildcard main.c src/*.c)
# SRC_DIR = src
# OBJ_DIR = obj
# OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)
# CC = cc
# CCS = cc -fsanitize=address -g
# CFLAGS = -Wall -Wextra -Werror
# LIBFTDIR = ./inc/libft
# LIBFTA = $(LIBFTDIR)/libftprintf.a
# VALG = valgrind --leak-check=full
# AT = leaks -atExit --
# RM = rm -rf
# ARGS ?= 4 2 3 1
# NONE = '\033[0m'
# GREEN = '\033[32m'
# GRAY = '\033[2;37m'
# CURSIVE = '\033[3m'
# WARNING = '\033[33m'

# # By default, USE_SANITIZER is set to 1
# USE_SANITIZER ?= 1

# ifeq ($(USE_SANITIZER), 1)
# 	CC := $(CCS)
# endif

# all: $(NAME)

# $(NAME): $(LIBFTA) $(SRCS) $(OBJS)
# 	@ $(CCS) $(OBJS) $(LIBFTA) -o $@
# 	@echo CCFLAGS $(CCFLAGS)
# 	@echo $(GREEN) "- Compiled -" $(NONE)

# $(OBJ_DIR)/%.o: %.c $(LIBFTA)
# 	@echo $(CURSIVE)$(GRAY) "     - Building $<" $(NONE)
# 	@mkdir -p $(dir $@)
# 	@echo USE_SANITIZER =$(USE_SANITIZER)-
# 	@echo CCFLAGS $(CC)
# 	@$(CC) $(CFLAGS) -c $< -o $@
# # ifeq ($(USE_SANITIZER),0)
# # 	$(CCS) $(CFLAGS) -c $< -o $@
# # 	@echo "linked CCS" $(USE_SANITIZER)
# # else
# # 	$(CC) $(CFLAGS) -c $< -o $@
# # 	@echo "linked CC" $(USE_SANITIZER)
# # endif


# $(LIBFTA):
# 	@make all -C $(LIBFTDIR)

# # Set USE_SANITIZER to 0 only when building val or at
# val: USE_SANITIZER = 0
# val: fclean $(LIBFTA) $(SRCS) $(OBJS)
# 	@$(CC) $(OBJS) $(LIBFTA) -o $(NAME)
# 	@echo USE_SANITIZER in VAL=$(USE_SANITIZER)-
# # @$(VALG) ./$(NAME) $(ARGS)

# at: USE_SANITIZER = 0
# at: fclean $(LIBFTA) $(SRCS) $(OBJS)
# 	@$(CC) $(OBJS) $(LIBFTA) -o $(NAME)
# 	@$(AT) ./$(NAME) $(ARGS)

# h:
# 	@echo '------ make at ARGS=" "  ------'
# 	@echo '------ make val ARGS=" " ------'

# clean:
# 	@$(RM) $(OBJS) $(OBJ_DIR)
# 	@make -C $(LIBFTDIR) clean
# 	@echo $(CURSIVE)$(GRAY) "     - Object files removed" $(NONE)

# fclean: clean
# 	@rm -f $(NAME)
# 	@make -C $(LIBFTDIR) fclean
# 	@echo $(CURSIVE)$(GRAY) "     - $(NAME) removed" $(NONE)

# re: fclean all


# # NAME = push_swap
# # SRCS = $(wildcard main.c src/*.c)
# # SRC_DIR = src
# # OBJ_DIR = obj
# # OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)
# # CC = cc
# # CCS = cc -fsanitize=address -g
# # CFLAGS = -Wall -Wextra -Werror
# # LIBFTDIR = ./inc/libft
# # LIBFTA = $(LIBFTDIR)/libftprintf.a
# # VALG = valgrind --leak-check=full
# # AT = leaks -atExit --
# # RM = rm -rf
# # ARGS ?= 4 2 3 1
# # NONE = '\033[0m'
# # GREEN = '\033[32m'
# # GRAY = '\033[2;37m'
# # CURSIVE = '\033[3m'
# # WARNING = '\033[33m'

# # # By default, USE_SANITIZER is set to 1
# # USE_SANITIZER ?= 1

# # all: $(NAME)

# # ifeq ($(USE_SANITIZER), 1)
# # 	CCFLAGS := $(CCS)
# # else
# # 	CCFLAGS := $(CC)
# # endif

# # $(NAME): $(LIBFTA) $(SRCS) $(OBJS)
# # 	@$(CCFLAGS) $(OBJS) $(LIBFTA) -o $@
# # 	@echo "CCFLAGS: $(CCFLAGS)"
# # 	@echo $(GREEN) "- Compiled -" $(NONE)

# # $(OBJ_DIR)/%.o: %.c $(LIBFTA)
# # 	@echo $(CURSIVE)$(GRAY) "     - Building $<" $(NONE)
# # 	@mkdir -p $(dir $@)
# # 	@echo "USE_SANITIZER = $(USE_SANITIZER)"
# # 	@echo "CCFLAGS: $(CCFLAGS)"
# # 	@$(CCFLAGS) $(CFLAGS) -c $< -o $@

# # $(LIBFTA):
# # 	@make all -C $(LIBFTDIR)

# # # Set USE_SANITIZER to 0 only when building val or at
# # val: USE_SANITIZER = 0
# # val: fclean $(LIBFTA) $(SRCS) $(OBJS)
# # 	@$(CCFLAGS) $(OBJS) $(LIBFTA) -o $(NAME)
# # 	@echo "USE_SANITIZER in VAL: $(USE_SANITIZER)"
# # 	@echo "CCFLAGS: $(CCFLAGS)"

# # at: USE_SANITIZER = 0
# # at: fclean $(LIBFTA) $(SRCS) $(OBJS)
# # 	@$(CCFLAGS) $(OBJS) $(LIBFTA) -o $(NAME)
# # 	@$(AT) ./$(NAME) $(ARGS)

# # h:
# # 	@echo '------ make at ARGS=" "  ------'
# # 	@echo '------ make val ARGS=" " ------'

# # clean:
# # 	@$(RM) $(OBJS) $(OBJ_DIR)
# # 	@make -C $(LIBFTDIR) clean
# # 	@echo $(CURSIVE)$(GRAY) "     - Object files removed" $(NONE)

# # fclean: clean
# # 	@rm -f $(NAME)
# # 	@make -C $(LIBFTDIR) fclean
# # 	@echo $(CURSIVE)$(GRAY) "     - $(NAME) removed" $(NONE)

# # re: fclean all
