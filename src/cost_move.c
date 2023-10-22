/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:39:44 by vgabovs           #+#    #+#             */
/*   Updated: 2023/10/22 19:39:58 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			action("rb", NULL, stack);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			action("rrb", NULL, stack);
			(*cost)++;
		}
	}
}
