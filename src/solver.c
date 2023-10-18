/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 23:15:42 by vgabovs           #+#    #+#             */
/*   Updated: 2023/10/18 12:54:33 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// #include "../inc/push_swap.h"

void	sort3(t_node **stack)
{
	t_node	*head;
	int		min;
	int		max;

	head = *stack;
	min = 0;
	max = 0;
	min_max(head, &min, &max);
	// printf("MIN-MAX: %i-%i, stack len:%i\n", min, max, stack_len(*stack));
	if (is_sorted(*stack))
		return ;
	if ((*stack)->data == max)
		action("ra", stack, NULL);
	else if ((*stack)->data == min || (*stack)->data < (*stack)->next->data)
		action("rra", stack, NULL);
	if ((*stack)->data > (*stack)->next->data)
		action("sa", stack, NULL);
}

void	sort5(t_node **stack_a, t_node **stack_b)
{
	if (is_sorted(*stack_a))
		exit (EXIT_SUCCESS);
	while (stack_len(*stack_a) > 3)
	{
		// printf("action\n");
		action("pb",stack_a, stack_b);
	}
	sort3(stack_a);
	printf("stack b\n");
	sort3(stack_b);
	// print_stack(*stack_a);
	printf("stack b\n");
	// print_stack(*stack_b);
}

