/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maker.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:07:06 by vgabovs           #+#    #+#             */
/*   Updated: 2023/10/19 01:10:08 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	get_price(t_node **stack_a, t_node **stack_b)
// {
// 	t_node	*tmp_a;
// 	t_node	*tmp_b;
// 	int		price;

// 	tmp_a = *stack_a;
// 	tmp_b = *stack_b;
// 	price = 0;
// 	while (tmp_a)
// 	{
// 		tmp_b = *stack_b;
// 		while (tmp_b)
// 		{
// 			// price = ft_abs(tmp_a->index - tmp_b->index); //check if needed;
// 			price = ft_abs(tmp_a->to_top) + ft_abs(tmp_b->to_top) + 1;
// 			if (tmp_a->index < tmp_b->index)
// 			{
// 				if (tmp_a->to_top < 0)
// 					price--;
// 				else
// 					price++;
// 			}
// 			// check for rr & rrr
// 			if ((tmp_a->to_top > 0 && tmp_b->to_top > 0) || (tmp_a->to_top < 0 && tmp_b->to_top < 0))
// 			{
// 				if (ft_abs(tmp_a->to_top) > ft_abs(tmp_b->to_top))
// 					price -= ft_abs(tmp_b->to_top);
// 				if (ft_abs(tmp_a->to_top) < ft_abs(tmp_b->to_top))
// 					price -= ft_abs(tmp_a->to_top);
// 			}
// 			if (tmp_a->price > price || tmp_a->price == 0)
// 				tmp_a->price = price;
// 			if (tmp_b->price > price || tmp_b->price == 0)
// 				tmp_b->price = price;
// 			tmp_b = tmp_b->next;
// 		}
// 		tmp_a = tmp_a->next;
// 	}
// 	// printf("price updated. A1 price:%d, A2 price:%d\n", (*stack_a)->price, (*stack_b)->price);
// }

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
	int		price;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	price = 0;
	while(tmp_b)
	{
		tmp_b->price = ft_abs(tmp_b->to_top) + ft_abs(find_ato_top(*stack_a, tmp_b->target_pos));
		tmp_b = tmp_b->next;
	}
}

// int	find_index_w_lowest_price(t_node *stack, int *move_to_top)
// {
// 	t_node	*tmp_a;
// 	int		return_idx_a;
// 	int		min_price;

// 	return_idx_a = -1;
// 	min_price = INT_MAX;
// 	tmp_a = stack;
// 	if (move_to_top == NULL)
// 		printf("move_to_top is NULL\n");
// 	while (tmp_a)
// 	{
// 		if (tmp_a->price <= min_price)
// 		{
// 			min_price = tmp_a->price;
// 			if (tmp_a->index > return_idx_a)
// 			{
// 				return_idx_a = tmp_a->index;
// 				*move_to_top = tmp_a->to_top;
// 			}
// 		}
// 		tmp_a = tmp_a->next;
// 	}
// 	return (return_idx_a);
// }

// int	get_next_move(t_node *stack_a, t_node *stack_b, int *to_top)
// {
// 	t_node	*tmp_a;
// 	t_node	*tmp_b;

// 	tmp_a = stack_a;
// 	tmp_b = stack_b;
// 	int	idx = find_index_w_lowest_price(stack_b, to_top);
// 	while (tmp_a)
// 	{
// 		printf("tmp_a->index:%d, idx:%d\n", tmp_a->index, idx);
// 		if (tmp_a->index < idx && tmp_a->next && tmp_a->next->index > idx)// && tmp_a->next->next)
// 		{
// 			tmp_a = tmp_a->next;
// 			printf("<> option\n");
// 			return (tmp_a->to_top);
// 		}
// 		else if (tmp_a->index > idx && tmp_a->index == idx + 1)
// 		{
// 			if (tmp_a->next == NULL)
// 				return (printf("sometimes??\n"), 0);
// 			return (tmp_a->to_top);
// 		}
// 		else if (tmp_a->index < idx && tmp_a->next == NULL)
// 			return (printf("idex%d<idx && next-NULL\n", tmp_a->index), 0);
// 		tmp_a = tmp_a->next;
// 	}
// 	return (-100);
// }


// void	make_move(t_node **stack_a, t_node **stack_b)
// {
// 	t_node	*tmp_a;
// 	t_node	*tmp_b;

// 	tmp_a = *stack_a;
// 	tmp_b = *stack_b;
// 	int to_top_b = 1;
// 	int to_top_a = get_next_move(*stack_a, *stack_b, &to_top_b);
// 	printf("to_top_a:%d, to_top_b:%d\n", to_top_a, to_top_b);
// 	while (to_top_a)
// 	{
// 		if (to_top_a > 0)
// 		{
// 			action("ra", stack_a, NULL);
// 			to_top_a--;
// 		}
// 		else if (to_top_a < 0)
// 		{
// 			action("rra", stack_a, NULL);
// 			to_top_a++;
// 		}
// 	}
// 	while (to_top_b)
// 	{
// 		if (to_top_b > 0)
// 		{
// 			action("rb", NULL, stack_b);
// 			to_top_b--;
// 		}
// 		else if (to_top_b < 0)
// 		{
// 			action("rrb", NULL, stack_b);
// 			to_top_b++;
// 		}
// 	}
// 	action("pa", stack_a, stack_b);
// }


void	rrr_move(t_node **stack_a, t_node **stack_b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		action("rrr", stack_a, stack_b);
		(*cost_a)++;
		(*cost_b)++;
	}
}

void	rr_move(t_node **stack_a, t_node **stack_b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		action("rr", stack_a, stack_b);
		(*cost_a)--;
		(*cost_b)--;
	}
}

void	rotate_a(t_node **stack, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			action("ra", stack, NULL);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			action("rra", stack, NULL);
			(*cost)++;
		}
	}
}

void	rotate_b(t_node **stack, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			action("rb", stack, NULL);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			action("rrb", stack, NULL);
			(*cost)++;
		}
	}
}


void	make_move(t_node **stack_a, t_node **stack_b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		rrr_move(stack_a, stack_b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		rr_move(stack_a, stack_b, &cost_a, &cost_b);
		printf("rev rotate segfault %p\n", *(stack_a));
	rotate_a(stack_a, &cost_a);
	printf("rev rotate segfault %p\n", *(stack_b));
	rotate_b(stack_b, &cost_b);
	printf("rev rotate segfault %p\n", *(stack_b));
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
	while(tmp_b)
	{
		if (tmp_b->price < cheapest_move)
		{
			cheapest_move = tmp_b->price;
			cost_b = tmp_b->to_top;
			cost_a = find_ato_top(*stack_a, tmp_b->target_pos);
		}
		tmp_b = tmp_b->next;
	}

	make_move(stack_a, stack_b, cost_a, cost_b);
}


int	get_target(t_node **stack_a, int b_idx, int target_idx, int target_pos)
{
	t_node	*tmp_a;

	tmp_a = *stack_a;
	while (tmp_a)
	{
		if (tmp_a->index > b_idx && tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	if (target_idx != INT_MAX)
		return (target_pos);
	tmp_a = *stack_a;
	while (tmp_a)
	{
		if (tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	return (target_pos);
}

void	get_target_position(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp_b;
	int		target_pos;

	tmp_b = *stack_b;

	target_pos = 0;
	while (tmp_b)
	{
		target_pos = get_target(stack_a, tmp_b->index, INT_MAX, target_pos);
		tmp_b->target_pos = target_pos;
		tmp_b = tmp_b->next;
	}
}
