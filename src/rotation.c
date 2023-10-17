/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 23:54:48 by vgabovs           #+#    #+#             */
/*   Updated: 2023/10/16 11:57:04 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// #include "../inc/push_swap.h"

void	swap(t_node **stack)
{
	t_node	*head;
	t_node	*tmp;

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
	t_node	*head;
	t_node	*tmp;

	if ((*stack) == NULL || (*stack)->next == NULL)
		return ;
	tmp = (*stack);
	head = (*stack)->next;
	while ((*stack)->next != NULL)
		(*stack) = (*stack)->next;
	tmp->next = NULL;
	(*stack)->next = tmp;
	(*stack) = head;
}

void	rev_rotate(t_node **stack)
{
	t_node	*head;
	t_node	*tmp;

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
}

void	push(t_node **from_s, t_node **to_s)
{
	t_node	*head;

	if (from_s == NULL || (*from_s) == NULL)
		return (printf("-----return from push\n"), (void)0) ;
	// printf("PUUUSSSSSSHHHH\n");
	head = (*from_s)->next;
	add_node_front(to_s, (*from_s));
	*from_s = head;
}

