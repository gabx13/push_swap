/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:36:31 by vgabovs           #+#    #+#             */
/*   Updated: 2023/10/17 23:40:41 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include "../inc/libft/ft_printf.h"

typedef struct s_node
{
	int				data;
	int				pos;
	int				index;
	int				to_top;
	int				price;
	struct s_node	*next;
}					t_node;

t_node		*new_node(int data);
void		add_node_back(t_node **stack, t_node *node);
void		add_node_front(t_node **stack, t_node *node);
t_node		*stack_init(int *list);
void		assign_index(t_node **stack_a, int stack_size);
int			stack_len(t_node *stack);
void		free_stack(t_node *stack);

void		print_stack(t_node *stack, FILE *o, char s);

void		swap(t_node **stack);
void		rotate(t_node **stack);
void		rev_rotate(t_node **stack);
void		push(t_node **from_s, t_node **to_s);

void		push_up_three(t_node **stack_a, t_node **stack_b, int ssize, int trigger);
void		calc_position(t_node **stack);

void		sort3(t_node **stack);
void		sort5(t_node **stack_a, t_node **stack_b);
int			is_sorted(t_node *stack);
int			last_node_idx(t_node *stack);
void		min_max(t_node *stack, int *min, int *max);

int			ft_abs(int nb);
char		*ft_strdup_ps(const char *s1, int i);
long		ft_atol(const char *str);
int			ft_strcmp(char *s1, char *s2);

void		action(char *command, t_node **stack_a, t_node **stack_b);
void		a_ction2(char *command, t_node **stack_a, t_node **stack_b);
void		a_ction3(char *command, t_node **stack_a, t_node **stack_b);
void		a_ction4(char *command, t_node **stack_a, t_node **stack_b);

void	get_price(t_node **stack_a, t_node **stack_b);
int	find_index_w_lowest_price(t_node *stack, int *move_to_top);
int	get_next_move(t_node *stack_a, t_node *stack_b, int *to_top);
void	make_move(t_node **stack_a, t_node **stack_b);

#endif
