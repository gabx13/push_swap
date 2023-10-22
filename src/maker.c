/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maker.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:07:06 by vgabovs           #+#    #+#             */
/*   Updated: 2023/10/22 21:22:43 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_ato_top(t_node *stack, int target_pos)
{
	t_node	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->pos == target_pos)
			return (tmp->to_top);
		tmp = tmp->next;
	}
	return (100);
}

void	get_price(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp_a;
	t_node	*tmp_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	while (tmp_b)
	{
		tmp_b->price = ft_abs(tmp_b->to_top)
			+ ft_abs(find_ato_top(tmp_a, tmp_b->target_pos));
		tmp_b = tmp_b->next;
	}
}

void	make_move(t_node **stack_a, t_node **stack_b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		rrr_move(stack_a, stack_b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		rr_move(stack_a, stack_b, &cost_a, &cost_b);
	rotate_a(stack_a, &cost_a);
	rotate_b(stack_b, &cost_b);
	action("pa", stack_a, stack_b);
}

void	check_make_move(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp_a;
	t_node	*tmp_b;
	int		cheapest_move;
	int		cost_a;
	int		cost_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	cheapest_move = INT_MAX;
	while (tmp_b)
	{
		if (tmp_b->price < cheapest_move)
		{
			cheapest_move = tmp_b->price;
			cost_b = tmp_b->to_top;
			cost_a = find_ato_top(tmp_a, tmp_b->target_pos);
		}
		tmp_b = tmp_b->next;
	}
	make_move(stack_a, stack_b, cost_a, cost_b);
}
