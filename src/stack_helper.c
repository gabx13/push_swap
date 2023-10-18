/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:52:54 by vgabovs           #+#    #+#             */
/*   Updated: 2023/10/18 12:59:07 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	max_index(t_node *stack)
{
	t_node	*tmp;
	int	max_index;

	tmp = stack;
	max_index = INT_MIN;
	while(tmp)
	{
		if (tmp->index > max_index)
			max_index = tmp->index;
		tmp = tmp->next;
	}
	return (max_index);
}

int	stack_len(t_node *stack)
{
	t_node	*head;
	int		i;

	if (stack == NULL)
		return (0);
	i = 0;
	head = stack;
	while (head!= NULL)
	{
		head = head->next;
		++i;
	}
	return (i);
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

int	last_node_idx(t_node *stack)
{
	t_node	*tmp;

	tmp = stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp->index);
}

void	free_stack(t_node *stack)
{
	t_node	*tmp;

	while (stack->next != NULL)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
	free(stack);
	stack = NULL;
}
