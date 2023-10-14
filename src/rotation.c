/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 23:54:48 by vgabovs           #+#    #+#             */
/*   Updated: 2023/10/12 16:10:29 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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

	// if (from_s == NULL || (*from_s) == NULL)
	// 	return (printf("-----return from push\n"), (void)NULL) ;
	// printf("PUUUSSSSSSHHHH\n");
	head = (*from_s)->next;
	add_node_front(to_s, (*from_s));
	*from_s = head;
}

void	action4(char *command, t_node **stack_a, t_node **stack_b)
{
	if (ft_strcmp(command, "rra") == 0)
	{
		rev_rotate(stack_a);
		ft_putstr_fd("rra\n", 1);
	}
	else if (ft_strcmp(command, "rrb") == 0)
	{
		rev_rotate(stack_b);
		ft_putstr_fd("rrb\n", 1);
	}
	else if (ft_strcmp(command, "rrr") == 0)
	{
		rev_rotate(stack_a);
		rev_rotate(stack_b);
		ft_putstr_fd("rrr\n", 1);
	}
}

void	action3(char *command, t_node **stack_a, t_node **stack_b)
{
	if (ft_strcmp(command, "ra") == 0)
	{
		rotate(stack_a);
		ft_putstr_fd("ra\n", 1);
	}
	else if (ft_strcmp(command, "rb") == 0)
	{
		rotate(stack_b);
		ft_putstr_fd("rb\n", 1);
	}
	else if (ft_strcmp(command, "rr") == 0)
	{
		rotate(stack_a);
		rotate(stack_b);
		ft_putstr_fd("rr\n", 1);
	}
	else
		action4(command, stack_a, stack_b);
}

void	action2(char *command, t_node **stack_a, t_node **stack_b)
{
	if (ft_strcmp(command, "pa") == 0)
	{
		push(stack_b, stack_a);
		ft_putstr_fd("pa\n", 1);
	}
	else if (ft_strcmp(command, "pb") == 0)
	{
		push(stack_a, stack_b);
		ft_putstr_fd("pb\n", 1);
	}
	else
		action3(command, stack_a, stack_b);
}

void	action(char *command, t_node **stack_a, t_node **stack_b)
{
	// printf("COMMAND RECIVED: %s\n", command);
	if (ft_strcmp(command, "sa") == 0)
	{
		swap(stack_a);
		ft_putstr_fd("sa\n", 1);
	}
	else if (ft_strcmp(command, "sb") == 0)
	{
		swap(stack_b);
		ft_putstr_fd("sb\n", 1);
	}
	else if (ft_strcmp(command, "ss") == 0)
	{
		swap(stack_a);
		swap(stack_b);
		ft_putstr_fd("ss\n", 1);
	}
	else
		action2(command, stack_a, stack_b);
}

