/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:31:44 by vgabovs           #+#    #+#             */
/*   Updated: 2023/10/19 15:40:19 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_ction4(char *command, t_node **stack_a, t_node **stack_b)
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

void	a_ction3(char *command, t_node **stack_a, t_node **stack_b)
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
		a_ction4(command, stack_a, stack_b);
}

void	a_ction2(char *command, t_node **stack_a, t_node **stack_b)
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
		a_ction3(command, stack_a, stack_b);
}

void	action(char *command, t_node **stack_a, t_node **stack_b)
{
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
		a_ction2(command, stack_a, stack_b);
}
