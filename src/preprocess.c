/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:36:35 by vgabovs           #+#    #+#             */
/*   Updated: 2023/10/18 12:53:39 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// #include "../inc/push_swap.h"

void	push_up_three(t_node **stack_a, t_node **stack_b, int ssize, int trigger)
{
	int	i;
	int	pushed;

	i = 0;
	pushed = 0;
	trigger = (ssize - trigger) / 4 + trigger;

	while (pushed <= trigger && i < ssize - trigger)
	{
		if ((*stack_a)->index <= trigger)
		{
			action("pb", stack_a, stack_b);
			pushed++;
		}
		else
		{
			if ((*stack_b) && (*stack_b)->next && (((*stack_b)->index
						< (*stack_b)->next->index) || (*stack_b)->index
					< last_node_idx(*stack_b)))
				action("rr", stack_a, stack_b);
			else
				action("ra", stack_a, NULL);
		}
		i++;
	}
		if (stack_len(*stack_a) > 4)
		{
			// printf("recursion\n");
			push_up_three(stack_a, stack_b, ssize, trigger);
		}

		while (stack_len(*stack_a) > 3)
		{
			action("pb", stack_a, stack_b);
		}
}
