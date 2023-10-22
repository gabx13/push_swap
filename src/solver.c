/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 23:15:42 by vgabovs           #+#    #+#             */
/*   Updated: 2023/10/22 20:29:16 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort3(t_node **stack)
{
	t_node	*head;
	int		min;
	int		max;

	head = *stack;
	min = 0;
	max = 0;
	min_max(head, &min, &max);
	if (is_sorted(*stack))
		return ;
	if ((*stack)->data == max)
		action("ra", stack, NULL);
	else if ((*stack)->data == min || (*stack)->data < (*stack)->next->data)
		action("rra", stack, NULL);
	if ((*stack)->data > (*stack)->next->data)
		action("sa", stack, NULL);
}

void	final_sort(t_node **stack_a, int i)
{
	int		len;

	len = stack_len(*stack_a);
	if (i < len / 2)
	{
		while (!is_sorted(*stack_a))
			action("ra", stack_a, NULL);
	}
	else
	{
		while (!is_sorted(*stack_a))
			action("rra", stack_a, NULL);
	}
}

void	final_turn(t_node **stack_a)
{
	int		i;
	t_node	*tmp;

	tmp = *stack_a;
	i = 0;
	while (tmp)
	{
		if (tmp->index == 0)
			final_sort(stack_a, i);
		i++;
		tmp = tmp->next;
	}
}
