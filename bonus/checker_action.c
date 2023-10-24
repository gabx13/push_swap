/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_action.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:37:25 by vgabovs           #+#    #+#             */
/*   Updated: 2023/10/24 21:39:18 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ca_ction4(char *command, t_node **stack_a, t_node **stack_b)
{
	if (ft_strcmp(command, "rra") == 0)
	{
		rev_rotate(stack_a);
	}
	else if (ft_strcmp(command, "rrb") == 0)
	{
		rev_rotate(stack_b);
	}
	else if (ft_strcmp(command, "rrr") == 0)
	{
		rev_rotate(stack_a);
		rev_rotate(stack_b);
	}
}

void	ca_ction3(char *command, t_node **stack_a, t_node **stack_b)
{
	if (ft_strcmp(command, "ra") == 0)
	{
		rotate(stack_a);
	}
	else if (ft_strcmp(command, "rb") == 0)
	{
		rotate(stack_b);
	}
	else if (ft_strcmp(command, "rr") == 0)
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	else
		ca_ction4(command, stack_a, stack_b);
}

void	ca_ction2(char *command, t_node **stack_a, t_node **stack_b)
{
	if (ft_strcmp(command, "pa") == 0)
	{
		push(stack_b, stack_a);
	}
	else if (ft_strcmp(command, "pb") == 0)
	{
		push(stack_a, stack_b);
	}
	else
		ca_ction3(command, stack_a, stack_b);
}

void	c_action(char *command, t_node **stack_a, t_node **stack_b)
{
	if (ft_strcmp(command, "sa") == 0)
	{
		swap(stack_a);
	}
	else if (ft_strcmp(command, "sb") == 0)
	{
		swap(stack_b);
	}
	else if (ft_strcmp(command, "ss") == 0)
	{
		swap(stack_a);
		swap(stack_b);
	}
	else
		ca_ction2(command, stack_a, stack_b);
}
