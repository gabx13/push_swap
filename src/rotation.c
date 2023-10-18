/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 23:54:48 by vgabovs           #+#    #+#             */
/*   Updated: 2023/10/19 01:12:25 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// #include "../inc/push_swap.h"

static int  checkNumberElements(t_node **stack){
	printf("rev rotate segfault %p\n", *(stack));
	printf("rev rotate adress %p\n", &(stack));
	if ((*stack)->next == NULL)
		return (1);
	else
		return (0);
}

void	swap(t_node **stack)
{
	t_node	*head;
	t_node	*tmp;
	printf("SWAP\n");

		if (checkNumberElements(stack) == 1)
		return;

	if ((*stack) == NULL || (*stack)->next == NULL)
		return ;
	tmp = (*stack);
	head = (*stack)->next;
	(*stack) = head->next;
	head->next = tmp;
	tmp->next = (*stack);
	(*stack) = head;
}

void	rotate(t_node **stack)
{
	// t_node	*head;
	// t_node	*tmp;
	printf("rev rotate segfault %p\n", *(stack));
	printf("rev rotate adress %p\n", &(stack));
	printf("ROTATE\n");
	// printf("stack:%p\n", &stack);
	// printf("stack->next:%p\n", (*stack)->next);

	// if ((*stack) == NULL || (*stack)->next == NULL)
	// 	return ;
	// tmp = (*stack);
	// head = (*stack)->next;
	// while ((*stack)->next != NULL)
	// 	(*stack) = (*stack)->next;
	// tmp->next = NULL;
	// (*stack)->next = tmp;
	// (*stack) = head;
	if (checkNumberElements(stack) == 1)
		return;
	t_node *sec = (*stack)->next;
	t_node *last = (*stack);
	while (last->next != NULL)
		last = last->next;
	last->next = (*stack);
	(*stack)->next = NULL;
	(*stack) = sec;
}

void	rev_rotate(t_node **stack)
{
	t_node	*head;
	t_node	*tmp;

	printf("REV ROTATE\n");

		if (checkNumberElements(stack) == 1)
		return;

	if ((*stack) == NULL || (*stack)->next == NULL)
		return ;
	tmp = (*stack);
	head = (*stack);
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	while (head->next != tmp)
	{
		head = head->next;
	}
	head->next = NULL;
	tmp->next = (*stack);
	(*stack) = tmp;

	printf("rev rotate segfault %p\n", *(stack));
}

void	push(t_node **from_s, t_node **to_s)
{
	t_node	*head;

	printf("PUSH\n");

	if (from_s == NULL || (*from_s) == NULL)
		return (printf("-----return from push\n"), (void)0) ;
	// printf("PUUUSSSSSSHHHH\n");
	head = (*from_s)->next;
	add_node_front(to_s, (*from_s));
	*from_s = head;
}

