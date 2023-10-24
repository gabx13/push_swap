/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:36:35 by vgabovs           #+#    #+#             */
/*   Updated: 2023/10/24 12:21:42 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**parser(int argc, char **argv)
{
	char	**list;
	int		i;

	if (argc == 2)
	{
		list = ft_split(argv[1], ' ');
	}
	else
	{
		list = (char **)malloc((argc + 1) * sizeof(char *));
		if (list == NULL)
			return (NULL);
		i = 0;
		while (i < argc - 1)
		{
			list[i] = ft_strdup_ps(argv[i + 1], ft_strlen(argv[i + 1]));
			i++;
		}
		list[i] = NULL;
	}
	return (list);
}

void	rotate_to_push(t_node **stack_a, t_node **stack_b)
{
	if ((*stack_b) && (*stack_b)->next && (((*stack_b)->index
				< (*stack_b)->next->index) || (*stack_b)->index
			< last_node_idx(*stack_b)))
		action("rr", stack_a, stack_b);
	else
		action("ra", stack_a, NULL);
}

void	push_up_three(t_node **stack_a, t_node **stack_b,
						int ssize, int trigger)
{
	int	i;
	int	pushed;

	i = 0;
	pushed = 0;
	trigger = (ssize - trigger) / 3 + trigger;
	while (pushed < trigger && i < ssize - trigger)
	{
		if ((*stack_a)->index <= trigger)
		{
			action("pb", stack_a, stack_b);
			pushed++;
		}
		else
		{
			rotate_to_push(stack_a, stack_b);
		}
		i++;
	}
	if (stack_len(*stack_a) > 4)
		push_up_three(stack_a, stack_b, ssize, trigger);
	while (stack_len(*stack_a) > 3)
	{
		action("pb", stack_a, stack_b);
	}
}
