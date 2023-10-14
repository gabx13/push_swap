/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:56:27 by vgabovs           #+#    #+#             */
/*   Updated: 2023/10/12 15:05:22 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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

t_node	*new_node(int data)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->data = data;
	node->value = 0;
	node->next = NULL;
	return (node);
}

// t_node	*add_node_back(t_node *stack, t_node *node)
// {
// 	t_node	*head;

// 	head = stack;
// 	while (stack->next != NULL)
// 		stack = stack->next;
// 	stack->next = node;
// 	stack = head;
// 	return (stack);
// }

void	add_node_back(t_node **stack, t_node *node)
{
	t_node	*head;

	head = *stack;
	while ((*stack)->next != NULL)
		(*stack) = (*stack)->next;
	(*stack)->next = node;
	*stack = head;
}

void	add_node_front(t_node **stack, t_node *node)
{
	node->next = (*stack);
	(*stack) = node;
}

void	print_stack(t_node *stack)
{
	t_node	*tmp;

	tmp = stack;
	if (tmp)
	{
		while (tmp->next != NULL )
		{
			ft_printf("stack A:%i\n", tmp->data);
			tmp = tmp->next;
		}
		ft_printf("stack A:%i\n", tmp->data);
	}
}

t_node	*stack_init(int *list)
{
	int		list_len;
	int		i;
	t_node	*stack;

	if (!list)
		return (0);
	list_len = list[0];
	i = 1;
	// printf("list len in stack:%i, int to be submited:%i\n", list_len, list[i]);
	stack = new_node(list[i]);
	while (--list_len)
	{
		// stack = add_node_back(stack, new_node(list[++i]));
		add_node_back(&stack, new_node(list[++i]));
	}
	free(list);
/////////////////////////
	// t_node	*stack_b;

	// stack_b = NULL;
	// sort3(&stack);

	// print_stack(stack);
	// // tmp = stack;	//test
	// // if (tmp)
	// // {
	// // 	while (tmp->next != NULL )
	// // 	{
	// // 		printf("stack A:%i\n", tmp->data);
	// // 		tmp = tmp->next;
	// // 	}
	// // 	printf("stack A:%i\n", tmp->data);
	// // 	free_stack(tmp);
	// // }
	// print_stack(stack_b);
	// // tmp = stack_b;
	// // if (tmp)
	// // {
	// // 	while (stack_b->next != NULL)
	// // 		{
	// // 			printf("stack B:%i\n", stack_b->data);
	// // 			stack_b = stack_b->next;
	// // 		}
	// 		printf("stack B:%i\n", stack_b->data);
	// 		free_stack(tmp);
	// }
	return (stack);
}
