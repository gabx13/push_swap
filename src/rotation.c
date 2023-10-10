/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 23:54:48 by vgabovs           #+#    #+#             */
/*   Updated: 2023/10/11 01:23:19 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap(t_node **stack)
{
	t_node	*head;
	t_node	*tmp;

	if ((*stack)->next == NULL)
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

	if ((*stack)->next == NULL)
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

	if ((*stack)->next == NULL)
		return ;
	tmp = (*stack);
	head = (*stack);
	while (tmp->next != NULL)
		tmp = tmp->next;
	while (head->next != tmp)
		head = head->next;
	head->next = NULL;
	tmp->next = (*stack);
	(*stack) = tmp;
}
