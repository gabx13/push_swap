/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:56:27 by vgabovs           #+#    #+#             */
/*   Updated: 2023/10/17 23:42:37 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// #include "../inc/push_swap.h"

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

t_node	*new_node(int data)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->data = data;
	node->to_top = 0;
	node->index = 0;
	node->price = 0;
	// node->price_b = 0;
	node->pos = 0;
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

void	print_stack(t_node *stack, FILE *o, char s)
{
	t_node	*tmp;

	// if (!stack)
	// 	return ;
	tmp = stack;
	if (tmp)
	{
		while (tmp->next != NULL )
		{
			fprintf(o, "	stack %c:%i,	index:%d,	to top:%d,	price:%d, pos:%d\n",s, tmp->data, tmp->index, tmp->to_top, tmp->price, tmp->pos);
			tmp = tmp->next;
		}
		fprintf(o, "	stack %c:%i,	index:%d,	to top:%d,	price:%d, pos:%d\n",s, tmp->data, tmp->index, tmp->to_top, tmp->price, tmp->pos);
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

void	assign_index(t_node **stack_a, int stack_size)
{
	t_node	*ptr;
	t_node	*highest;
	int		data;

	while (--stack_size > 0)
	{
		ptr = *stack_a;
		data = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->data == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->data > data && ptr->index == 0)
			{
				data = ptr->data;
				highest = ptr;
				// ptr = stack_a;
			}
			// else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
	}
}
