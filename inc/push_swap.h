/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:36:31 by vgabovs           #+#    #+#             */
/*   Updated: 2023/10/22 21:40:29 by vgabovs          ###   ########.fr       */
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
	int				target_pos;
	struct s_node	*next;
}					t_node;

void		push_swap(char **list);
void		solve_small(t_node **stack_a);
void		solve_big(t_node **stack_a);
char		**parser(int argc, char **argv);

void		action(char *command, t_node **stack_a, t_node **stack_b);
void		a_ction2(char *command, t_node **stack_a, t_node **stack_b);
void		a_ction3(char *command, t_node **stack_a, t_node **stack_b);
void		a_ction4(char *command, t_node **stack_a, t_node **stack_b);
void		rrr_move(t_node **stack_a, t_node **stack_b, int *cost_a, int *cost_b);
void		rr_move(t_node **stack_a, t_node **stack_b, int *cost_a, int *cost_b);
void		rotate_a(t_node **stack, int *cost);
void		rotate_b(t_node **stack, int *cost);

void		free_stack(t_node *stack);
void		free_list(char **list);

int			ft_abs(int nb);
char		*ft_strdup_ps(const char *s1, int i);
long		ft_atol(const char *str);
int			ft_strcmp(char *s1, char *s2);

int			check_duplicate(int *list, int num, int n);
int			correct_numb(char *number);
int			*check_int_list(char **list, int lsize);
int			*check_list(char **list);

int			find_ato_top(t_node *stack, int target_pos);
void		get_price(t_node **stack_a, t_node **stack_b);
void		make_move(t_node **stack_a, t_node **stack_b, int cost_a, int cost_b);
void		check_make_move(t_node **stack_a, t_node **stack_b);

void		write_data(t_node **tmp, int *i, int *j);
void		calc_position(t_node **stack);

void		rotate_to_push(t_node **stack_a, t_node **stack_b);
void		push_up_three(t_node **stack_a, t_node **stack_b,
						int ssize, int trigger);

void		swap(t_node **stack);
void		rotate(t_node **stack);
void		rev_rotate(t_node **stack);
void		push(t_node **from_s, t_node **to_s);

void		sort3(t_node **stack);
void		final_sort(t_node **stack_a, int i);
void		final_turn(t_node **stack_a);

int			is_sorted(t_node *stack);
int			max_index(t_node *stack);
int			stack_len(t_node *stack);
void		min_max(t_node *stack, int *min, int *max);
int			last_node_idx(t_node *stack);

t_node		*new_node(int data);
void		add_node_back(t_node **stack, t_node *node);
void		add_node_front(t_node **stack, t_node *node);
t_node		*stack_init(int *list);
void		assign_index(t_node **stack_a, int stack_size);

int			get_target(t_node **stack_a, int b_idx, int target_idx, int target_pos);
void		get_target_position(t_node **stack_a, t_node **stack_b);


#endif
