/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:36:31 by vgabovs           #+#    #+#             */
/*   Updated: 2023/10/12 15:00:24 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include "libft/ft_printf.h"

typedef struct s_node
{
	int				data;
	int				value;
	struct s_node	*next;
}					t_node;

t_node		*new_node(int data);
// t_node	*add_node_back(t_node *stack, t_node *node);
void		add_node_back(t_node **stack, t_node *node);
void		add_node_front(t_node **stack, t_node *node);
t_node		*stack_init(int *list);
void		free_stack(t_node *stack);
void		print_stack(t_node *stack);

void		swap(t_node **stack);
void		rotate(t_node **stack);
void		rev_rotate(t_node **stack);
void		push(t_node **from_s, t_node **to_s);


void		sort3(t_node **stack);
int			is_sorted(t_node *stack);
void		min_max(t_node *stack, int *min, int *max);

size_t		ft_strlen_ps(const char *s);
char		*ft_strdup_ps(const char *s1, int i);
long		ft_atol(const char *str);
int			ft_strcmp(char *s1, char *s2);

void		action(char *command, t_node **stack_a, t_node **stack_b);
void		action2(char *command, t_node **stack_a, t_node **stack_b);
void		action3(char *command, t_node **stack_a, t_node **stack_b);
void		action4(char *command, t_node **stack_a, t_node **stack_b);

#endif
