/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:54:33 by vgabovs           #+#    #+#             */
/*   Updated: 2023/10/22 19:55:28 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	free_list(char **list)
{
	int	i;

	if (list == NULL)
		return ;
	i = 0;
	while (list[i] != NULL)
	{
		free(list[i]);
		list[i] = NULL;
		i++;
	}
	free(list);
	list = NULL;
}
