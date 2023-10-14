/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 23:15:42 by vgabovs           #+#    #+#             */
/*   Updated: 2023/10/12 16:33:31 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	is_sorted(t_node *stack)
{
	t_node	*head;

	head = stack;
	while (head->next != NULL)
	{
		if (head->data > head->next->data)
		{
			// printf("| NOT sorted |\n");
			return (0);
		}
		head = head->next;
	}
	// printf("| sorted |\n");
	return (1);
}

void	min_max(t_node *stack, int *min, int *max)
{
	t_node	*head;

	head = stack;
	*min = stack->data;
	*max = stack->data;
	while (head->next != NULL)
	{
		if (head->data > *max)
			*max = head->data;
		if (head->data < *min)
			*min = head->data;
		head = head->next;
	}
	if (head->data > *max)
		*max = head->data;
	if (head->data < *min)
		*min = head->data;
}

int	stack_len(t_node *stack)
{
	t_node	*head;
	int		i;

	if (stack == NULL)
		return (0);
	i = 0;
	head = stack;
	while (head->next != NULL)
	{
		head = head->next;
		++i;
	}
	return (i );
}

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
	{

		action("rra", stack, NULL);
		// printf("Stack data: %i\n", (*stack)->data);
	}
	if ((*stack)->data > (*stack)->next->data)
		action("sa", stack, NULL);
}
