/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:43:23 by vgabovs           #+#    #+#             */
/*   Updated: 2023/10/22 20:07:28 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_target(t_node **stack_a, int b_idx, int target_idx, int target_pos)
{
	t_node	*tmp_a;

	tmp_a = *stack_a;
	while (tmp_a)
	{
		if (tmp_a->index > b_idx && tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	if (target_idx != INT_MAX)
		return (target_pos);
	tmp_a = *stack_a;
	while (tmp_a)
	{
		if (tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	return (target_pos);
}

void	get_target_position(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp_b;
	t_node	*tmp_a;
	int		target_pos;

	tmp_b = *stack_b;
	tmp_a = *stack_a;
	target_pos = 0;
	while (tmp_b)
	{
		target_pos = get_target(&tmp_a, tmp_b->index, INT_MAX, target_pos);
		tmp_b->target_pos = target_pos;
		tmp_b = tmp_b->next;
	}
}
