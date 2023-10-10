# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/18 18:13:39 by vgabovs           #+#    #+#              #
#    Updated: 2023/10/04 21:18:48 by vgabovs          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c itoa_base.c put_d.c helper.c put_hcsp.c put_ux.c flags_bonus.c

BONUS_SRC = flags_bonus.c

CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

B_OBJ = $(BONUS_SRC:.c=.o)

CC = cc

LIBFT = ./libft

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT)
	@cp ./libft/libft.a .
	@mv libft.a $(NAME)
	@ar -rcs $(NAME) $(OBJ) $(B_OBJ)

bonus: all

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) $(B_OBJ)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all
	@make re -C $(LIBFT)
