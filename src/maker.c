/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maker.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:07:06 by vgabovs           #+#    #+#             */
/*   Updated: 2023/10/17 23:47:20 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_price(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp_a;
	t_node	*tmp_b;
	int		price;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	price = 0;
	while (tmp_a)
	{
		tmp_b = *stack_b;
		while (tmp_b)
		{
			// price = ft_abs(tmp_a->index - tmp_b->index); //check if needed;
			price = ft_abs(tmp_a->to_top) + ft_abs(tmp_b->to_top) + 1;
			if (tmp_a->index < tmp_b->index)
			{
				if (tmp_a->to_top < 0)
					price--;
				else
					price++;
			}
			// check for rr & rrr
			if ((tmp_a->to_top > 0 && tmp_b->to_top > 0) || (tmp_a->to_top < 0 && tmp_b->to_top < 0))
			{
				if (ft_abs(tmp_a->to_top) > ft_abs(tmp_b->to_top))
					price -= ft_abs(tmp_b->to_top);
				if (ft_abs(tmp_a->to_top) < ft_abs(tmp_b->to_top))
					price -= ft_abs(tmp_a->to_top);
			}
			if (tmp_a->price > price || tmp_a->price == 0)
				tmp_a->price = price;
			if (tmp_b->price > price || tmp_b->price == 0)
				tmp_b->price = price;
			tmp_b = tmp_b->next;
		}
		tmp_a = tmp_a->next;
	}
	printf("price updated. A1 price:%d, A2 price:%d\n", (*stack_a)->price, (*stack_b)->price);
}

int	find_index_w_lowest_price(t_node *stack, int *move_to_top)
{
	t_node	*tmp_a;
	int		return_idx_a;
	int		min_price;

	return_idx_a = -1;
	min_price = INT_MAX;
	tmp_a = stack;
	if (move_to_top == NULL)
		printf("move_to_top is NULL\n");
	while (tmp_a)
	{
		if (tmp_a->price <= min_price)
		{
			min_price = tmp_a->price;
			if (tmp_a->index > return_idx_a)
			{
				return_idx_a = tmp_a->index;
				*move_to_top = tmp_a->to_top;
			}
		}
		tmp_a = tmp_a->next;
	}
	return (return_idx_a);
}

int	get_next_move(t_node *stack_a, t_node *stack_b, int *to_top)
{
	t_node	*tmp_a;
	t_node	*tmp_b;

	tmp_a = stack_a;
	tmp_b = stack_b;
	int	idx = find_index_w_lowest_price(stack_b, to_top);
	while (tmp_a)
	{
		printf("tmp_a->index:%d, idx:%d\n", tmp_a->index, idx);
		if (tmp_a->index < idx && tmp_a->next && tmp_a->next->index > idx)// && tmp_a->next->next)
		{
			tmp_a = tmp_a->next;
			printf("<> option\n");
			return (tmp_a->to_top);
		}
		else if (tmp_a->index > idx && tmp_a->index == idx + 1)
		{
			if (tmp_a->next == NULL)
				return (printf("sometimes??\n"), 0);
			return (tmp_a->to_top);
		}
		else if (tmp_a->index < idx && tmp_a->next == NULL)
			return (printf("idex%d<idx && next-NULL\n", tmp_a->index), 0);
		tmp_a = tmp_a->next;
	}
	return (-100);
}


void	make_move(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp_a;
	t_node	*tmp_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	int to_top_b = 1;
	int to_top_a = get_next_move(*stack_a, *stack_b, &to_top_b);
	printf("to_top_a:%d, to_top_b:%d\n", to_top_a, to_top_b);
	while (to_top_a)
	{
		if (to_top_a > 0)
		{
			action("ra", stack_a, NULL);
			to_top_a--;
		}
		else if (to_top_a < 0)
		{
			action("rra", stack_a, NULL);
			to_top_a++;
		}
	}
	while (to_top_b)
	{
		if (to_top_b > 0)
		{
			action("rb", NULL, stack_b);
			to_top_b--;
		}
		else if (to_top_b < 0)
		{
			action("rrb", NULL, stack_b);
			to_top_b++;
		}
	}
	action("pa", stack_a, stack_b);
}

